/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_world_intersect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:27:18 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/20 12:15:18 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIB/Unity/src/unity.h"
#include "test.h"

#include "base_helpers.h"
#include "base_matrices.h"
#include "base_rays.h"
#include "objects_transform.h"
#include "muk_lib.h"
#include <stdlib.h>

// ************************************************************************** //
//                             GLOBAL VARIABLES                               //
// ************************************************************************** //
static t_object		*sph1 = NULL;
static t_object		*sph2 = NULL;

static t_ray		*ray1 = NULL;

static t_rayt		*lux = NULL;

static t_isect		**inter = NULL;

static t_comps		*comps = NULL;

// ************************************************************************** //
//                              INTERSECT WORLD                               //
// ************************************************************************** //
static void	intersect_world_test()
{
	sph1 = safe_malloc(sizeof(t_object), 1);
	sph2 = safe_malloc(sizeof(t_object), 1);
	ray1 = safe_malloc(sizeof(t_ray), 1);
	lux = safe_malloc(sizeof(t_rayt), 1);

	sph1->obj.sphere.origin = matrix_create(4, 1);
	sph2->obj.sphere.origin = matrix_create(4, 1);
	sph1->obj.sphere.transform = matrix_identity(4);
	sph2->obj.sphere.transform = object_scaling(0.5, 0.5, 0.5);

	ray1->origin = matrix_create(4, 1);
	ray1->origin->data[0][0] = 0; ray1->origin->data[1][0] = 0; ray1->origin->data[2][0] = -5; ray1->origin->data[3][0] = 1;
	ray1->direction = matrix_create(4, 1);
	ray1->direction->data[0][0] = 0; ray1->direction->data[1][0] = 0; ray1->direction->data[2][0] = 1; ray1->direction->data[3][0] = 0;

	lux->objects = safe_malloc(sizeof(t_object *), 3);
	lux->objects[0] = sph1; lux->objects[1] = sph2; lux->objects[2] = NULL;

	inter = ray_intersect_world(lux, ray1);

	TEST_ASSERT_EQUAL(4, inter[0]->count);
	TEST_ASSERT_EQUAL_DOUBLE(4, inter[0]->t_val);
	TEST_ASSERT_EQUAL_DOUBLE(4.5, inter[1]->t_val);
	TEST_ASSERT_EQUAL_DOUBLE(5.5, inter[2]->t_val);
	TEST_ASSERT_EQUAL_DOUBLE(6, inter[3]->t_val);

	print_colored(green_back, "RAY INTERSECT WORLD ORDERED - Passed!");

	free_matrix(sph1->obj.sphere.origin); free_matrix(sph1->obj.sphere.transform); free(sph1);
	free_matrix(sph2->obj.sphere.origin); free_matrix(sph2->obj.sphere.transform); free(sph2);
	free_matrix(ray1->origin); free_matrix(ray1->direction); free(ray1);
	free_dptr((void **)inter);
	free(lux->objects); free(lux);
}

// ************************************************************************** //
//                           PREPARE COMPUTATIONS                             //
// ************************************************************************** //
static void	create_prepare_computations_test(void)
{
	sph1 = safe_malloc(sizeof(t_object), 1);
	ray1 = safe_malloc(sizeof(t_ray), 1);
	lux = safe_malloc(sizeof(t_rayt), 1);

	sph1->obj.sphere.origin = matrix_create(4, 1);
	sph1->obj.sphere.transform = matrix_identity(4);

	ray1->origin = matrix_create(4, 1);
	ray1->origin->data[0][0] = 0; ray1->origin->data[1][0] = 0; ray1->origin->data[2][0] = -5; ray1->origin->data[3][0] = 1;
	ray1->direction = matrix_create(4, 1);
	ray1->direction->data[0][0] = 0; ray1->direction->data[1][0] = 0; ray1->direction->data[2][0] = 1; ray1->direction->data[3][0] = 0;

	lux->objects = safe_malloc(sizeof(t_object *), 2);
	lux->objects[0] = sph1; lux->objects[1] = NULL;

	inter = ray_intersect_world(lux, ray1);

	comps = prepare_computations(lux, inter, ray1);

	t_matrix	*testmat = matrix_create(4, 1);
	TEST_ASSERT_EQUAL_DOUBLE(comps->t_val, inter[0]->t_val);
	TEST_ASSERT_EQUAL(comps->obj_id, inter[0]->obj_id);
	testmat->data[0][0] = 0; testmat->data[1][0] = 0; testmat->data[2][0] = -1; testmat->data[3][0] = 1;
	TEST_ASSERT_EQUAL(0, matrix_compare(comps->p_intersect, testmat));
	testmat->data[3][0] = 0;
	TEST_ASSERT_EQUAL(0, matrix_compare(comps->v_eye, testmat));
	TEST_ASSERT_EQUAL(0, matrix_compare(comps->v_normal, testmat));

	print_colored(green_back, "PREPARE COMPS STRUCTURE - Passed!");

	free_matrix(sph1->obj.sphere.origin); free_matrix(sph1->obj.sphere.transform); free(sph1);
	free_matrix(ray1->origin); free_matrix(ray1->direction); free(ray1);
	free(lux->objects); free(lux); free_matrix(testmat);
	free_matrix(comps->p_intersect); free_matrix(comps->v_eye); free_matrix(comps->v_normal); free(comps);
}

// ************************************************************************** //
//                              ENTRY FUNCTION                                //
// ************************************************************************** //
void	intersection_test_ray_world(void)
{
	UNITY_BEGIN();
	print_colored(cyan_back, "-> WORLD INTERSECTION FEATURE <-");

	print_colored(bold, "TEST - RAY-SPHERE INTERSECT");
	RUN_TEST(intersect_world_test);
	printf("\n");

	print_colored(bold, "TEST - CREATE \"PREPARE COMPUTATIONS STRUCTURE\"");
	RUN_TEST(create_prepare_computations_test);
	printf("\n");

	UNITY_END();
}