/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:34:16 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/24 17:35:20 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_parse.h"
#include "base_matrices.h"
#include "muk_lib.h"
#include "objects_transform.h"
#include "objects_utils.h"

void	parse_plane(t_parse *pars, char **split_line)
{
	t_object	*curr;

	curr = NULL;
	parse_validate_obj(pars, split_line, PLANE);
	if (pars->error_encountered == true)
		return ;
	curr = (t_object *)safe_malloc(sizeof(t_object), 1);
	if (curr == NULL)
	{
		pars->error_encountered = true;
		return ;
	}
	curr->type = PLANE;
	curr->obj.plane.origin = matrix_create(4, 1);
	curr->obj.plane.v_orient = matrix_create(4, 1);
	parse_assign_coord(pars, split_line[1], curr->obj.plane.origin);
	parse_assign_vec(pars, split_line[2], curr->obj.plane.v_orient);
	parse_assign_trgb(pars, split_line[3], &curr->obj.plane.color);
	if (pars->error_encountered == true || \
			add_to_dptr((void ***)&pars->lux->objects, (void *)curr))
	{
		free(curr);
		return ;
	}
	pars->count_pl++;
}

static t_object	*init_sphere(t_parse *pars, char **split_line)
{
	t_object	*curr;
	t_matrix	*scaling;
	t_matrix	*transform_temp;

	curr = (t_object *)safe_malloc(sizeof(t_object), 1);
	if (curr == NULL)
	{
		pars->error_encountered = true;
		return (NULL);
	}
	curr->type = SPHERE;
	curr->obj.sphere.origin = matrix_create(4, 1);
	parse_assign_coord(pars, split_line[1], curr->obj.sphere.origin);
	parse_assign_trgb(pars, split_line[3], &curr->obj.sphere.color);
	curr->obj.sphere.radius = ft_atod(split_line[2]) / 2;
	curr->obj.sphere.transform = matrix_identity(4);
	scaling = object_scaling(curr->obj.sphere.radius, \
			curr->obj.sphere.radius,
			curr->obj.sphere.radius);
	transform_temp = \
			matrix_multiple(curr->obj.sphere.transform, scaling);
	free_matrix(curr->obj.sphere.transform);
	curr->obj.sphere.transform = transform_temp;
	free_matrix(scaling);
	return (curr);
}

void	parse_sphere(t_parse *pars, char **split_line)
{
	t_object	*curr;

	parse_validate_obj(pars, split_line, SPHERE);
	if (pars->error_encountered == true)
		return ;
	curr = init_sphere(pars, split_line);
	if (curr == NULL)
		return ;
	if (pars->error_encountered == true \
		|| add_to_dptr((void ***)&pars->lux->objects, (void *)curr))
	{
		free_object(curr);
		free(curr);
		return ;
	}
	pars->count_sp++;
}

void	parse_cylinder(t_parse *pars, char **split_line)
{
	t_object	*curr;

	curr = NULL;
	parse_validate_obj(pars, split_line, CYLINDER);
	if (pars->error_encountered == true)
		return ;
	curr = (t_object *)safe_malloc(sizeof(t_object), 1);
	if (curr == NULL)
		pars->error_encountered = true;
	curr->type = CYLINDER;
	curr->obj.cylinder.origin = matrix_create(4, 1);
	curr->obj.cylinder.v_orient = matrix_create(4, 1);
	parse_assign_coord(pars, split_line[1], curr->obj.cylinder.origin);
	parse_assign_vec(pars, split_line[2], curr->obj.cylinder.v_orient);
	curr->obj.cylinder.diameter = ft_atod(split_line[3]);
	curr->obj.cylinder.height = ft_atod(split_line[4]);
	parse_assign_trgb(pars, split_line[5], &curr->obj.cylinder.color);
	if (pars->error_encountered == true || \
			add_to_dptr((void ***)&pars->lux->objects, (void *)curr))
	{
		free(curr);
		return ;
	}
	pars->count_cy++;
}
