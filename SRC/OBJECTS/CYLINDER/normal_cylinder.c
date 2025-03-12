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

/**
 * Calculates the normal vector at a point on a cylinder.
 * For cylinders, the normal points outward from the cylinder axis.
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
	
	// Create the point on the axis at the projected distance
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