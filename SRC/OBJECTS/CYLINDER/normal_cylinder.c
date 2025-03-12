/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:00:00 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/03/12 15:00:00 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"
#include "objects_cylinder.h"
#include <math.h>

/**
 * Determines if a point is on one of the end caps of the cylinder.
 * 
 * @param curr The cylinder object
 * @param point The point to check
 * @param axis Normalized cylinder axis
 * @param projection Projection of point onto axis
 * @return 1 if on top cap, -1 if on bottom cap, 0 if on side
 */
static int	is_on_cap(t_object *curr, t_matrix *point, t_matrix *axis, 
					double projection)
{
	double	half_height;
	double	distance_from_center;
	t_matrix	*projected_point;
	t_matrix	*to_center;
	double	radius;
	int		result;

	half_height = curr->obj.cylinder.height / 2;
	radius = curr->obj.cylinder.diameter / 2;
	
	// Check if point is near top or bottom cap (within epsilon)
	if (fabs(projection - half_height) < 0.0001)
		result = 1;  // Top cap
	else if (fabs(projection + half_height) < 0.0001)
		result = -1;  // Bottom cap
	else
		return (0);  // Side of cylinder
	
	// Calculate the projected point on the axis
	projected_point = matrix_clone(axis);
	if (!projected_point)
		return (0);
	
	matrix_scalar_mult(projected_point, projection);
	matrix_sum(projected_point, curr->obj.cylinder.origin);
	
	// Check if point is within radius from the cap center
	to_center = matrix_subs(point, projected_point);
	free_matrix(projected_point);
	
	if (!to_center)
		return (0);
	
	distance_from_center = matrix_length(to_center);
	free_matrix(to_center);
	
	if (distance_from_center <= radius)
		return (result);
	return (0);
}

/**
 * Calculates the normal vector at a point on a cylinder.
 * For cylinders, the normal points outward from the cylinder axis for the
 * side, and along the axis for the caps.
 * 
 * Error handling: Returns NULL on invalid parameters or allocation failures.
 * 
 * @param curr The cylinder object
 * @param point The point on the cylinder surface to calculate the normal for
 * @return A new matrix representing the normalized normal vector, or NULL on error
 */
t_matrix	*cylinder_normal(t_object *curr, t_matrix *point)
{
	t_matrix	*normal;
	t_matrix	*axis;
	t_matrix	*to_point;
	double		projection;
	t_matrix	*projected_point;
	int			cap_result;

	// Add null checks for parameters
	if (!curr || curr->type != CYLINDER || !point || !curr->obj.cylinder.origin)
		return (NULL);
	
	// Get cylinder axis (normalized)
	axis = matrix_clone(curr->obj.cylinder.v_orient);
	if (!axis)
		return (NULL);
	matrix_normalize(axis);
	
	// Calculate vector from cylinder origin to point
	to_point = matrix_subs(point, curr->obj.cylinder.origin);
	if (!to_point)
	{
		free_matrix(axis);
		return (NULL);
	}
	
	// Calculate projection of point onto cylinder axis
	projection = matrix_dot(to_point, axis);
	
	// Check if point is on end caps
	cap_result = is_on_cap(curr, point, axis, projection);
	if (cap_result != 0)
	{
		// Point is on cap, normal is same as axis (or opposite)
		normal = matrix_clone(axis);
		free_matrix(axis);
		free_matrix(to_point);
		
		if (!normal)
			return (NULL);
		
		if (cap_result < 0)
			matrix_scalar_mult(normal, -1);  // Bottom cap
		
		return (normal);
	}
	
	// Point is on cylinder side, calculate normal from axis
	projected_point = matrix_clone(axis);
	if (!projected_point)
	{
		free_matrix(axis);
		free_matrix(to_point);
		return (NULL);
	}
	matrix_scalar_mult(projected_point, projection);
	
	// Add origin to get world space point
	matrix_sum(projected_point, curr->obj.cylinder.origin);
	
	// Calculate normal as vector from axis point to surface point
	normal = matrix_subs(point, projected_point);
	free_matrix(projected_point);
	free_matrix(axis);
	free_matrix(to_point);
	
	if (!normal)
		return (NULL);
	
	// Ensure it's a proper vector (w = 0)
	normal->data[3][0] = 0;
	
	// Normalize the vector
	matrix_normalize(normal);
	
	return (normal);
}