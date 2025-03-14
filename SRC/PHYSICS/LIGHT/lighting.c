/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:46:44 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/08 17:16:12 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"
#include "base_colours.h"
#include "physics_light.h"
#include <math.h>

static void	trgb_init(t_mat *result, t_mat material, t_light *light)
{
	t_trgb	temp;

	temp = colour_hadamard_product(material.colour, light->color);
	result->colour = colour_scalar_mult(temp, (double)0.00392156862);
	result->diffuse = 0;
	result->specular = 0;
	result->ambient = light->brightness_ratio * material.ambient;
}

t_mat	lighting(t_rayt *lux, t_mat mat, t_matrix *pos, t_matrix *v_normal)
{
	t_mat		result;
	double		dot_h;
	t_matrix	*v_light;
	t_matrix	*v_reflect;

	v_reflect = NULL;
	trgb_init(&result, mat, lux->p_light);
	v_light = matrix_subs(lux->p_light->origin, pos);
	matrix_normalize(v_light);
	dot_h = matrix_dot(v_light, v_normal);
	if (dot_h > 0)
	{
		result.diffuse = lux->p_light->brightness_ratio * mat.diffuse * dot_h;
		matrix_scalar_mult(v_light, -1);
		v_reflect = reflect(v_light, v_normal);
		dot_h = matrix_dot(v_reflect, lux->camera->v_orient);
		if (dot_h > 0)
			result.specular = lux->p_light->brightness_ratio * mat.specular * \
				pow(dot_h, mat.shininess);
	}
	result.brightness_ratio = result.ambient + result.diffuse + result.specular;
	free_matrix(v_reflect);
	free_matrix(v_light);
	return (result);
}
