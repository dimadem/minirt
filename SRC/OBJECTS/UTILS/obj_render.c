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

static void	calculate_uv(int i, int j, t_camera *camera)
{
	camera->viewport.u = (2.0 * ((i + 0.5) / WINDOW_WIDTH) - 1.0) \
							* camera->half_width;
	camera->viewport.v = (1.0 - 2.0 * ((j + 0.5) / WINDOW_HEIGHT)) \
							* camera->half_height;
}

static bool	process_pixel(int x, int y, t_object **objects, t_camera *camera)
{
	t_ray	ray;
	t_isect	**inter;
	int		i;
	bool	hit;

	hit = false;
	calculate_uv(x, y, camera);
	matrix_normalize(camera->v_orient);
	ray = ray_create_local(camera->origin, &camera->viewport);
	i = 0;
	while (objects[i] != NULL)
	{
		inter = ray_intersect_sphere(objects[i], &ray);
		if (inter != NULL)
		{
			hit = true;
			free_dptr((void **)inter);
		}
		i++;
	}
	return (hit);
}

void	obj_render(int **pixel, t_object **objects, t_camera *camera)
{
	int		y;
	int		x;
	bool	hit;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			hit = process_pixel(x, y, objects, camera);
			if (hit == true)
				pixel[y][x] = 0xFFFFFFFF;
			else
				pixel[y][x] = 0x00000000;
			x++;
		}
		y++;
	}
}
