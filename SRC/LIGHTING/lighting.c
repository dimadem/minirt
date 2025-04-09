/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:46:44 by mcoskune          #+#    #+#             */
/*   Updated: 2025/04/09 14:28:14 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	// result->colour.r *= 0.00392156862;
	// result->colour.g *= 0.00392156862;
	// result->colour.b *= 0.00392156862;
	
	// Set ambient light
	result->ambient = light->brightness_ratio * material->ambient;
}

static double	calculate_specular(t_tuple *v_light, t_tuple *v_normal, t_tuple *camera_orient, t_light *light, t_mat mat)
{
	t_tuple	v_reflect;
	double		dot_h;
	double		specular;

	specular = 0.0;
	
	// if (!v_light || !v_normal || !camera_orient || !light)
	// 	return (specular);
		
	tuple_scalar_mult(v_light, -1);
	v_reflect = reflect(v_light, v_normal);
	
	// if (v_reflect)
	// {
		t_tuple	negative_camera_vec = tuple_scalar_mult(camera_orient, -1);
		dot_h = tuple_dot(&v_reflect, &negative_camera_vec);
		// printf("dot_h is %f\n", dot_h);
		if (dot_h < 0)
		{
			dot_h *= -1;
		}
			// printf("hello spec");
			specular = light->brightness_ratio * mat.specular * pow(dot_h, mat.shininess);

		// }
		// free_matrix(v_reflect);
	// }
	
	return (specular);
}

t_mat	lighting(t_rayt *lux, t_mat mat, t_tuple pos, t_tuple v_normal)
{
	t_mat		result;
	double		dot_h;
	t_tuple		v_light;
	// bool		in_shadow;


	ft_bzero(&result, sizeof(t_mat));
	
	trgb_init(&result, &mat, lux->p_light);
	
	// in_shadow = is_shadowed(lux, pos);
	
	// if (!in_shadow)
	// {
		v_light = tuple_sub(&lux->p_light->origin, &pos);
		v_light = tuple_normalize(&v_light);
		dot_h = tuple_dot(&v_light, &v_normal);
		
		if (dot_h > 0)
		{
			result.diffuse = lux->p_light->brightness_ratio * mat.diffuse * dot_h;
			// We need to clone v_light because calculate_specular will modify it
			t_tuple v_light_copy = v_light;
			result.specular = calculate_specular(&v_light_copy, &v_normal, &lux->camera->v_orient, lux->p_light, mat);

		// }
		

	}

	result.brightness_ratio = result.ambient + result.diffuse + result.specular;
	return (result);
}
