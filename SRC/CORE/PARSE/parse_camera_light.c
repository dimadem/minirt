/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:43:47 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/14 23:15:03 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_parse.h"
#include "base_matrices.h"
#include "objects_camera.h"
#include "muk_lib.h"

void	parse_ambient(t_parse *pars, char **split_line)
{
	t_ambient	*ambient;

	parse_validate_obj(pars, split_line, AMBIENT);
	if (pars->error_encountered == true)
		return ;
	ambient = safe_malloc(sizeof(t_ambient), 1);
	if (ambient == NULL)
	{
		pars->error_encountered = true;
		return ;
	}
	ambient->lighting_ratio = ft_atod(split_line[1]);
	parse_assign_trgb(pars, split_line[2], &ambient->color);
	if (pars->error_encountered == true || \
		add_to_ptr((void **)&pars->lux->a_light, (void *)ambient))
	{
		free(ambient);
		return ;
	}
	ambient->type = AMBIENT;
	pars->count_a++;
}

void	parse_camera(t_parse *pars, char **split_line)
{
	t_camera	*camera;

	parse_validate_obj(pars, split_line, CAMERA);
	if (pars->error_encountered == true)
		return ;
	camera = safe_malloc(sizeof(t_camera), 1);
	if (camera == NULL)
	{
		pars->error_encountered = true;
		return ;
	}
	if (pars->error_encountered == true || \
		add_to_ptr((void **)&pars->lux->camera, (void *)camera))
	{
		free(camera);
		return ;
	}
	camera->origin = matrix_create(4, 1);
	camera->v_orient = matrix_create(4, 1);
	parse_assign_coord(pars, split_line[1], camera->origin);
	parse_assign_vec(pars, split_line[2], camera->v_orient);
	camera->fov_deg = ft_atod(split_line[3]);
	camera->type = CAMERA;
	pars->count_c++;
	camera_init(camera);
}

void	parse_light(t_parse *pars, char **split_line)
{
	t_light	*light;

	parse_validate_obj(pars, split_line, LIGHT);
	if (pars->error_encountered == true)
		return ;
	light = safe_malloc(sizeof(t_light), 1);
	if (light == NULL)
	{
		pars->error_encountered = true;
		return ;
	}
	if (pars->error_encountered == true || \
		add_to_ptr((void **)&pars->lux->p_light, (void *)light))
	{
		free(light);
		return ;
	}
	light->origin = matrix_create(4, 1);
	parse_assign_coord(pars, split_line[1], light->origin);
	parse_assign_trgb(pars, split_line[3], &light->color);
	light->brightness_ratio = ft_atod(split_line[2]);
	light->type = LIGHT;
	pars->count_l++;
}
