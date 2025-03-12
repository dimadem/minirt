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
#include "objects_plane.h"

static t_comps	*init_comp_structure(t_isect *inter)
{
	t_comps	*comps;

	comps = safe_malloc(sizeof(t_comps), 1);
	if (!comps)
		return (NULL);

	comps->t_val = inter->t_val;
	comps->type = inter->obj_type;
	comps->obj_id = inter->obj_id;
	comps->p_intersect = NULL;
	comps->v_eye = NULL;
	comps->v_normal = NULL;
	comps->object = NULL;
	
	return (comps);
}

static int	setup_eye_vector(t_comps *comps, t_ray *ray)
{
	if (!comps || !ray || !ray->direction)
		return (0);
		
	comps->v_eye = matrix_clone(ray->direction);
	if (!comps->v_eye)
		return (0);
		
	matrix_scalar_mult(comps->v_eye, -1);
	return (1);
}

// Removed create_plane_normal function - using plane_normal instead

static t_matrix	*create_fallback_normal(void)
{
	t_matrix	*normal;
	
	normal = matrix_create(4, 1);
	if (!normal)
		return (NULL);
		
	normal->data[0][0] = 0;
	normal->data[1][0] = 1;
	normal->data[2][0] = 0;
	normal->data[3][0] = 0;
	
	return (normal);
}

static int	setup_normal_vector(t_comps *comps)
{
	if (!comps || !comps->object)
		return (0);
		
	if (comps->type == SPHERE)
		comps->v_normal = sphere_normal(comps->object, comps->p_intersect);
	else if (comps->type == PLANE)
	{
		comps->v_normal = plane_normal(comps->object, comps->p_intersect);
		printf("Debug: Created plane normal\n");
	}
	else if (comps->type == CYLINDER)
		comps->v_normal = create_fallback_normal(); // TODO: Implement cylinder normal

	if (!comps->v_normal)
		comps->v_normal = create_fallback_normal();
		
	return (comps->v_normal != NULL);
}

t_comps	*prepare_computations(t_rayt *lux, t_isect **inter, t_ray *ray)
{
	t_comps	*comps;

	if (!lux || !inter || !inter[0] || !ray || !ray->direction || !ray->origin)
		return (NULL);

	comps = init_comp_structure(inter[0]);
	if (!comps)
		return (NULL);

	if (inter[0]->obj_id < 0 || !lux->objects[inter[0]->obj_id])
	{
		free(comps);
		return (NULL);
	}
	
	comps->object = lux->objects[inter[0]->obj_id];
	comps->p_intersect = ray_position(ray, comps->t_val);
	
	if (!comps->p_intersect)
	{
		free(comps);
		return (NULL);
	}
	
	if (!setup_eye_vector(comps, ray))
	{
		free_matrix(comps->p_intersect);
		free(comps);
		return (NULL);
	}
	
	if (!setup_normal_vector(comps))
	{
		free_matrix(comps->p_intersect);
		free_matrix(comps->v_eye);
		free(comps);
		return (NULL);
	}
	
	return (comps);
}
