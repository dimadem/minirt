/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 01:52:56 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/14 14:08:10 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIB/Unity/src/unity.h"
#include "test.h"
#include "base_matrices.h"
#include "objects_transform.h"
#include "muk_lib.h"
#include <stdlib.h>

// ************************************************************************** //
//                              GLOBAL VARIABLE                               //
// ************************************************************************** //
static t_matrix	*mat1 = NULL;
static t_matrix	*mat2 = NULL;
static t_matrix	*mat3 = NULL;
static t_matrix	*mat4 = NULL;
static t_matrix	*mat_translate = NULL;

// ************************************************************************** //
//                             TRANSLATION TEST                               //
// ************************************************************************** //
void	matrix_test_translation()
{
	mat_translate = object_translation(5, -3, 2);
	mat1 = matrix_create(4, 1);
	mat1->data[0][0] = -3; mat1->data[1][0] = 4;  mat1->data[2][0] = 5; mat1->data[3][0] = 1;
	mat2 = matrix_multiple(mat_translate, mat1);
	
	TEST_ASSERT_EQUAL(2, mat2->data[0][0]);
	TEST_ASSERT_EQUAL(1, mat2->data[1][0]);
	TEST_ASSERT_EQUAL(7, mat2->data[2][0]);
	TEST_ASSERT_EQUAL(1, mat2->data[3][0]);
	print_colored(green_back, "Transform - Object Translation - Passed!");

	mat3 = matrix_inverse(mat_translate);
	mat4 = matrix_multiple(mat3, mat1);
	TEST_ASSERT_EQUAL(-8, mat4->data[0][0]);
	TEST_ASSERT_EQUAL(7, mat4->data[1][0]);
	TEST_ASSERT_EQUAL(3, mat4->data[2][0]);
	TEST_ASSERT_EQUAL(1, mat4->data[3][0]);
	print_colored(green_back, "Transform - Object Inverse Translation - Passed!");

	mat1->data[3][0] = 0;
	free_matrix(mat4);

	mat4 = matrix_multiple(mat_translate, mat1);
	TEST_ASSERT_EQUAL(0, matrix_compare(mat1, mat4));
	print_colored(green_back, "Transform - Object Translation w Vector - Passed!");

	free_matrix(mat_translate);
	free_matrix(mat1); free_matrix(mat2); free_matrix(mat3); free_matrix(mat4);
}

// ************************************************************************** //
//                               SCALING TEST                                 //
// ************************************************************************** //
void	matrix_test_scaling()
{
	mat_translate = object_scaling(2, 3, 4);
	mat1 = matrix_create(4, 1);
	mat1->data[0][0] = -4; mat1->data[1][0] = 6;  mat1->data[2][0] = 8; mat1->data[3][0] = 1;
	mat2 = matrix_multiple(mat_translate, mat1);
	
	TEST_ASSERT_EQUAL(-8, mat2->data[0][0]);
	TEST_ASSERT_EQUAL(18, mat2->data[1][0]);
	TEST_ASSERT_EQUAL(32, mat2->data[2][0]);
	TEST_ASSERT_EQUAL(1, mat2->data[3][0]);
	print_colored(green_back, "Transform - Object Scaling - Point - Passed!");

	mat3 = matrix_create(4, 1);
	mat3->data[0][0] = -4; mat3->data[1][0] = 6;  mat3->data[2][0] = 8; mat3->data[3][0] = 0;
	mat4 = matrix_multiple(mat_translate, mat3);
	
	TEST_ASSERT_EQUAL(-8, mat4->data[0][0]);
	TEST_ASSERT_EQUAL(18, mat4->data[1][0]);
	TEST_ASSERT_EQUAL(32, mat4->data[2][0]);
	TEST_ASSERT_EQUAL(0, mat4->data[3][0]);
	print_colored(green_back, "Transform - Object Scaling - Vector - Passed!");

	free_matrix(mat1); free_matrix(mat2);
	mat1 = matrix_inverse(mat_translate);
	mat2 = matrix_multiple(mat1, mat3);

	TEST_ASSERT_EQUAL(-2, mat2->data[0][0]);
	TEST_ASSERT_EQUAL(2, mat2->data[1][0]);
	TEST_ASSERT_EQUAL(2, mat2->data[2][0]);
	TEST_ASSERT_EQUAL(0, mat2->data[3][0]);
	print_colored(green_back, "Transform - Object Inverse Scaling - Vector - Passed!");

	free_matrix(mat1); free_matrix(mat2); free_matrix(mat_translate);
	mat_translate = object_scaling(-1, 1, 1);
	mat1 = matrix_create(4, 1);
	mat1->data[0][0] = 2; mat1->data[1][0] = 3;  mat1->data[2][0] = 4; mat1->data[3][0] = 1;
	mat2 = matrix_multiple(mat_translate, mat1);

	TEST_ASSERT_EQUAL(-2, mat2->data[0][0]);
	TEST_ASSERT_EQUAL(3, mat2->data[1][0]);
	TEST_ASSERT_EQUAL(4, mat2->data[2][0]);
	TEST_ASSERT_EQUAL(1, mat2->data[3][0]);
	print_colored(green_back, "Transform - Object Scaling - Reflection - Passed!");

	free_matrix(mat_translate);
	free_matrix(mat1); free_matrix(mat2); free_matrix(mat3); free_matrix(mat4);
}

// ************************************************************************** //
//                              ROTATING TEST                                 //
// ************************************************************************** //
void	matrix_test_rotating()
{
	/****** Around X Axis ******/
	mat_translate = rotation_x(M_PI / 4);
	mat1 = matrix_create(4, 1);
	mat1->data[0][0] = 0; mat1->data[1][0] = 1;  mat1->data[2][0] = 0; mat1->data[3][0] = 1;
	mat2 = matrix_multiple(mat_translate, mat1);
	
	TEST_ASSERT_EQUAL(0, mat2->data[0][0]);
	TEST_ASSERT_EQUAL(sqrt(2)/2, mat2->data[1][0]);
	TEST_ASSERT_EQUAL(sqrt(2)/2, mat2->data[2][0]);
	TEST_ASSERT_EQUAL(1, mat2->data[3][0]);
	print_colored(green_back, "Transform - Rotate X - pi/4 - Passed!");

	free_matrix(mat_translate); free_matrix(mat1); free_matrix(mat2);

	mat_translate = rotation_x(M_PI / 2);
	mat1 = matrix_create(4, 1);
	mat1->data[0][0] = 0; mat1->data[1][0] = 1;  mat1->data[2][0] = 0; mat1->data[3][0] = 1;
	mat2 = matrix_multiple(mat_translate, mat1);

	TEST_ASSERT_EQUAL(0, mat2->data[0][0]);
	TEST_ASSERT_EQUAL(0, mat2->data[1][0]);
	TEST_ASSERT_EQUAL(1, mat2->data[2][0]);
	TEST_ASSERT_EQUAL(1, mat2->data[3][0]);
	print_colored(green_back, "Transform - Rotate X - pi/2 - Passed!");

	free_matrix(mat_translate); free_matrix(mat1); free_matrix(mat2);
	mat_translate = rotation_x(M_PI / 4);
	mat1 = matrix_create(4, 1);
	mat1->data[0][0] = 0; mat1->data[1][0] = 1;  mat1->data[2][0] = 0; mat1->data[3][0] = 1;
	mat2 = matrix_inverse(mat_translate);
	mat3 = matrix_multiple(mat2, mat1);
	
	TEST_ASSERT_EQUAL(0, mat3->data[0][0]);
	TEST_ASSERT_EQUAL(sqrt(2)/2, mat3->data[1][0]);
	TEST_ASSERT_EQUAL(-sqrt(2)/2, mat3->data[2][0]);
	TEST_ASSERT_EQUAL(1, mat3->data[3][0]);
	print_colored(green_back, "Transform - Rotate X - Inverse pi/2 - Passed!");

	free_matrix(mat_translate); free_matrix(mat1); free_matrix(mat2); free_matrix(mat3);
	
	/****** Around Y Axis ******/
	mat_translate = rotation_y(M_PI / 4);
	mat1 = matrix_create(4, 1);
	mat1->data[0][0] = 0; mat1->data[1][0] = 0;  mat1->data[2][0] = 1; mat1->data[3][0] = 1;
	mat2 = matrix_multiple(mat_translate, mat1);
	
	TEST_ASSERT_EQUAL(sqrt(2)/2, mat2->data[0][0]);
	TEST_ASSERT_EQUAL(0, mat2->data[1][0]);
	TEST_ASSERT_EQUAL(sqrt(2)/2, mat2->data[2][0]);
	TEST_ASSERT_EQUAL(1, mat2->data[3][0]);
	print_colored(green_back, "Transform - Rotate Y - pi/4 - Passed!");

	free_matrix(mat_translate); free_matrix(mat1); free_matrix(mat2);

	mat_translate = rotation_y(M_PI / 2);
	mat1 = matrix_create(4, 1);
	mat1->data[0][0] = 0; mat1->data[1][0] = 0;  mat1->data[2][0] = 1; mat1->data[3][0] = 1;
	mat2 = matrix_multiple(mat_translate, mat1);

	TEST_ASSERT_EQUAL(1, mat2->data[0][0]);
	TEST_ASSERT_EQUAL(0, mat2->data[1][0]);
	TEST_ASSERT_EQUAL(0, mat2->data[2][0]);
	TEST_ASSERT_EQUAL(1, mat2->data[3][0]);
	print_colored(green_back, "Transform - Rotate Y - pi/2 - Passed!");

	free_matrix(mat_translate); free_matrix(mat1); free_matrix(mat2);

	/****** Around Z Axis ******/
	mat_translate = rotation_z(M_PI / 4);
	mat1 = matrix_create(4, 1);
	mat1->data[0][0] = 0; mat1->data[1][0] = 1;  mat1->data[2][0] = 0; mat1->data[3][0] = 1;
	mat2 = matrix_multiple(mat_translate, mat1);
	
	TEST_ASSERT_EQUAL(-sqrt(2)/2, mat2->data[0][0]);
	TEST_ASSERT_EQUAL(sqrt(2)/2, mat2->data[1][0]);
	TEST_ASSERT_EQUAL(0, mat2->data[2][0]);
	TEST_ASSERT_EQUAL(1, mat2->data[3][0]);
	print_colored(green_back, "Transform - Rotate Z - pi/4 - Passed!");

	free_matrix(mat_translate); free_matrix(mat1); free_matrix(mat2);

	mat_translate = rotation_z(M_PI / 2);
	mat1 = matrix_create(4, 1);
	mat1->data[0][0] = 0; mat1->data[1][0] = 1;  mat1->data[2][0] = 0; mat1->data[3][0] = 1;
	mat2 = matrix_multiple(mat_translate, mat1);

	TEST_ASSERT_EQUAL(-1, mat2->data[0][0]);
	TEST_ASSERT_EQUAL(0, mat2->data[1][0]);
	TEST_ASSERT_EQUAL(0, mat2->data[2][0]);
	TEST_ASSERT_EQUAL(1, mat2->data[3][0]);
	print_colored(green_back, "Transform - Rotate Z - pi/2 - Passed!");

	free_matrix(mat_translate); free_matrix(mat1); free_matrix(mat2);
}

// ************************************************************************** //
//                              SHEARING TEST                                 //
// ************************************************************************** //
void	matrix_test_shearing()
{
	mat_translate = shearing(64);
	mat1 = matrix_create(4, 1);
	mat1->data[0][0] = 2; mat1->data[1][0] = 3;  mat1->data[2][0] = 4; mat1->data[3][0] = 1;
	mat2 = matrix_multiple(mat_translate, mat1);

	TEST_ASSERT_EQUAL(5, mat2->data[0][0]);
	TEST_ASSERT_EQUAL(3, mat2->data[1][0]);
	TEST_ASSERT_EQUAL(4, mat2->data[2][0]);
	TEST_ASSERT_EQUAL(1, mat2->data[3][0]);
	print_colored(green_back, "Transform - Shear X ipo Y - Passed!");

	free_matrix(mat_translate); free_matrix(mat1); free_matrix(mat2);
}

// ************************************************************************** //
//                              ENTRY FUNCTION                                //
// ************************************************************************** //
void	matrix_test_transform_main(void)
{
	UNITY_BEGIN();
	print_colored(cyan_back, "-> MATRIX TRANSFORMATIONS FEATURE <-");

	print_colored(bold, "TEST - MATRIX TRANSLATION");
	RUN_TEST(matrix_test_translation);
	printf("\n");

	print_colored(bold, "TEST - MATRIX SCALING");
	RUN_TEST(matrix_test_scaling);
	printf("\n");

	print_colored(bold, "TEST - MATRIX ROTATING");
	RUN_TEST(matrix_test_rotating);
	printf("\n");

	print_colored(bold, "TEST - MATRIX ROTATING");
	RUN_TEST(matrix_test_shearing);
	printf("\n");
	UNITY_END();
}