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

	if (!lux || !inter || !inter[0] || !ray || !ray->direction || !ray->origin)
		return (NULL);

	comps = safe_malloc(sizeof(t_comps), 1);
	if (!comps)
		return (NULL);

	comps->t_val = inter[0]->t_val;
	comps->type = inter[0]->obj_type;
	
	// Check for valid object ID
	if (inter[0]->obj_id < 0 || !lux->objects[inter[0]->obj_id])
	{
		free(comps);
		return (NULL);
	}
	
	comps->object = lux->objects[inter[0]->obj_id];
	comps->p_intersect = ray_position(ray, comps->t_val);
	
	// Check if ray_position succeeded
	if (!comps->p_intersect)
	{
		free(comps);
		return (NULL);
	}
	
	comps->v_eye = matrix_clone(ray->direction);
	if (!comps->v_eye)
	{
		free_matrix(comps->p_intersect);
		free(comps);
		return (NULL);
	}
	
	matrix_scalar_mult(comps->v_eye, -1);
	
	// Create a default normal vector if sphere_normal fails
	comps->v_normal = sphere_normal(comps->object, comps->p_intersect);
	if (!comps->v_normal)
	{
		// Create a fallback normal (straight up)
		comps->v_normal = matrix_create(4, 1);
		if (!comps->v_normal)
		{
			free_matrix(comps->p_intersect);
			free_matrix(comps->v_eye);
			free(comps);
			return (NULL);
		}
		
		// Default normal pointing up
		comps->v_normal->data[0][0] = 0;
		comps->v_normal->data[1][0] = 1;
		comps->v_normal->data[2][0] = 0;
		comps->v_normal->data[3][0] = 0;
	}
	
	return (comps);
}
