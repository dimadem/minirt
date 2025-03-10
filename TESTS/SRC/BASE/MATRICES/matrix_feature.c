/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_feature.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 01:56:26 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/03 12:16:11 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../LIB/Unity/src/unity.h"
#include "test.h"
#include "base_matrices.h"
#include <stdlib.h>

// ************************************************************************** //
//                              GLOBAL VARIABLE                               //
// ************************************************************************** //
static t_matrix	*mat1 = NULL;
static t_matrix	*mat2 = NULL;
static t_matrix	*mat3 = NULL;
static t_matrix	*mat4 = NULL;
static t_matrix	*mat5 = NULL;
static t_matrix	*mat_result = NULL;
static t_matrix	*mat_mult = NULL;
static t_matrix	*identity = NULL;

// ************************************************************************** //
//                               CREATE - INIT                                //
// ************************************************************************** //
void	matrix_test_create()
{
	mat1 = matrix_create(4, 4);
	mat1->data[0][0] = 1; mat1->data[0][1] = 2; mat1->data[0][2] = 3; mat1->data[0][3] = 2;
	mat1->data[1][0] = 4; mat1->data[1][1] = 5; mat1->data[1][2] = 6; mat1->data[1][3] = 9;
	mat1->data[2][0] = 7; mat1->data[2][1] = 8; mat1->data[2][2] = 0; mat1->data[2][3] = 9;
	mat1->data[3][0] = 7; mat1->data[3][1] = 8; mat1->data[3][2] = 9; mat1->data[3][3] = 9;

	TEST_ASSERT_NOT_EQUAL(NULL, mat1);
	TEST_ASSERT_EQUAL(2, mat1->data[0][1]);
	TEST_ASSERT_EQUAL(7, mat1->data[3][0]);
	TEST_ASSERT_EQUAL(0, mat1->data[2][2]);
	TEST_ASSERT_EQUAL(9, mat1->data[3][3]);
	print_colored(green_back, "Matrix - Create mat1 - Passed!");

	mat2 = matrix_create(4, 4);
	mat2->data[0][0] = 9; mat2->data[0][1] = 2; mat2->data[0][2] = 3; mat2->data[0][3] = 3;
	mat2->data[1][0] = 4; mat2->data[1][1] = 6; mat2->data[1][2] = 9; mat2->data[1][3] = 6;
	mat2->data[2][0] = 1; mat2->data[2][1] = 7; mat2->data[2][2] = 8; mat2->data[2][3] = 7;
	mat2->data[3][0] = 1; mat2->data[3][1] = 7; mat2->data[3][2] = 8; mat2->data[3][3] = 0;

	TEST_ASSERT_NOT_EQUAL(NULL, mat2);
	TEST_ASSERT_EQUAL(2, mat2->data[0][1]);
	TEST_ASSERT_EQUAL(1, mat2->data[3][0]);
	TEST_ASSERT_EQUAL(8, mat2->data[2][2]);
	TEST_ASSERT_EQUAL(0, mat2->data[3][3]);
	print_colored(green_back, "Matrix - Create mat2 - Passed!");
	
	mat3 = matrix_create(4, 1);
	mat3->data[0][0] = 4;
	mat3->data[1][0] = 6;
	mat3->data[2][0] = 8;
	mat3->data[3][0] = 0;
	TEST_ASSERT_NOT_EQUAL(NULL, mat2);
	TEST_ASSERT_EQUAL(4, mat3->data[0][0]);
	TEST_ASSERT_EQUAL(6, mat3->data[1][0]);
	TEST_ASSERT_EQUAL(8, mat3->data[2][0]);
	TEST_ASSERT_EQUAL(0, mat3->data[3][0]);
	print_colored(green_back, "Matrix - Create mat3 - Passed!");

	mat4 = matrix_create(4, 1);
	mat4->data[0][0] = 7;
	mat4->data[1][0] = 4;
	mat4->data[2][0] = 1;
	mat4->data[3][0] = 1;
	TEST_ASSERT_NOT_EQUAL(NULL, mat4);
	TEST_ASSERT_EQUAL(7, mat4->data[0][0]);
	TEST_ASSERT_EQUAL(4, mat4->data[1][0]);
	TEST_ASSERT_EQUAL(1, mat4->data[2][0]);
	TEST_ASSERT_EQUAL(1, mat4->data[3][0]);
	print_colored(green_back, "Matrix - Create mat4 - Passed!");

	mat5 = matrix_create(4, 1);
	mat5->data[0][0] = 7;
	mat5->data[1][0] = 4;
	mat5->data[2][0] = 1;
	mat5->data[3][0] = 1;
	TEST_ASSERT_NOT_EQUAL(NULL, mat5);
	TEST_ASSERT_EQUAL(7, mat5->data[0][0]);
	TEST_ASSERT_EQUAL(4, mat5->data[1][0]);
	TEST_ASSERT_EQUAL(1, mat5->data[2][0]);
	TEST_ASSERT_EQUAL(1, mat5->data[3][0]);
	print_colored(green_back, "Matrix - Create mat5 - Passed!");
}
// ************************************************************************** //
//                              MATRIX_COMPARE                                //
// ************************************************************************** //
void	matrix_test_compare()
{
	TEST_ASSERT_EQUAL(3, matrix_compare(mat1, mat2));
	print_colored(green_back, "Matrix - Compare mat1 & mat2 - Passed!");

	TEST_ASSERT_EQUAL(2, matrix_compare(mat1, mat3));
	print_colored(green_back, "Matrix - Compare mat1 & mat3 - Passed!");

	TEST_ASSERT_EQUAL(0, matrix_compare(mat4, mat5));
	print_colored(green_back, "Matrix - Compare mat4 & mat5 - Passed!");
}

// ************************************************************************** //
//                           MATRIX_MULTIPLICATION                            //
// ************************************************************************** //
void	matrix_test_multiplication()
{
	mat_result = matrix_create(4, 4);
	mat_result->data[0][0] = 22;  mat_result->data[0][1] = 49;  mat_result->data[0][2] = 61;  mat_result->data[0][3] = 36;
	mat_result->data[1][0] = 71; mat_result->data[1][1] = 143; mat_result->data[1][2] = 177; mat_result->data[1][3] = 84;
	mat_result->data[2][0] = 104; mat_result->data[2][1] = 125; mat_result->data[2][2] = 165; mat_result->data[2][3] = 69;
	mat_result->data[3][0] = 113; mat_result->data[3][1] = 188; mat_result->data[3][2] = 237; mat_result->data[3][3] = 132;

	mat_mult = matrix_multiple(mat1, mat2);
	TEST_ASSERT_EQUAL(0, matrix_compare(mat_result, mat_mult));
	print_colored(green_back, "Matrix - Multiply 1 & 2 - Passed!");

	free_matrix(mat_result);
	free_matrix(mat_mult);

	mat_result = matrix_create(4, 1);
	mat_result->data[0][0] = 20;
	mat_result->data[1][0] = 63;
	mat_result->data[2][0] = 90;
	mat_result->data[3][0] = 99;

	mat_mult = matrix_multiple(mat1, mat5);
	TEST_ASSERT_EQUAL(0, matrix_compare(mat_result, mat_mult));
	print_colored(green_back, "Matrix - Multiply 1 & 5 - Passed!");

	free_matrix(mat_result);
	free_matrix(mat_mult);

	identity = matrix_identity(4);
	mat_mult = matrix_multiple(mat1, identity);
	TEST_ASSERT_EQUAL(0, matrix_compare(mat1, mat_mult));
	print_colored(green_back, "Matrix - Multiply 1 & IDENTITY - Passed!");

	free_matrix(identity);
	free_matrix(mat_mult);
}

// ************************************************************************** //
//                             MATRIX_TRANSPOSE                               //
// ************************************************************************** //
void	matrix_test_transpose()
{
	int	i = 0;
	int	j = 0;

	mat_mult = matrix_transpose(mat1);
	while (j < mat1->n)
	{
		i = 0;
		while (i < mat1->m)
		{
			printf("Testing i: %d and j: %d\n", i, j);
			TEST_ASSERT_EQUAL(mat1->data[j][i], mat_mult->data[i][j]);
			i++;
		}
		j++;
	}
	print_colored(green_back, "Matrix - Transpose mat1 - Passed!");

	free_matrix(mat_mult);

	j = 0;
	mat_mult = matrix_transpose(mat5);
	while (j < mat5->n)
	{
		i = 0;
		while (i < mat5->m)
		{
			printf("Testing i: %d and j: %d\n", i, j);
			TEST_ASSERT_EQUAL(mat5->data[j][i], mat_mult->data[i][j]);
			i++;
		}
		j++;
	}
	print_colored(green_back, "Matrix - Transpose mat5 - Passed!");

	free_matrix(mat_mult);
}

void	matrix_test_determinant()
{
	TEST_ASSERT_EQUAL(-189, matrix_determinants(mat1));
	print_colored(green_back, "Matrix - Determinant mat1 - Passed!");

	TEST_ASSERT_EQUAL(805, matrix_determinants(mat2));
	print_colored(green_back, "Matrix - Determinant mat2 - Passed!");
}

// ************************************************************************** //
//                              MATRIX_INVERSE                                //
// ************************************************************************** //
void	matrix_test_inverse()
{
	mat_mult = matrix_inverse(mat1);
	mat_result = matrix_create(4, 4);
	mat_result->data[0][0] = -1.2857; mat_result->data[0][1] = -0.0952; mat_result->data[0][2] = -0.1111; mat_result->data[0][3] = 0.4921;
	mat_result->data[1][0] = 1.2857; mat_result->data[1][1] = -0.2381; mat_result->data[1][2] = 0.2222; mat_result->data[1][3] = -0.2698;
	mat_result->data[2][0] = 0; mat_result->data[2][1] = 0; mat_result->data[2][2] = -0.1111; mat_result->data[2][3] = 0.1111;
	mat_result->data[3][0] = -0.1429; mat_result->data[3][1] = 0.2857; mat_result->data[3][2] = 0; mat_result->data[3][3] = -0.1429;

	TEST_ASSERT_EQUAL(0, matrix_compare(mat_mult, mat_result));
	print_colored(green_back, "Matrix - Inverse mat1 - Passed!");
	free_matrix(mat_mult); 
	free_matrix(mat_result);

	mat_mult = matrix_inverse(mat2);
	mat_result = matrix_create(4, 4);
	mat_result->data[0][0] = 0.130435; mat_result->data[0][1] = -0.043478; mat_result->data[0][2] = -0.018634; mat_result->data[0][3] = 0.018634;
	mat_result->data[1][0] =  0.200000; mat_result->data[1][1] =  -0.600000; mat_result->data[1][2] = 0.428571; mat_result->data[1][3] = 0.171429;
	mat_result->data[2][0] =  -0.191304; mat_result->data[2][1] = 0.530435; mat_result->data[2][2] =  -0.372671; mat_result->data[2][3] = -0.027329;
	mat_result->data[3][0] = -0.000000; mat_result->data[3][1] = -0.000000; mat_result->data[3][2] = 0.142857; mat_result->data[3][3] = -0.142857;

	TEST_ASSERT_EQUAL(0, matrix_compare(mat_mult, mat_result));
	print_colored(green_back, "Matrix - Inverse mat2 - Passed!");
	free_matrix(mat_mult); 
	free_matrix(mat_result);
}

// ************************************************************************** //
//                               ENTRY FUNCTION                               //
// ************************************************************************** //
void	matrix_test_main(void)
{
	UNITY_BEGIN();
	print_colored(cyan_back, "-> MATRIX FEATURE <-");

	print_colored(bold, "TEST - MATRIX CREATE");
	RUN_TEST(matrix_test_create);
	printf("\n");

	print_colored(bold, "TEST - MATRIX COMPARE");
	RUN_TEST(matrix_test_compare);
	printf("\n");

	print_colored(bold, "TEST - MATRIX MULTIPLICATION");
	RUN_TEST(matrix_test_multiplication);
	printf("\n");

	print_colored(bold, "TEST - MATRIX TRANSPOSE");
	RUN_TEST(matrix_test_transpose);
	printf("\n");

	print_colored(bold, "TEST - MATRIX DETERMINANT");
	RUN_TEST(matrix_test_determinant);
	printf("\n");

	print_colored(bold, "TEST - MATRIX INVERSE");
	RUN_TEST(matrix_test_inverse);
	printf("\n");

	free_matrix(mat1); free_matrix(mat2); free_matrix(mat3); free_matrix(mat4); free_matrix(mat5);
	UNITY_END();

}