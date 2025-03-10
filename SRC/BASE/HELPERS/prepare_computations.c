/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_computations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:03:54 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/19 18:20:15 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "muk_lib.h"
#include "base_matrices.h"
#include "base_rays.h"
#include "objects_sphere.h"

t_comps	*prepare_computations(t_rayt *lux, t_isect **inter, t_ray *ray)
{
	t_comps	*comps;

	comps = safe_malloc(sizeof(t_comps), 1);
	if (!comps)
		return (NULL);
	comps->t_val = inter[0]->t_val;
	comps->type = inter[0]->obj_type;
	comps->object = lux->objects[inter[0]->obj_id];
	comps->p_intersect = ray_position(ray, comps->t_val);
	comps->v_eye = matrix_clone(ray->direction);
	matrix_scalar_mult(comps->v_eye, -1);
	comps->v_normal = sphere_normal(comps->object, comps->p_intersect);
	return (comps);
}
