/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_shading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:14:25 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/15 10:23:00 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIB/Unity/src/unity.h"
#include "test.h"
#include "physics_light.h"
#include "base_colours.h"
#include "objects_transform.h"
#include "objects_sphere.h"
#include "base_helpers.h"
#include "base_matrices.h"
#include "muk_lib.h"
#include <stdlib.h>
#include <math.h>

// ************************************************************************** //
//                             GLOBAL VARIABLES                               //
// ************************************************************************** //
static t_matrix		*poi1 = NULL;
static t_matrix		*vec1 = NULL;
static t_matrix		*temp1 = NULL;
static t_matrix		*temp2 = NULL;
static t_object		*curr = NULL;

static t_matrix		*v_camera = NULL;
static t_matrix		*v_normal = NULL;
static t_light		*light = NULL;
static t_camera		*camera = NULL;

static t_rayt		*lux = NULL;

// ************************************************************************** //
//                              FINDING NORMAL                                //
// ************************************************************************** //
void	finding_normal_test()
{
	curr = safe_malloc(sizeof(t_object), 1);
	curr->obj.sphere.transform = object_translation(0, 1, 0);
	poi1 = matrix_create(4, 1);
	poi1->data[0][0] = 0; poi1->data[1][0] = 1.70711; poi1->data[2][0] = -0.70711; poi1->data[3][0] = 1;
	vec1 = sphere_normal(curr, poi1);

	TEST_ASSERT_EQUAL_FLOAT(0, vec1->data[0][0]);
	TEST_ASSERT_EQUAL_FLOAT(0.70711, vec1->data[1][0]);
	TEST_ASSERT_EQUAL_FLOAT(-0.70711, vec1->data[2][0]);
	TEST_ASSERT_EQUAL_FLOAT(0, vec1->data[3][0]);
	print_colored(green_back, "Normal - Normal on a Translated Sphere - Passed!");

	free_matrix(curr->obj.sphere.transform); free_matrix(poi1); free_matrix(vec1);

	temp1 = object_scaling(1, 0.5, 1);
	temp2 = rotation_z(M_PI / 5);
	curr->obj.sphere.transform = matrix_multiple(temp1, temp2);
	free_matrix(temp1); free_matrix(temp2);
	temp1 = matrix_create(4, 1);
	temp1->data[0][0] = 0; temp1->data[1][0] = sqrt(2) / 2; temp1->data[2][0] = sqrt(2) / -2; temp1->data[3][0] = 1;
	vec1 = sphere_normal(curr, temp1);
	temp1->data[0][0] = 0; temp1->data[1][0] = 0.97014; temp1->data[2][0] = -0.24254; temp1->data[3][0] = 0;
	
	TEST_ASSERT_EQUAL(0, matrix_compare(vec1, temp1));
	print_colored(green_back, "Normal - Normal on a Transformed Sphere - Passed!");

	free_matrix(curr->obj.sphere.transform); free_matrix(vec1); free(curr); free_matrix(temp1);
}

// ************************************************************************** //
//                              REFLECTION VEC                                //
// ************************************************************************** //
void	finding_reflection_test()
{
	vec1 = matrix_create(4, 1);
	temp1 = matrix_create(4, 1);

	vec1->data[0][0] = 1; vec1->data[1][0] = -1; vec1->data[2][0] = 0; vec1->data[3][0] = 0;
	temp1->data[0][0] = 0; temp1->data[1][0] = 1; temp1->data[2][0] = 0; temp1->data[3][0] = 0;

	temp2 = reflect(vec1, temp1);
	temp1->data[0][0] = 1; temp1->data[1][0] = 1; temp1->data[2][0] = 0; temp1->data[3][0] = 0;

	TEST_ASSERT_EQUAL(0, matrix_compare(temp1, temp2));
	print_colored(green_back, "Normal - Reflection 45 deg - Passed!");

	free_matrix(temp2);

	vec1->data[0][0] = 0; vec1->data[1][0] = -1; vec1->data[2][0] = 0; vec1->data[3][0] = 0;
	temp1->data[0][0] = sqrt(2) / 2; temp1->data[1][0] = sqrt(2) / 2; temp1->data[2][0] = 0; temp1->data[3][0] = 0;

	temp2 = reflect(vec1, temp1);
	temp1->data[0][0] = 1; temp1->data[1][0] = 0; temp1->data[2][0] = 0; temp1->data[3][0] = 0;

	TEST_ASSERT_EQUAL(0, matrix_compare(temp1, temp2));
	print_colored(green_back, "Normal - Reflection off a Slanted Surface - Passed!");

	free_matrix(vec1); free_matrix(temp1); free_matrix(temp2);
}
// ************************************************************************** //
//                          PHONG LIGHT REFLECTION                            //
// ************************************************************************** //
void	phongy_phong_test()
{
	t_mat	material;
	t_mat	result;

	material.colour = colour(255, 255, 255); material.ambient = 0.1; material.diffuse = 0.9; material.specular = 0.9; material.shininess = 200;

	poi1 = matrix_create(4, 1);
	poi1->data[0][0] = 0; poi1->data[1][0] = 0; poi1->data[2][0] = 0; poi1->data[3][0] = 1;

	v_camera = matrix_create(4, 1);
	v_camera->data[0][0] = 0; v_camera->data[1][0] = 0; v_camera->data[2][0] = -1; v_camera->data[3][0] = 0;

	v_normal = matrix_create(4, 1);
	v_normal->data[0][0] = 0; v_normal->data[1][0] = 0; v_normal->data[2][0] = -1; v_normal->data[3][0] = 0;

	light = safe_malloc(sizeof(t_light), 1);
	light->origin = matrix_create(4, 1);
	light->origin->data[0][0] = 0; light->origin->data[1][0] = 0; light->origin->data[2][0] = -10; light->origin->data[3][0] = 1;
	light->color = colour(255, 255, 255);
	light->brightness_ratio = 1;

	lux = safe_malloc(sizeof(t_rayt), 1);
	camera = safe_malloc(sizeof(t_camera), 1);
	lux->p_light = light;
	lux->camera = camera;
	camera->v_orient = v_camera;

	result = lighting(lux, material, poi1, v_normal);

	TEST_ASSERT_EQUAL_DOUBLE(0.1, result.ambient);
	TEST_ASSERT_EQUAL_DOUBLE(0.9, result.diffuse);
	TEST_ASSERT_EQUAL_DOUBLE(0.9, result.specular);
	TEST_ASSERT_EQUAL_DOUBLE(1.9, result.brightness_ratio);
	print_colored(green_back, "PHONG - Light Behind Camera - Passed!");

	v_camera->data[0][0] = 0; v_camera->data[1][0] = sqrt(2) / 2; v_camera->data[2][0] = sqrt(2) / -2; v_camera->data[3][0] = 0;
	v_normal->data[0][0] = 0; v_normal->data[1][0] = 0; v_normal->data[2][0] = -1; v_normal->data[3][0] = 0;
	light->origin->data[0][0] = 0; light->origin->data[1][0] = 0; light->origin->data[2][0] = -10; light->origin->data[3][0] = 1;
	light->color = colour(255, 255, 255);
	light->brightness_ratio = 1;

	result = lighting(lux, material, poi1, v_normal);

	TEST_ASSERT_EQUAL_DOUBLE(0.1, result.ambient);
	TEST_ASSERT_EQUAL_DOUBLE(0.9, result.diffuse);
	TEST_ASSERT_EQUAL(1, epsilon(0, result.specular));
	TEST_ASSERT_EQUAL_DOUBLE(1.0, result.brightness_ratio);
	print_colored(green_back, "PHONG - Camera at 45deg from normal - Passed!");
	
	v_camera->data[0][0] = 0; v_camera->data[1][0] = 0; v_camera->data[2][0] = -1; v_camera->data[3][0] = 0;
	v_normal->data[0][0] = 0; v_normal->data[1][0] = 0; v_normal->data[2][0] = -1; v_normal->data[3][0] = 0;
	light->origin->data[0][0] = 0; light->origin->data[1][0] = 10; light->origin->data[2][0] = -10; light->origin->data[3][0] = 1;
	light->color = colour(255, 255, 255);
	light->brightness_ratio = 1;

	result = lighting(lux, material, poi1, v_normal);

	TEST_ASSERT_EQUAL_DOUBLE(0.1, result.ambient);
	TEST_ASSERT_EQUAL_DOUBLE(0.9 * sqrt(2) / 2, result.diffuse);
	TEST_ASSERT_EQUAL(1, epsilon(0, result.specular));
	TEST_ASSERT_EQUAL(1, epsilon(0.7364, result.brightness_ratio));
	print_colored(green_back, "PHONG - Light 45 deg from normal - Passed!");
	
	v_camera->data[0][0] = 0; v_camera->data[1][0] = sqrt(2) / -2; v_camera->data[2][0] = sqrt(2) / -2; v_camera->data[3][0] = 0;
	v_normal->data[0][0] = 0; v_normal->data[1][0] = 0; v_normal->data[2][0] = -1; v_normal->data[3][0] = 0;
	light->origin->data[0][0] = 0; light->origin->data[1][0] = 10; light->origin->data[2][0] = -10; light->origin->data[3][0] = 1;
	light->color = colour(255, 255, 255);
	light->brightness_ratio = 1;

	result = lighting(lux, material, poi1, v_normal);

	TEST_ASSERT_EQUAL_DOUBLE(0.1, result.ambient);
	TEST_ASSERT_EQUAL_DOUBLE(0.9 * sqrt(2) / 2, result.diffuse);
	TEST_ASSERT_EQUAL_DOUBLE(0.9, result.specular);
	TEST_ASSERT_EQUAL(1, epsilon(1.6364, result.brightness_ratio));
	print_colored(green_back, "PHONG - Light & Camera 45 deg from normal - Passed!");

	v_camera->data[0][0] = 0; v_camera->data[1][0] = 0; v_camera->data[2][0] = -1; v_camera->data[3][0] = 0;
	v_normal->data[0][0] = 0; v_normal->data[1][0] = 0; v_normal->data[2][0] = -1; v_normal->data[3][0] = 0;
	light->origin->data[0][0] = 0; light->origin->data[1][0] = 0; light->origin->data[2][0] = 10; light->origin->data[3][0] = 1;
	light->color = colour(255, 255, 255);
	light->brightness_ratio = 1;

	result = lighting(lux, material, poi1, v_normal);

	TEST_ASSERT_EQUAL_DOUBLE(0.1, result.ambient);
	TEST_ASSERT_EQUAL_DOUBLE(0, result.diffuse);
	TEST_ASSERT_EQUAL_DOUBLE(0, result.specular);
	TEST_ASSERT_EQUAL_DOUBLE(0.1, result.brightness_ratio);
	print_colored(green_back, "PHONG - Light Behind Object - Passed!");

	free_matrix(poi1); free_matrix(v_camera); free_matrix(v_normal);
	free_matrix(light->origin); free(light);
	free(camera);  free(lux);
}

// ************************************************************************** //
//                              ENTRY FUNCTION                                //
// ************************************************************************** //
void	light_shading_test(void)
{
	UNITY_BEGIN();
	print_colored(cyan_back, "-> LIGHTING && SHADING <-");

	print_colored(bold, "TEST - TRANSLATED NORMAL VECTOR");
	RUN_TEST(finding_normal_test);
	printf("\n");

	print_colored(bold, "TEST - REFLECTION VECTOR");
	RUN_TEST(finding_reflection_test);
	printf("\n");

	print_colored(bold, "TEST - PHONG REFLECTION");
	RUN_TEST(phongy_phong_test);
	printf("\n");

	UNITY_END();
}