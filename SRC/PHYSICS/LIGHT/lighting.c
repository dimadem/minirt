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

static void	trgb_init(t_mat *result, t_mat *material, t_light *light)
{
	if (!result || !material || !light)
		return;

	result->colour.r = 0;
	result->colour.g = 0; 
	result->colour.b = 0;
	result->colour.t = 0;
	result->diffuse = 0;
	result->specular = 0;
	result->ambient = 0;
	result->brightness_ratio = 0;
	
	result->colour = colour_hadamard_product(material->colour, light->color);
	
	// Scale by constant factor (1/255)
	result->colour.r *= 0.00392156862;
	result->colour.g *= 0.00392156862;
	result->colour.b *= 0.00392156862;
	
	result->ambient = light->brightness_ratio * material->ambient;
}

static void	calculate_diffuse_lighting(t_mat *result, t_mat *mat, 
										t_light *light, double dot_product)
{
	if (!result || !mat || !light || dot_product <= 0)
		return;
		
	result->diffuse = light->brightness_ratio * mat->diffuse * dot_product;
}

static void	calculate_specular_lighting(t_mat *result, t_mat *mat, 
										t_light *light, t_matrix *v_reflect, 
										t_matrix *v_camera)
{
	double	dot_product;
	
	if (!result || !mat || !light || !v_reflect || !v_camera)
		return;
		
	dot_product = matrix_dot(v_reflect, v_camera);
	if (dot_product <= 0)
		return;
		
	result->specular = light->brightness_ratio * mat->specular * 
						pow(dot_product, mat->shininess);
}

static void	calculate_direct_lighting(t_rayt *lux, t_mat *result, 
									t_mat *mat, t_matrix *pos, t_matrix *v_normal)
{
	t_matrix	*v_light;
	t_matrix	*v_reflect;
	double		dot_product;
	
	v_light = matrix_subs(lux->p_light->origin, pos);
	if (!v_light)
		return;
		
	matrix_normalize(v_light);
	dot_product = matrix_dot(v_light, v_normal);
	
	if (dot_product > 0)
	{
		calculate_diffuse_lighting(result, mat, lux->p_light, dot_product);
		
		matrix_scalar_mult(v_light, -1);
		v_reflect = reflect(v_light, v_normal);
		
		if (v_reflect)
		{
			calculate_specular_lighting(result, mat, lux->p_light, 
										v_reflect, lux->camera->v_orient);
			free_matrix(v_reflect);
		}
	}
	
	free_matrix(v_light);
}

t_mat	lighting(t_rayt *lux, t_mat mat, t_matrix *pos, t_matrix *v_normal)
{
	t_mat		result;
	bool		in_shadow;

	ft_bzero(&result, sizeof(t_mat));
	
	if (!lux || !lux->p_light || !pos || !v_normal || 
		!lux->camera || !lux->camera->v_orient)
		return (result);
	
	trgb_init(&result, &mat, lux->p_light);
	in_shadow = is_shadowed(lux, pos);
	
	if (!in_shadow)
		calculate_direct_lighting(lux, &result, &mat, pos, v_normal);
	
	result.brightness_ratio = result.ambient + result.diffuse + result.specular;
	return (result);
}
