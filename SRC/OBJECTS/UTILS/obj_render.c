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

static t_ray	*create_ray_for_pixel(int x, int y, t_camera *camera)
{
	calculate_uv(x, y, camera);
	matrix_normalize(camera->v_orient);
	return (ray_create_local(camera->origin, &camera->viewport));
}

static void	free_comp(t_comps *comp)
{
	if (!comp)
		return ;
	if (comp->p_intersect)
		free_matrix(comp->p_intersect);
	if (comp->v_eye)
		free_matrix(comp->v_eye);
	if (comp->v_normal)
		free_matrix(comp->v_normal);
	free(comp);
}

static void	print_debug_info(t_comps *comp, int x, int y)
{
	static int debug_count = 0;
	
	if (debug_count >= 20 || !comp)
		return ;
	
	if (comp->type == SPHERE)
		printf("Pixel [%d,%d] hit SPHERE\n", x, y);
	else if (comp->type == PLANE)
		printf("Pixel [%d,%d] hit PLANE\n", x, y);
	else if (comp->type == CYLINDER)
		printf("Pixel [%d,%d] hit CYLINDER\n", x, y);
	debug_count++;
}

static void	setup_material(t_mat *material, t_comps *comp)
{
	ft_bzero(material, sizeof(t_mat));
	
	if (!comp)
		return ;
	
	if (comp->type == SPHERE)
		material->colour = comp->object->obj.sphere.color;
	else if (comp->type == PLANE)
		material->colour = comp->object->obj.plane.color;
	else if (comp->type == CYLINDER)
		material->colour = comp->object->obj.cylinder.color;
	
	material->ambient = 0.1;
	material->diffuse = 0.7;
	material->specular = 0.2;
	material->shininess = 200.0;
}

static int	apply_lighting(t_rayt *lux, t_mat *material, t_comps *comp)
{
	t_trgb	adjusted_color;
	double	brightness;
	
	if (!lux || !lux->p_light || !comp->p_intersect || !comp->v_normal)
		return (colour_to_int(material->colour));
	
	*material = lighting(lux, *material, comp->p_intersect, comp->v_normal);
	
	adjusted_color = material->colour;
	brightness = material->brightness_ratio;
	
	if (brightness < 0.0)
		brightness = 0.0;
	if (brightness > 1.0)
		brightness = 1.0;
	
	adjusted_color.r *= brightness;
	adjusted_color.g *= brightness;
	adjusted_color.b *= brightness;
	
	return (colour_to_int(adjusted_color));
}

static int	process_pixel(int x, int y, t_rayt *lux)
{
	t_ray		*ray;
	t_isect		**intersections;
	t_comps		*comp;
	t_mat		material;
	int			color;

	if (!lux || !lux->camera)
		return (0x00000000);
		
	ray = create_ray_for_pixel(x, y, lux->camera);
	if (!ray)
		return (0x00000000);
	
	intersections = ray_intersect_world(lux, ray);
	if (!intersections || !intersections[0])
	{
		if (intersections)
			free_dptr((void **)intersections);
		free_ray(ray);
		return (0x00000000);
	}
	
	comp = prepare_computations(lux, intersections, ray);
	free_ray(ray);
	
	if (!comp)
	{
		free_dptr((void **)intersections);
		return (0x00000000);
	}
	
	print_debug_info(comp, x, y);
	setup_material(&material, comp);
	color = apply_lighting(lux, &material, comp);
	
	free_dptr((void **)intersections);
	free_comp(comp);
	
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
