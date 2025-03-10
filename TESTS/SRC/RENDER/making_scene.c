/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:39:51 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/10 18:13:53 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../LIB/Unity/src/unity.h"
#include "types.h"
#include "test.h"
#include "mini_features.h"
#include "mini_ray.h"
#include <stdlib.h>

// ************************************************************************** //
//                             GLOBAL VARIABLES                               //
// ************************************************************************** //
static t_rayt		*lux = NULL;
static t_sphere		*sph1 = NULL;
static t_sphere		*sph2 = NULL;
static t_light		*light = NULL;
static t_ray		*ray1 = NULL;

static void	global_var_init(void)
{
	lux = safe_malloc(sizeof(t_rayt), 1);
	sph1 = safe_malloc(sizeof(t_sphere), 1);
	sph2 = safe_malloc(sizeof(t_sphere), 1);
	light = safe_malloc(sizeof(t_light), 1);
	ray1 = safe_malloc(sizeof(t_ray), 1);

	light->origin = matrix_create(4, 1);
	light->origin->data[0][0] = -10; light->origin->data[1][0] = 10; light->origin->data[2][0] = -10; light->origin->data[3][0] = 1;
	light->brightness_ratio = 1;
	light->type = LIGHT;
	light->color = colour(255, 255, 255);

	sph1->origin = matrix_create(4, 1);
	sph1->origin->data[0][0] = 0; sph1->origin->data[1][0] = 0; sph1->origin->data[2][0] = 0; sph1->origin->data[3][0] = 1;
	sph1->color = colour(255 * 0.8, 255, 255 * 0.6);
	sph1->transform = matrix_identity(4);
	sph1->mat.diffuse = 0.7; sph1->mat.specular = 0.2;

	sph2->origin = matrix_clone(sph1->origin);
	sph2->transform = object_scaling(0.5, 0.5, 0.5);

	ray1->origin = matrix_create(4, 1);
	ray1->origin->data[0][0] = 0; ray1->origin->data[1][0] = 0; ray1->origin->data[2][0] = -5; ray1->origin->data[3][0] = 1;
	ray1->vector = matrix_create(4, 1);
	ray1->origin->data[0][0] = 0; ray1->origin->data[1][0] = 0; ray1->origin->data[2][0] = 1; ray1->origin->data[3][0] = 0;

	lux->p_light = light;
	lux->sphere = malloc(sizeof(t_sphere *) * 3);
	lux->sphere[0] = sph1; lux->sphere[1] = sph2; lux->sphere[2] = NULL;
}

// ************************************************************************** //
//                              INTERSECT RAY                                 //
// ************************************************************************** //
void	intersect_world_ray(void)
{
	intersect_world(lux, ray1);

}

// ************************************************************************** //
//                              ENTRY FUNCTION                                //
// ************************************************************************** //
void	making_scene(void)
{
	global_var_init();

	UNITY_BEGIN();
	print_colored(cyan_back, "-> Making Scene & World <-");

	print_colored(bold, "TEST - INTERSECT WORLD - RAY");
	RUN_TEST(intersect_world_ray);
	printf("\n");


	UNITY_END();
}
