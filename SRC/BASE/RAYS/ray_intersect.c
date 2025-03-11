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

static void	asgva(t_isect ***a_ix, double t1, double t2)
{
	t_isect	*inter1;
	t_isect	*inter2;

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
	
	asgva(&all_inter, t1, t2);
	free_matrix(sptoray);
	free_ray(nray);
	return (all_inter);
}

t_isect	**ray_intersect_plane(t_object *obj, t_ray *ray)
{
	t_isect		**all_inter;
	double		denom;
	double		t;
	t_matrix	*normal;

	if (!obj || !ray || obj->type != PLANE || !obj->obj.plane.v_orient)
		return (NULL);
		
	all_inter = NULL;
	normal = obj->obj.plane.v_orient;
	
	// Check if ray is parallel to plane
	denom = matrix_dot(normal, ray->direction);
	if (fabs(denom) < 0.0001)
		return (NULL);  // Ray is parallel to plane
	
	// Calculate distance to intersection
	t = matrix_dot(matrix_subs(obj->obj.plane.origin, ray->origin), normal) / denom;
	
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

t_isect	**ray_intersect_cylinder(t_object *obj, t_ray *ray)
{
	// Simplified cylinder intersection logic - returns NULL for now
	// Will be implemented properly in a future update
	(void)obj;
	(void)ray;
	return (NULL);
}