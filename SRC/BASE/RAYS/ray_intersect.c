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
	
	// Create intersection
	all_inter = safe_malloc(sizeof(t_isect *), 3);  // 2 intersections + NULL terminator
	if (!all_inter)
		return (NULL);
		
	all_inter[0] = safe_malloc(sizeof(t_isect), 1);
	if (!all_inter[0])
	{
		free(all_inter);
		return (NULL);
	}
	all_inter[0]->t_val = t;
	all_inter[0]->count = 2;  // Set count for compatibility
	
	all_inter[1] = safe_malloc(sizeof(t_isect), 1);
	if (!all_inter[1])
	{
		free(all_inter[0]);
		free(all_inter);
		return (NULL);
	}
	all_inter[1]->t_val = t;  // Same t value for second intersection (needed for compatibility)
	
	all_inter[2] = NULL;  // NULL terminator
	return (all_inter);
}

/**
 * Calculates the intersection points between a ray and a cylinder.
 * 
 * Note: This is a placeholder for future implementation.
 * 
 * Error handling: Always returns NULL (not yet implemented).
 * Resource management: No resources are allocated.
 * 
 * @param obj The cylinder object to test for intersection
 * @param ray The ray to test for intersection
 * @return Array of intersection records or NULL
 */
t_isect	**ray_intersect_cylinder(t_object *obj, t_ray *ray)
{
	// Placeholder for future implementation
	// Currently always returns NULL
	if (!obj || !ray || obj->type != CYLINDER)
		return (NULL);
		
	// TODO: Implement cylinder intersection logic
	return (NULL);
}