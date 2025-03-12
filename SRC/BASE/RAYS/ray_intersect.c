/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:35:53 by mcoskune          #+#    #+#             */
/*   Updated: 2025/03/11 15:00:00 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"
#include "base_helpers.h"
#include "base_rays.h"
#include "muk_lib.h"
#include <math.h>

/**
 * Creates and populates two intersection records with the given t-values.
 * Adds them to the provided intersection array.
 * 
 * Error handling: Cleans up resources on allocation failure. If the first
 * allocation fails, returns immediately. If the second fails, frees the first
 * and sets the array to NULL.
 * 
 * @param a_ix Pointer to the intersection array to populate
 * @param t1 The t-value for the first intersection
 * @param t2 The t-value for the second intersection
 */
static void	create_sphere_intersections(t_isect ***a_ix, double t1, double t2)
{
	t_isect	*inter1;
	t_isect	*inter2;

	if (!a_ix)
		return;
		
	inter1 = safe_malloc(sizeof(t_isect), 1);
	if (!inter1)
		return;
		
	inter1->t_val = t1;
	add_to_dptr((void ***)a_ix, (void *)inter1);
	
	inter2 = safe_malloc(sizeof(t_isect), 1);
	if (!inter2)
	{
		free((*a_ix)[0]);
		*a_ix = NULL;
		return;
	}
	
	inter2->t_val = t2;
	add_to_dptr((void ***)a_ix, (void *)inter2);
}

/**
 * Calculates the intersection points between a ray and a sphere.
 * Transforms the ray to object space, calculates intersection points,
 * and creates intersection records.
 * 
 * Error handling: Returns NULL on allocation failures or when no intersection exists.
 * Resource management: Properly frees intermediate matrices and rays.
 * 
 * @param obj The sphere object to test for intersection
 * @param ray The ray to test for intersection
 * @return Array of intersection records or NULL if no intersection or on error
 */
t_isect	**ray_intersect_sphere(t_object *obj, t_ray *ray)
{
	t_isect		**all_inter;
	t_matrix	*sptoray;
	double		delta;
	t_ray		*nray;
	double		t1, t2, var;

	if (!obj || !ray || obj->type != SPHERE || !obj->obj.sphere.transform)
		return (NULL);
		
	all_inter = NULL;
	sptoray = matrix_inverse(obj->obj.sphere.transform);
	if (!sptoray)
		return (NULL);
		
	nray = ray_transform(ray, sptoray);
	free_matrix(sptoray);
	if (!nray)
		return (NULL);
		
	sptoray = matrix_subs(nray->origin, obj->obj.sphere.origin);
	if (!sptoray)
	{
		free_ray(nray);
		return (NULL);
	}
	
	delta = discriminant(nray, sptoray);
	if (delta < 0)
	{
		free_ray(nray);
		free_matrix(sptoray);
		return (NULL);
	}
	
	var = -1 * 2 * matrix_dot(nray->direction, sptoray);
	t1 = (var - sqrt(delta)) / (2 * matrix_dot(nray->direction, nray->direction));
	t2 = (var + sqrt(delta)) / (2 * matrix_dot(nray->direction, nray->direction));
	
	create_sphere_intersections(&all_inter, t1, t2);
	free_matrix(sptoray);
	free_ray(nray);
	return (all_inter);
}

/**
 * Calculates the intersection points between a ray and a plane.
 * Uses the plane normal and position to determine if and where the ray intersects.
 * 
 * Error handling: Returns NULL on allocation failures or when no intersection exists.
 * Resource management: Properly frees intermediate matrices.
 * 
 * @param obj The plane object to test for intersection
 * @param ray The ray to test for intersection
 * @return Array of intersection records or NULL if no intersection or on error
 */
t_isect	**ray_intersect_plane(t_object *obj, t_ray *ray)
{
	t_isect		**all_inter;
	double		denom;
	double		t;
	t_matrix	*normal;
	t_matrix	*origin_diff;

	if (!obj || !ray || obj->type != PLANE || !obj->obj.plane.v_orient)
		return (NULL);
		
	all_inter = NULL;
	normal = obj->obj.plane.v_orient;
	
	// Check if ray is parallel to plane
	denom = matrix_dot(normal, ray->direction);
	if (fabs(denom) < 0.0001)
		return (NULL);  // Ray is parallel to plane
	
	// Calculate distance to intersection
	origin_diff = matrix_subs(obj->obj.plane.origin, ray->origin);
	if (!origin_diff)
		return (NULL);
	
	t = matrix_dot(origin_diff, normal) / denom;
	free_matrix(origin_diff);
	
	// Only add intersection if it's in front of the ray origin
	if (t <= 0.0001)
		return (NULL);
	
	// Create intersection - just one intersection for plane is enough
	all_inter = safe_malloc(sizeof(t_isect *), 2);  // 1 intersection + NULL terminator
	if (!all_inter)
		return (NULL);
		
	all_inter[0] = safe_malloc(sizeof(t_isect), 1);
	if (!all_inter[0])
	{
		free(all_inter);
		return (NULL);
	}
	all_inter[0]->t_val = t;
	all_inter[0]->count = 1;  // Only one intersection for a plane
	
	all_inter[1] = NULL;  // NULL terminator
	return (all_inter);
}

/**
 * Creates and populates intersection records for cylinder.
 * 
 * Error handling: Cleans up resources on allocation failure.
 * 
 * @param a_ix Pointer to the intersection array to populate
 * @param t_vals Array containing t values
 * @param count Number of intersections to create
 */
static void	create_cylinder_intersections(t_isect ***a_ix, double *t_vals, int count)
{
	t_isect	*inter;
	int		i;

	if (!a_ix || !t_vals || count < 1 || count > 4)
		return;
	
	// Sort the intersections by t_val (ascending)
	// Simple bubble sort for small array
	for (int j = 0; j < count - 1; j++)
	{
		for (int k = 0; k < count - j - 1; k++)
		{
			if (t_vals[k] > t_vals[k + 1])
			{
				double temp = t_vals[k];
				t_vals[k] = t_vals[k + 1];
				t_vals[k + 1] = temp;
			}
		}
	}
	
	i = 0;
	while (i < count)
	{
		inter = safe_malloc(sizeof(t_isect), 1);
		if (!inter)
		{
			// Clean up all previous allocations
			if (*a_ix)
			{
				int j = 0;
				while (j < i && (*a_ix)[j])
				{
					free((*a_ix)[j]);
					j++;
				}
				*a_ix = NULL;
			}
			return;
		}
		inter->t_val = t_vals[i];
		inter->count = count;  // Store number of intersections
		add_to_dptr((void ***)a_ix, (void *)inter);
		i++;
	}
	
	// Add NULL terminator
	add_to_dptr((void ***)a_ix, NULL);
}

/**
 * Checks if a point is within the height limits of a cylinder.
 * 
 * @param obj The cylinder object
 * @param ray The ray being tested
 * @param t The t value of the intersection
 * @param axis The normalized cylinder axis
 * @param projection_ptr Pointer to store the projection value (can be NULL)
 * @return 1 if within height limits, 0 if outside
 */
static int	is_within_cylinder_height(t_object *obj, t_ray *ray, double t, 
									t_matrix *axis, double *projection_ptr)
{
	t_matrix	*intersection_point;
	t_matrix	*cylinder_to_point;
	double		projection;
	double		half_height;

	// Calculate intersection point
	intersection_point = ray_position(ray, t);
	if (!intersection_point)
		return (0);
	
	// Vector from cylinder origin to intersection point
	cylinder_to_point = matrix_subs(intersection_point, obj->obj.cylinder.origin);
	free_matrix(intersection_point);
	
	if (!cylinder_to_point)
		return (0);
	
	// Project this vector onto the cylinder axis
	projection = matrix_dot(cylinder_to_point, axis);
	free_matrix(cylinder_to_point);
	
	// Store projection value for caller if requested
	if (projection_ptr != NULL)
		*projection_ptr = projection;
	
	// Check if projection is within cylinder height
	half_height = obj->obj.cylinder.height / 2;
	return (projection >= -half_height && projection <= half_height);
}

/**
 * Calculates the intersection of a ray with a cylinder cap.
 * 
 * @param obj The cylinder object
 * @param ray The ray being tested
 * @param axis The normalized cylinder axis
 * @param is_top 1 for top cap, 0 for bottom cap
 * @return The t value of the intersection or -1 if no intersection
 */
static double	intersect_cap(t_object *obj, t_ray *ray, t_matrix *axis, 
							int is_top)
{
	double		t;
	t_matrix	*cap_center;
	t_matrix	*cap_to_ray;
	double		radius;
	double		denom;
	t_matrix	*intersection_point;
	t_matrix	*to_center;
	double		distance_squared;

	// Calculate cap center position
	cap_center = matrix_clone(axis);
	if (!cap_center)
		return (-1);
	
	// Position the cap at either top or bottom
	matrix_scalar_mult(cap_center, is_top ? 
						obj->obj.cylinder.height / 2 : 
						-obj->obj.cylinder.height / 2);
	matrix_sum(cap_center, obj->obj.cylinder.origin);
	
	// Calculate vector from cap center to ray origin
	cap_to_ray = matrix_subs(cap_center, ray->origin);
	if (!cap_to_ray)
	{
		free_matrix(cap_center);
		return (-1);
	}
	
	// Check if ray is parallel to cap plane
	denom = matrix_dot(axis, ray->direction);
	if (fabs(denom) < 0.0001)
	{
		free_matrix(cap_center);
		free_matrix(cap_to_ray);
		return (-1);
	}
	
	// Calculate t at which ray intersects cap plane
	t = matrix_dot(cap_to_ray, axis) / denom;
	free_matrix(cap_to_ray);
	
	// Check if intersection is behind ray origin
	if (t <= 0.0001)
	{
		free_matrix(cap_center);
		return (-1);
	}
	
	// Calculate intersection point
	intersection_point = ray_position(ray, t);
	if (!intersection_point)
	{
		free_matrix(cap_center);
		return (-1);
	}
	
	// Calculate distance from intersection to cap center
	to_center = matrix_subs(intersection_point, cap_center);
	free_matrix(cap_center);
	free_matrix(intersection_point);
	if (!to_center)
		return (-1);
	
	// Check if intersection point is within the cap radius
	distance_squared = matrix_dot(to_center, to_center);
	free_matrix(to_center);
	radius = obj->obj.cylinder.diameter / 2;
	
	if (distance_squared <= radius * radius)
		return (t);
	
	return (-1);
}

/**
 * Calculates the intersection points between a ray and a cylinder.
 * Handles both the cylinder body and end caps.
 * 
 * Error handling: Returns NULL on allocation failures or when no intersection exists.
 * Resource management: Properly frees intermediate matrices.
 * 
 * @param obj The cylinder object to test for intersection
 * @param ray The ray to test for intersection
 * @return Array of intersection records or NULL if no intersection or on error
 */
t_isect	**ray_intersect_cylinder(t_object *obj, t_ray *ray)
{
	t_isect		**all_inter;
	t_matrix	*axis, *oc, *rd_reject, *oc_reject;
	double		a, b, c, delta, t_vals[4]; // Max 4 intersections (2 body + 2 caps)
	double		t1, t2, t_cap;
	int			count;

	printf("DEBUG: ray_intersect_cylinder called\n");

	if (!obj || !ray || obj->type != CYLINDER || !obj->obj.cylinder.v_orient)
	{
		printf("DEBUG: ray_intersect_cylinder early return: %p %p %d %p\n", 
			obj, ray, (obj ? obj->type : -1), (obj ? obj->obj.cylinder.v_orient : NULL));
		return (NULL);
	}
	
	all_inter = NULL;
	count = 0;
	
	// Get cylinder orientation (normalized)
	axis = matrix_clone(obj->obj.cylinder.v_orient);
	if (!axis)
		return (NULL);
	matrix_normalize(axis);
	
	// Calculate vector from cylinder origin to ray origin (oc)
	oc = matrix_subs(ray->origin, obj->obj.cylinder.origin);
	if (!oc)
	{
		free_matrix(axis);
		return (NULL);
	}
	
	// Calculate projections
	double dot_dir_axis = matrix_dot(ray->direction, axis);
	double dot_oc_axis = matrix_dot(oc, axis);
	
	// Calculate perpendicular components for ray direction and oc vector
	// Ray direction perpendicular to cylinder axis
	rd_reject = matrix_clone(ray->direction);
	if (!rd_reject)
	{
		free_matrix(axis);
		free_matrix(oc);
		return (NULL);
	}
	t_matrix *axis_temp = matrix_clone(axis);
	if (!axis_temp)
	{
		free_matrix(axis);
		free_matrix(oc);
		free_matrix(rd_reject);
		return (NULL);
	}
	matrix_scalar_mult(axis_temp, dot_dir_axis);
	matrix_scalar_mult(axis_temp, -1);
	matrix_sum(rd_reject, axis_temp);
	free_matrix(axis_temp);
	
	// OC vector perpendicular to cylinder axis
	oc_reject = matrix_clone(oc);
	if (!oc_reject)
	{
		free_matrix(axis);
		free_matrix(oc);
		free_matrix(rd_reject);
		return (NULL);
	}
	axis_temp = matrix_clone(axis);
	if (!axis_temp)
	{
		free_matrix(axis);
		free_matrix(oc);
		free_matrix(rd_reject);
		free_matrix(oc_reject);
		return (NULL);
	}
	matrix_scalar_mult(axis_temp, dot_oc_axis);
	matrix_scalar_mult(axis_temp, -1);
	matrix_sum(oc_reject, axis_temp);
	free_matrix(axis_temp);
	
	// Compute quadratic coefficients
	a = matrix_dot(rd_reject, rd_reject);
	b = 2 * matrix_dot(rd_reject, oc_reject);
	c = matrix_dot(oc_reject, oc_reject) - pow(obj->obj.cylinder.diameter / 2, 2);
	
	// Calculate discriminant
	delta = b * b - 4 * a * c;
	printf("DEBUG: Cylinder quadratic: a=%f, b=%f, c=%f, delta=%f\n", a, b, c, delta);
	
	// Free temporary matrices that aren't needed anymore
	free_matrix(rd_reject);
	free_matrix(oc_reject);
	
	// Check for body intersections if discriminant is positive
	if (delta >= 0 && fabs(a) > 0.00001)
	{
		// Calculate intersection points
		t1 = (-b - sqrt(delta)) / (2 * a);
		t2 = (-b + sqrt(delta)) / (2 * a);
		printf("DEBUG: Cylinder body t values: t1=%f, t2=%f\n", t1, t2);
		
		// Only include intersections with positive t values and within cylinder height
		if (t1 > 0.00001 && is_within_cylinder_height(obj, ray, t1, axis, NULL))
		{
			printf("DEBUG: Adding t1=%f to intersections\n", t1);
			t_vals[count++] = t1;
		}
		if (t2 > 0.00001 && is_within_cylinder_height(obj, ray, t2, axis, NULL))
		{
			printf("DEBUG: Adding t2=%f to intersections\n", t2);
			t_vals[count++] = t2;
		}
	}
	
	// Check cap intersections
	// Top cap
	t_cap = intersect_cap(obj, ray, axis, 1);
	if (t_cap > 0.00001)
	{
		printf("DEBUG: Adding top cap t=%f to intersections\n", t_cap);
		t_vals[count++] = t_cap;
	}
	
	// Bottom cap
	t_cap = intersect_cap(obj, ray, axis, 0);
	if (t_cap > 0.00001)
	{
		printf("DEBUG: Adding bottom cap t=%f to intersections\n", t_cap);
		t_vals[count++] = t_cap;
	}
	
	// Clean up resources
	free_matrix(oc);
	free_matrix(axis);
	
	// Create intersection records if we found any
	if (count > 0)
	{
		printf("DEBUG: Found %d cylinder intersections\n", count);
		create_cylinder_intersections(&all_inter, t_vals, count);
	}
	else
	{
		printf("DEBUG: No cylinder intersections found\n");
	}
	
	return (all_inter);
}