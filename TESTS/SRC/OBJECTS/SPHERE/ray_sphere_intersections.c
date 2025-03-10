/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere_intersections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:43:25 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/14 14:11:03 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIB/Unity/src/unity.h"
#include "test.h"
#include "base_helpers.h"
#include "base_matrices.h"
#include "base_rays.h"
#include "objects_transform.h"
#include "objects_utils.h"
#include "objects_sphere.h"
#include "muk_lib.h"
#include <stdlib.h>

// ************************************************************************** //
//                          RAY SPHERE INTERSECTION                           //
// ************************************************************************** //
void	ray_sphere_intersect()
{
	t_object		*curr = NULL;
 	t_ray			*ray1 = NULL;
	t_matrix		*or1 = NULL;
	t_matrix		*or2 = NULL;
	t_matrix		*vec2 = NULL;
	t_isect			**inter = NULL;

	// from 
	or1 = matrix_create(4, 1);
	or2 = matrix_create(4, 1);
	or2->data[0][0] = 0; 
	or2->data[1][0] = 0; 
	or2->data[2][0] = -5; 
	or2->data[3][0] = 1;
	// to
	vec2 = matrix_create(4, 1);
	vec2->data[0][0] = 0; 
	vec2->data[1][0] = 0; 
	vec2->data[2][0] = 1; 
	vec2->data[3][0] = 0;
	// create ray
	ray1 = ray_create(or2, vec2);

	// declare sphere
	curr = (t_object *)safe_malloc(sizeof(t_object), 1);
	curr->obj.sphere.radius = 1;
	curr->obj.sphere.transform = matrix_identity(4);
	curr->obj.sphere.origin = or1;
	curr->obj.sphere.origin->data[0][0] = 0; 
	curr->obj.sphere.origin->data[1][0] = 0; 
	curr->obj.sphere.origin->data[2][0] = 0; 
	curr->obj.sphere.origin->data[3][0] = 1;
	curr->type = SPHERE;
	
	// calculate value of intersection
	inter = ray_intersect_sphere(curr, ray1);

	TEST_ASSERT_EQUAL(4, inter[0]->t_val);
	TEST_ASSERT_EQUAL(6, inter[1]->t_val);

	free_dptr((void **)inter);

	print_colored(green_back, "RAY INTERSECT - 2 INTERSECTIONS - PASSED!");

	// rewrite value in vector *from 
	or2->data[1][0] = 1;

	// calculate value of intersection
	inter = ray_intersect_sphere(curr, ray1);
	
	TEST_ASSERT_EQUAL(5, inter[0]->t_val);
	TEST_ASSERT_EQUAL(5, inter[1]->t_val);

	free_dptr((void **)inter);

	print_colored(green_back, "RAY INTERSECT - TANGENT - PASSED!");

	// rewrite value in vector *from 
	or2->data[1][0] = 2;
	inter = ray_intersect_sphere(curr, ray1);

	TEST_ASSERT_NULL(inter);
	free_dptr((void **)inter);
	
	print_colored(green_back, "RAY INTERSECT - NO INTERSECTION - PASSED!");

	// rewrite value in vector *from
	or2->data[1][0] = 0; 
	or2->data[2][0] = 0;

	// calculate value of intersection
	inter = ray_intersect_sphere(curr, ray1);

	TEST_ASSERT_EQUAL(-1, inter[0]->t_val);
	TEST_ASSERT_EQUAL(1, inter[1]->t_val);

	free_dptr((void **)inter);
	print_colored(green_back, "RAY INTERSECT - RAY IN OBJ - PASSED!");

	// rewrite value in vector *from
	or2->data[2][0] = 5;
	// calculate value of intersection
	inter = ray_intersect_sphere(curr, ray1);
	TEST_ASSERT_EQUAL(-6, inter[0]->t_val);
	TEST_ASSERT_EQUAL(-4, inter[1]->t_val);
	print_colored(green_back, "RAY INTERSECT - OBJ BEHIND RAY - PASSED!");
	
	free_dptr((void **)inter);
	free_ray(ray1);
	free_object(curr);
}

// ************************************************************************** //
//                           TRANSFORM RAY-SPHERE                             //
// ************************************************************************** //
void	transform_test_ray_sphere()
{
	t_object		*curr = NULL;
 	t_ray			*ray1 = NULL;
 	t_ray			*ray2 = NULL;
	t_matrix		*or2 = NULL;
	t_matrix		*vec2 = NULL;
	t_matrix		*translation = NULL;
	t_isect			**inter = NULL;

	or2 = matrix_create(4, 1);
	or2->data[0][0] = 1; 
	or2->data[1][0] = 2; 
	or2->data[2][0] = 3; 
	or2->data[3][0] = 1;
	vec2 = matrix_create(4, 1);
	vec2->data[0][0] = 0; vec2->data[1][0] = 1; vec2->data[2][0] = 0; vec2->data[3][0] = 0;
	ray1 = ray_create(or2, vec2);
	translation = object_translation(3, 4, 5);

	ray2 = ray_transform(ray1, translation);
	TEST_ASSERT_EQUAL(4, ray2->origin->data[0][0]); TEST_ASSERT_EQUAL(6, ray2->origin->data[1][0]); TEST_ASSERT_EQUAL(8, ray2->origin->data[2][0]); TEST_ASSERT_EQUAL(1, ray2->origin->data[3][0]);
	TEST_ASSERT_EQUAL(0, ray2->direction->data[0][0]); TEST_ASSERT_EQUAL(1, ray2->direction->data[1][0]); TEST_ASSERT_EQUAL(0, ray2->direction->data[2][0]); TEST_ASSERT_EQUAL(0, ray2->direction->data[3][0]);
	print_colored(green_back, "RAY TRANSLATION - PASSED!");

	free_ray(ray2); free_matrix(translation);

	translation = object_scaling(2, 3, 4);
	ray2 = ray_transform(ray1, translation);
	TEST_ASSERT_EQUAL(2, ray2->origin->data[0][0]); TEST_ASSERT_EQUAL(6, ray2->origin->data[1][0]); TEST_ASSERT_EQUAL(12, ray2->origin->data[2][0]); TEST_ASSERT_EQUAL(1, ray2->origin->data[3][0]);
	TEST_ASSERT_EQUAL(0, ray2->direction->data[0][0]); TEST_ASSERT_EQUAL(3, ray2->direction->data[1][0]); TEST_ASSERT_EQUAL(0, ray2->direction->data[2][0]); TEST_ASSERT_EQUAL(0, ray2->direction->data[3][0]);
	print_colored(green_back, "RAY SCALING - PASSED!");

	free_ray(ray2); free_matrix(translation);

	curr = (t_object *)safe_malloc(sizeof(t_object), 1);
	curr->obj.sphere.transform = object_scaling(2, 2, 2);
	curr->obj.sphere.radius = 1;
	curr->obj.sphere.origin = matrix_create(4, 1);
	curr->type = SPHERE;
	curr->obj.sphere.origin->data[0][0] = 0; curr->obj.sphere.origin->data[1][0] = 0; curr->obj.sphere.origin->data[2][0] = 0; curr->obj.sphere.origin->data[3][0] = 1;
	ray1->origin->data[0][0] = 0; ray1->origin->data[1][0] = 0; ray1->origin->data[2][0] = -5; ray1->origin->data[3][0] = 1;
	ray1->direction->data[0][0] = 0; ray1->direction->data[1][0] = 0; ray1->direction->data[2][0] = 1; ray1->direction->data[3][0] = 0;
	inter = ray_intersect_sphere(curr, ray1);
	TEST_ASSERT_EQUAL(3, inter[0]->t_val);
	TEST_ASSERT_EQUAL(7, inter[1]->t_val);
	print_colored(green_back, "RAY SPHERE INTERSECTION - SPHERE SCALING - PASSED!");

	free_dptr((void **)inter); free_matrix(curr->obj.sphere.transform);

	curr->obj.sphere.transform = object_translation(5, 0, 0);

	inter = ray_intersect_sphere(curr, ray1);
	TEST_ASSERT_NULL(inter);
	print_colored(green_back, "RAY SPHERE INTERSECTION - SPHERE TRANSLATE - PASSED!");

	free_ray(ray1);
	free_object(curr);
}

// ************************************************************************** //
//                              ENTRY FUNCTION                                //
// ************************************************************************** //
void	intersection_test_ray_sphere(void)
{
	UNITY_BEGIN();
	print_colored(cyan_back, "-> INTERSECTION FEATURE <-");

	print_colored(bold, "TEST - RAY-SPHERE INTERSECT");
	RUN_TEST(ray_sphere_intersect);
	printf("\n");

	print_colored(bold, "TEST - RAY-SPHERE INTERSECT");
	RUN_TEST(transform_test_ray_sphere);
	printf("\n");

	UNITY_END();
}