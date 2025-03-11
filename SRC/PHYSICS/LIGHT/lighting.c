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
#include "libft.h"
#include <math.h>

static void	trgb_init(t_mat *result, t_mat *material, t_light *light)
{
	// Add null checks
	if (!result || !material || !light)
		return;

	// Initialize with default values first in case of early return
	result->colour.r = 0;
	result->colour.g = 0; 
	result->colour.b = 0;
	result->colour.t = 0;
	result->diffuse = 0;
	result->specular = 0;
	result->ambient = 0;
	result->brightness_ratio = 0;
	
	// Calculate color
	result->colour = colour_hadamard_product(material->colour, light->color);
	
	// Scale by constant factor
	result->colour.r *= 0.00392156862;
	result->colour.g *= 0.00392156862;
	result->colour.b *= 0.00392156862;
	
	// Set ambient light
	result->ambient = light->brightness_ratio * material->ambient;
}

static double	calculate_specular(t_matrix *v_light, t_matrix *v_normal, 
						t_matrix *camera_orient, t_light *light, t_mat mat)
{
	t_matrix	*v_reflect;
	double		dot_h;
	double		specular;

	specular = 0.0;
	
	if (!v_light || !v_normal || !camera_orient || !light)
		return (specular);
		
	matrix_scalar_mult(v_light, -1);
	v_reflect = reflect(v_light, v_normal);
	
	if (v_reflect)
	{
		dot_h = matrix_dot(v_reflect, camera_orient);
		if (dot_h > 0)
			specular = light->brightness_ratio * mat.specular * 
				pow(dot_h, mat.shininess);
		free_matrix(v_reflect);
	}
	
	return (specular);
}

t_mat	lighting(t_rayt *lux, t_mat mat, t_matrix *pos, t_matrix *v_normal)
{
	t_mat		result;
	double		dot_h;
	t_matrix	*v_light;
	bool		in_shadow;

	// Initialize the result with zero values
	ft_bzero(&result, sizeof(t_mat));
	
	// Add null checks
	if (!lux || !lux->p_light || !pos || !v_normal || !lux->camera || !lux->camera->v_orient)
		return (result);
	
	trgb_init(&result, &mat, lux->p_light);
	
	// Check for shadows if shadow detection is available
	in_shadow = is_shadowed(lux, pos);
	
	if (!in_shadow)
	{
		v_light = matrix_subs(lux->p_light->origin, pos);
		if (!v_light)
			return (result);
			
		matrix_normalize(v_light);
		dot_h = matrix_dot(v_light, v_normal);
		
		if (dot_h > 0)
		{
			result.diffuse = lux->p_light->brightness_ratio * mat.diffuse * dot_h;
			result.specular = calculate_specular(v_light, v_normal, 
				lux->camera->v_orient, lux->p_light, mat);
		}
		
		free_matrix(v_light);
	}
	
	// Calculate final brightness
	result.brightness_ratio = result.ambient + result.diffuse + result.specular;
	return (result);
}
