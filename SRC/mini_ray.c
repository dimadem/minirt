/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:46:43 by mcoskune          #+#    #+#             */
/*   Updated: 2025/04/07 17:31:12 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h> //remove this

// int	main(int ac, char **av)
// {
// 	t_rayt	lux;

// 	// input_validate(ac, av);
// 	// init_lux(&lux);
// 	// parse_rt_main(av, &lux);
// 	// init_mlx(&lux);
// 	// render_main(&lux);
// 	// exit_cleanup("Reached end of MAIN!\n", &lux, 0);
// }


void	print_matrix(t_matrix *mat, char *str)
{
	int i = 0;
	int	j = 0;

	printf(GREEN "Printing matrix %s\nn value: %d\nm value: %d\nPassed Matrix Elements:\n" RESET, str, mat->n, mat->m);
	while (j < mat->n)
	{
		i = 0;
		while (i < mat->m)
		{
			printf("%.3f  ", mat->data[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}

void	print_tuple(t_tuple *tup, char *str)
{
	int i = 0;
	int	j = 0;

	printf(GREEN "Printing tuple %s\nn value: %d\nm value: %d\nPassed Tuple Elements:\n" RESET, str, tup->n, tup->m);
	while (j < tup->n)
	{
		i = 0;
		while (i < tup->m)
		{
			printf("%.3f  ", tup->data[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}

void	print_ray(t_ray	*ray, char *str)
{
	printf(GREEN "Printing ray %s\n" RESET, str);
	print_tuple(&ray->origin, "RAY ORIGIN");
	print_tuple(&ray->direction, "RAY DIRECTION");
}

void	print_color(t_trgb *color, char *str)
{
	printf(GREEN "Printing color %s\n" RESET, str);
	// printf("T: %.3f\n", color->t);
	printf("R: %.3f\n", color->r);
	printf("G: %.3f\n", color->g);
	printf("B: %.3f\n", color->b);
}

int main()
{
	/** CHAPTER 1 - TUPLE TEST **/
	printf(RED "TUPLE TEST\n" RESET);
	{
		printf(BLUE "TUPLE CREATE\n" RESET);
		t_tuple tup1;
		t_tuple	tup2;

		tup1 = tuple_create(1, 2, 3, 1);
		tup2 = tuple_create(1, 5, 1, 0);
		print_tuple(&tup1, "TUPLE 1");
		print_tuple(&tup2, "TUPLE 2");

		printf(BLUE "TUPLE OPERATIONS\n" RESET);
		
		t_tuple tup3 = tuple_sum(&tup1, &tup2);
		print_tuple(&tup3, "TUPLE 3");
		t_tuple	tup4 = tuple_sub(&tup1, &tup2);
		print_tuple(&tup4, "TUPLE 4");
		t_tuple	tup5 = tuple_scalar_mult(&tup1, 3);
		print_tuple(&tup5, "TUPLE 5");

		double magnitude = tuple_magnitude(&tup1);
		printf("Len of tup1 is %.3f\n", magnitude);
		
		t_tuple	tup6 = tuple_normalize(&tup1);
		print_tuple(&tup6, "TUPLE 6");

		double dot_res = tuple_dot(&tup1, &tup2);
		printf("Dot product of tup1 and tup2 is %.3f\n", dot_res);

		tup1 = tuple_create(1, 2, 3, 0);
		tup2 = tuple_create(2, 3, 4, 0);
		tup3 = tuple_cross(&tup1, &tup2);
		print_tuple(&tup3, "TUPLE 3 CROSS PRODUCT");
		tup3 = tuple_cross(&tup2, &tup1);
		print_tuple(&tup3, "TUPLE 3 CROSS PRODUCT");
	}

	/** CHAPTER 2 - COLOR TEST **/
	printf(RED "COLOR TEST\n" RESET);
	{
		printf(BLUE "COLOR CREATE\n" RESET);
		t_trgb	color1;
		t_trgb	color2;

		color1 = colour_create(-0.5, 0.4, 1.7);
		print_color(&color1, "color1");

		printf(BLUE "COLOR OPERATIONS\n" RESET);
		color1 = colour_create(0.9, 0.6, 0.75);
		color2 = colour_create(0.7, 0.1, 0.25);
		t_trgb color3 = colour_sum(color1, color2);
		print_color(&color3, "color3");

		color3 = colour_subs(color1, color2);
		print_color(&color3, "color3");

		color1 = colour_create(0.2, 0.3, 0.4);
		color3 = colour_scalar_mult(color1, 2);
		print_color(&color3, "color3");

		color1 = colour_create(1, 0.2, 0.4);
		color2 = colour_create(0.9, 1, 0.1);
		color3 = colour_hadamard_product(color1, color2);
		print_color(&color3, "color3");
	}

	/** CHAPTER 3 - MATRIX TEST **/
	printf(RED "MATRIX TEST\n" RESET);
	{
		printf(BLUE "MATRIX CREATE\n" RESET);
		t_matrix	mat1;
		t_matrix	mat2;

		mat1 = matrix_create(4, 4);
		mat2 = matrix_create(4, 4);

		mat1.data[0][0] = 1; mat1.data[0][1] = 2; mat1.data[0][2] = 3; mat1.data[0][3] = 4;
		mat1.data[1][0] = 5.5; mat1.data[1][1] = 6.5; mat1.data[1][2] = 7.5; mat1.data[1][3] = 8.5;
		mat1.data[2][0] = 9; mat1.data[2][1] = 10; mat1.data[2][2] = 11; mat1.data[2][3] = 12;
		mat1.data[3][0] = 13.5; mat1.data[3][1] = 14.5; mat1.data[3][2] = 15.5; mat1.data[3][3] = 16.5;
		mat2.data[0][0] = 1; mat2.data[0][1] = 2; mat2.data[0][2] = 3; mat2.data[0][3] = 4;
		mat2.data[1][0] = 5.5; mat2.data[1][1] = 6.5; mat2.data[1][2] = 7.5; mat2.data[1][3] = 8.5;
		mat2.data[2][0] = 9; mat2.data[2][1] = 10; mat2.data[2][2] = 11; mat2.data[2][3] = 12;
		mat2.data[3][0] = 13.5; mat2.data[3][1] = 14.5; mat2.data[3][2] = 15.5; mat2.data[3][3] = 16.5;

		print_matrix(&mat1, "MATRIX 1");
		print_matrix(&mat2, "MATRIX 2");

		printf(BLUE "MATRIX COMPARISON\n" RESET);
		int comparison = matrix_compare(&mat1, &mat2);
		printf("Result of Matrix Comparison: %d\n", comparison);


		mat1.data[0][0] = 1; mat1.data[0][1] = 2; mat1.data[0][2] = 3; mat1.data[0][3] = 4;
		mat1.data[1][0] = 5; mat1.data[1][1] = 6; mat1.data[1][2] = 7; mat1.data[1][3] = 8;
		mat1.data[2][0] = 9; mat1.data[2][1] = 8; mat1.data[2][2] = 7; mat1.data[2][3] = 6;
		mat1.data[3][0] = 5; mat1.data[3][1] = 4; mat1.data[3][2] = 3; mat1.data[3][3] = 2;

		mat2.data[0][0] = -2; mat2.data[0][1] = 1; mat2.data[0][2] = 2; mat2.data[0][3] = 3;
		mat2.data[1][0] = 3; mat2.data[1][1] = 2; mat2.data[1][2] = 1; mat2.data[1][3] = -1;
		mat2.data[2][0] = 4; mat2.data[2][1] = 3; mat2.data[2][2] = 6; mat2.data[2][3] = 5;
		mat2.data[3][0] = 1; mat2.data[3][1] = 2; mat2.data[3][2] = 7; mat2.data[3][3] = 8;

		printf(BLUE "MATRIX MULTUPLICATION\n" RESET);
		t_matrix	mat3 = matrix_multiple(&mat1, &mat2);
		print_matrix(&mat3, "MATRIX 3");

		mat1.data[0][0] = 1; mat1.data[0][1] = 2; mat1.data[0][2] = 3; mat1.data[0][3] = 4;
		mat1.data[1][0] = 2; mat1.data[1][1] = 4; mat1.data[1][2] = 4; mat1.data[1][3] = 2;
		mat1.data[2][0] = 8; mat1.data[2][1] = 6; mat1.data[2][2] = 4; mat1.data[2][3] = 1;
		mat1.data[3][0] = 0; mat1.data[3][1] = 0; mat1.data[3][2] = 0; mat1.data[3][3] = 1;
		t_tuple	tup1 = point_create(1, 2, 3);
		t_tuple	tup2 = matrix_tuple_multiple(&mat1, &tup1);
		print_tuple(&tup2, "TUP 2 - MATRIX TUPLE MULTIPLE");

		mat2 = matrix_identity(4);
		print_matrix(&mat2, "MATRIX IDENTITY");

		mat2 = matrix_transpose(&mat1);
		print_matrix(&mat2, "MATRIX TRANSPOSE");

		double	determinant;
		t_matrix	mat2x2= matrix_create(2, 2);
		mat2x2.data[0][0] = 1; mat2x2.data[0][1] = 5;
		mat2x2.data[1][0] = -3; mat2x2.data[1][1] = 2;
		determinant = matrix_determinants(&mat2x2);
		printf("Result of Matrix DETERMNANT: %f\n", determinant);

		mat1.data[0][0] = -2; mat1.data[0][1] = -8; mat1.data[0][2] = 3; mat1.data[0][3] = 5;
		mat1.data[1][0] = -3; mat1.data[1][1] = 1; mat1.data[1][2] = 7; mat1.data[1][3] = 3;
		mat1.data[2][0] = 1; mat1.data[2][1] = 2; mat1.data[2][2] = -9; mat1.data[2][3] = 6;
		mat1.data[3][0] = -6; mat1.data[3][1] = 7; mat1.data[3][2] = 7; mat1.data[3][3] = -9;
		determinant = matrix_determinants(&mat1);
		printf("Result of Matrix DETERMNANT: %f\n", determinant);

		printf(BLUE "MATRIX INVERSION\n" RESET);
		mat1.data[0][0] = -5; mat1.data[0][1] = 2; mat1.data[0][2] = 6; mat1.data[0][3] = -8;
		mat1.data[1][0] = 1; mat1.data[1][1] = -5; mat1.data[1][2] = 1; mat1.data[1][3] = 8;
		mat1.data[2][0] = 7; mat1.data[2][1] = 7; mat1.data[2][2] = -6; mat1.data[2][3] = -7;
		mat1.data[3][0] = 1; mat1.data[3][1] = -3; mat1.data[3][2] = 7; mat1.data[3][3] = 4;
		mat2 = matrix_inverse(&mat1);
		print_matrix(&mat2, "MATRIX INVERSE (mat2)");
	}


	/** CHAPTER 4 - MATRIX TRANSFORMATIONS **/
	printf(RED "MATRIX TRANSFORMATION TEST\n" RESET);
	{
		printf(BLUE "TRANSLATION\n" RESET);
		t_matrix	mat1;
		t_matrix	mat2;
		t_tuple		tup1;
		t_tuple		tup2;

		mat1 = object_translation(5, -3, 2);
		tup1 = point_create(-3, 4, 5);
		tup2 = matrix_tuple_multiple(&mat1, &tup1);
		print_tuple(&tup2, "TRANSLATED TUP2");
		mat2 = matrix_inverse(&mat1);
		tup2 = matrix_tuple_multiple(&mat2, &tup1);
		print_tuple(&tup2, "INVERSE TRANSLATED TUP2");

		tup1 = vector_create(-3, 4, 5);
		tup2 = matrix_tuple_multiple(&mat1, &tup1);
		print_tuple(&tup2, "TRANSLATED TUP2");

		printf(BLUE "SCALING\n" RESET);
		mat1 = object_scaling(2, 3, 4);
		tup1 = point_create(-4, 6, 8);
		tup2 = matrix_tuple_multiple(&mat1, &tup1);
		print_tuple(&tup2, "SCALED TUP2 POINT");

		tup1 = vector_create(-4, 6, 8);
		tup2 = matrix_tuple_multiple(&mat1, &tup1);
		print_tuple(&tup2, "SCALED TUP2 VECTOR");

		mat2 = matrix_inverse(&mat1);
		tup2 = matrix_tuple_multiple(&mat2, &tup1);
		print_tuple(&tup2, "SCALED TUP2 INVERSE VECTOR");

		mat1 = object_scaling(-1, 1, 1);
		tup1 = point_create(2, 3, 4);
		tup2 = matrix_tuple_multiple(&mat1, &tup1);
		print_tuple(&tup2, "SCALED TUP2 VECTOR");

		printf(BLUE "ROTATE AROUND X\n" RESET);
		tup1 = point_create(0, 1, 0);
		mat1 = rotation_x(M_PI / 4);
		mat2 = matrix_inverse(&mat1);
		tup2 = matrix_tuple_multiple(&mat2, &tup1);
		print_tuple(&tup2, "ROTATED TUP2 INVERSE AROUND X");

		mat1 = rotation_y(M_PI / 4);
		tup1 = point_create(0, 0, 1);
		tup2 = matrix_tuple_multiple(&mat1, &tup1);
		print_tuple(&tup2, "ROTATED TUP2 AROUND Y pi/4");
		mat1 = rotation_y(M_PI / 2);
		tup2 = matrix_tuple_multiple(&mat1, &tup1);
		print_tuple(&tup2, "ROTATED TUP2 AROUND Y pi/2");

		mat1 = rotation_z(M_PI / 4);
		tup1 = point_create(0, 1, 0);
		tup2 = matrix_tuple_multiple(&mat1, &tup1);
		print_tuple(&tup2, "ROTATED TUP2 AROUND Z pi/4");
		mat1 = rotation_z(M_PI / 2);
		tup2 = matrix_tuple_multiple(&mat1, &tup1);
		print_tuple(&tup2, "ROTATED TUP2 AROUND Z pi/2");

		printf(BLUE "SHEARING\n" RESET);
		mat1 = shearing(64);
		tup1 = point_create(2, 3, 4);
		tup2 = matrix_tuple_multiple(&mat1, &tup1);
		print_tuple(&tup2, "SHEAR X IN PROPORTION TO Y");

		mat1 = shearing(32);
		tup2 = matrix_tuple_multiple(&mat1, &tup1);
		print_tuple(&tup2, "SHEAR X IN PROPORTION TO Z");

		mat1 = shearing(16);
		tup2 = matrix_tuple_multiple(&mat1, &tup1);
		print_tuple(&tup2, "SHEAR Y IN PROPORTION TO X");

		mat1 = shearing(8);
		tup2 = matrix_tuple_multiple(&mat1, &tup1);
		print_tuple(&tup2, "SHEAR Y IN PROPORTION TO Z");

		mat1 = shearing(4);
		tup2 = matrix_tuple_multiple(&mat1, &tup1);
		print_tuple(&tup2, "SHEAR Z IN PROPORTION TO X");

		mat1 = shearing(2);
		tup2 = matrix_tuple_multiple(&mat1, &tup1);
		print_tuple(&tup2, "SHEAR Z IN PROPORTION TO Y");

		t_tuple		point = point_create(1, 0, 1);
		t_matrix	rot = rotation_x(M_PI / 2);
		t_matrix	scale = object_scaling(5, 5, 5);
		t_matrix	transl = object_translation(10, 5, 7);

		t_tuple	temp = matrix_tuple_multiple(&rot, &point);
		temp = matrix_tuple_multiple(&scale, &temp);
		temp = matrix_tuple_multiple(&transl, &temp);
		print_tuple(&temp, "ALL TRANSFORM");
	}

	/** CHAPTER 5 - RAY SPHERE INTERSECTIONS **/
	printf(RED "RAY SPHERE INTERSECTIONS\n" RESET);
	{
		printf(BLUE "CREATE RAY\n" RESET);

		t_ray	ray1;

		ray1.origin = point_create(2, 3, 4);
		ray1.direction = vector_create(1, 0, 0);
		print_ray(&ray1, "RAY1");

		t_tuple pos = ray_position(ray1, 0);
		print_tuple(&pos, "pos at t 0");
		pos = ray_position(ray1, 1);
		print_tuple(&pos, "pos at t 1");
		pos = ray_position(ray1, -1);
		print_tuple(&pos, "pos at t -1");
		pos = ray_position(ray1, 2.5);
		print_tuple(&pos, "pos at t 2.5");
	}

	
}
