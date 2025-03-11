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

	v_to_light = matrix_subs(lux->p_light->origin, point);
	distance = matrix_length(v_to_light);
	matrix_normalize(v_to_light);
	
	point_offset = matrix_clone(point);
	point_offset->data[0][0] += v_to_light->data[0][0] * EPSILON_VAL;
	point_offset->data[1][0] += v_to_light->data[1][0] * EPSILON_VAL;
	point_offset->data[2][0] += v_to_light->data[2][0] * EPSILON_VAL;
	
	shadow_ray = ray_create(point_offset, v_to_light);
	intersections = ray_intersect_world(lux, shadow_ray);
	
	shadowed = false;
	if (intersections && intersections[0] && 
		intersections[0]->t_val > 0 && 
		intersections[0]->t_val < distance)
	{
		shadowed = true;
	}
	
	free_matrix(point_offset);
	free_matrix(v_to_light);
	if (intersections)
		free_dptr((void **)intersections);
	free(shadow_ray);
	
	return (shadowed);
}