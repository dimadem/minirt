/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:00:00 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/03/11 12:00:00 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "base_rays.h"
#include "base_matrices.h"
#include "muk_lib.h"
#include "base_helpers.h"

#define EPSILON_VAL 0.0001

bool	is_shadowed(t_rayt *lux, t_matrix *point)
{
	t_matrix	*v_to_light;
	t_matrix	*point_offset;
	t_ray		*shadow_ray;
	t_isect		**intersections;
	double		distance;
	bool		shadowed;

	if (!lux || !lux->p_light || !lux->p_light->origin || !point)
		return (false);

	v_to_light = matrix_subs(lux->p_light->origin, point);
	if (!v_to_light)
		return (false);
		
	distance = matrix_length(v_to_light);
	matrix_normalize(v_to_light);
	
	point_offset = matrix_clone(point);
	if (!point_offset)
	{
		free_matrix(v_to_light);
		return (false);
	}
	
	// Offset point slightly to avoid self-shadowing
	point_offset->data[0][0] += v_to_light->data[0][0] * EPSILON_VAL;
	point_offset->data[1][0] += v_to_light->data[1][0] * EPSILON_VAL;
	point_offset->data[2][0] += v_to_light->data[2][0] * EPSILON_VAL;
	
	// ray_create now clones its input matrices
	shadow_ray = ray_create(point_offset, v_to_light);
	if (!shadow_ray)
	{
		free_matrix(point_offset);
		free_matrix(v_to_light);
		return (false);
	}
	
	intersections = ray_intersect_world(lux, shadow_ray);
	
	shadowed = false;
	if (intersections && intersections[0] && 
		intersections[0]->t_val > 0 && 
		intersections[0]->t_val < distance)
	{
		shadowed = true;
	}
	
	// Free all resources
	if (intersections)
		free_dptr((void **)intersections);
	free_ray(shadow_ray);  // This will free its internal copies
	free_matrix(point_offset);
	free_matrix(v_to_light);
	
	return (shadowed);
}