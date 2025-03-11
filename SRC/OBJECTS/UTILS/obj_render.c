/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:33:33 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/24 17:28:23 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects_sphere.h"
#include "base_matrices.h"
#include "base_rays.h"
#include "window_size.h"
#include "muk_lib.h"
#include "base_helpers.h"
#include "base_colours.h"
#include "physics_light.h"

static void	calculate_uv(int i, int j, t_camera *camera)
{
	camera->viewport.u = (2.0 * ((i + 0.5) / WINDOW_WIDTH) - 1.0) \
							* camera->half_width;
	camera->viewport.v = (1.0 - 2.0 * ((j + 0.5) / WINDOW_HEIGHT)) \
							* camera->half_height;
}

static int	process_pixel(int x, int y, t_rayt *lux)
{
	t_ray		ray;
	t_isect		**intersections;
	t_comps		*comp;
	t_mat		material;
	int			color;

	calculate_uv(x, y, lux->camera);
	matrix_normalize(lux->camera->v_orient);
	ray = ray_create_local(lux->camera->origin, &lux->camera->viewport);
	
	intersections = ray_intersect_world(lux, &ray);
	if (!intersections || !intersections[0])
	{
		if (intersections)
			free_dptr((void **)intersections);
		return (0x00000000);
	}
	
	comp = prepare_computations(lux, intersections, &ray);
	
	// Get the appropriate color based on object type
	if (comp->type == SPHERE)
		material.colour = comp->object->obj.sphere.color;
	else if (comp->type == PLANE)
		material.colour = comp->object->obj.plane.color;
	else if (comp->type == CYLINDER)
		material.colour = comp->object->obj.cylinder.color;
	
	// Set default material properties
	material.ambient = 0.1;
	material.diffuse = 0.7;
	material.specular = 0.2;
	material.shininess = 200.0;
	
	material = lighting(lux, material, comp->p_intersect, comp->v_normal);
	
	// Modify the color based on lighting calculations
	t_trgb adjusted_color = material.colour;
	adjusted_color.r *= material.brightness_ratio;
	adjusted_color.g *= material.brightness_ratio;
	adjusted_color.b *= material.brightness_ratio;
	
	color = colour_to_int(adjusted_color);
	
	free_dptr((void **)intersections);
	free_matrix(comp->p_intersect);
	free_matrix(comp->v_eye);
	free_matrix(comp->v_normal);
	free(comp);
	
	return (color);
}

void	obj_render(int **pixel, t_rayt *lux)
{
	int		y;
	int		x;
	int		color;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			color = process_pixel(x, y, lux);
			pixel[y][x] = color;
			x++;
		}
		y++;
	}
}
