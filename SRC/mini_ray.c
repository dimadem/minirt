/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:46:43 by mcoskune          #+#    #+#             */
/*   Updated: 2025/04/09 14:45:00 by mcoskune         ###   ########.fr       */
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
			printf("%.5f  ", mat->data[j][i]);
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
			printf("%.5f  ", tup->data[j][i]);
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

void	print_intersect(t_isect **isect, char *str)
{
	int	i = 0;

	if (isect == NULL)
		return ;
	printf(MAGENTA "Intersection Structure %s\n" RESET, str);
	while (isect[i] != NULL)
	{
		printf("iteration: %d  ", i);
		printf("t_val %.3f  ", isect[i]->t_val);
		printf("t_count %d  ", isect[i]->t_count);
		printf("obj_id %d  ", isect[i]->obj_id);
		printf("count %d\n", isect[i]->count);
		i++;
	}
}

void	print_material(t_mat *mat, char *str)
{
	printf(MAGENTA "Material Structure %s\n" RESET, str);
	print_color(&mat->colour, "Color of given Material");
	printf("Brightness Ratio %.3f  \n", mat->brightness_ratio);
	printf("Ambient %.5f  \n", mat->ambient);
	printf("Diffuse %.5f  \n", mat->diffuse);
	printf("Specular %.5f  \n", mat->specular);
	printf("Shininess %.5f  \n", mat->shininess);
}


int main()
{
	/** CHAPTER 1 - TUPLE TEST **/
	printf(RED "TUPLE TEST\n" RESET);
	{
		// printf(BLUE "TUPLE CREATE\n" RESET);
		// t_tuple tup1;
		// t_tuple	tup2;

		// tup1 = tuple_create(1, 2, 3, 1);
		// tup2 = tuple_create(1, 5, 1, 0);
		// print_tuple(&tup1, "TUPLE 1");
		// print_tuple(&tup2, "TUPLE 2");

		// printf(BLUE "TUPLE OPERATIONS\n" RESET);
		
		// t_tuple tup3 = tuple_sum(&tup1, &tup2);
		// print_tuple(&tup3, "TUPLE 3");
		// t_tuple	tup4 = tuple_sub(&tup1, &tup2);
		// print_tuple(&tup4, "TUPLE 4");
		// t_tuple	tup5 = tuple_scalar_mult(&tup1, 3);
		// print_tuple(&tup5, "TUPLE 5");

		// double magnitude = tuple_magnitude(&tup1);
		// printf("Len of tup1 is %.3f\n", magnitude);
		
		// t_tuple	tup6 = tuple_normalize(&tup1);
		// print_tuple(&tup6, "TUPLE 6");

		// double dot_res = tuple_dot(&tup1, &tup2);
		// printf("Dot product of tup1 and tup2 is %.3f\n", dot_res);

		// tup1 = tuple_create(1, 2, 3, 0);
		// tup2 = tuple_create(2, 3, 4, 0);
		// tup3 = tuple_cross(&tup1, &tup2);
		// print_tuple(&tup3, "TUPLE 3 CROSS PRODUCT");
		// tup3 = tuple_cross(&tup2, &tup1);
		// print_tuple(&tup3, "TUPLE 3 CROSS PRODUCT");
	}


	/** CHAPTER 2 - COLOR TEST **/
	printf(RED "COLOR TEST\n" RESET);
	{
		// printf(BLUE "COLOR CREATE\n" RESET);
		// t_trgb	color1;
		// t_trgb	color2;

		// color1 = colour_create(-0.5, 0.4, 1.7);
		// print_color(&color1, "color1");

		// printf(BLUE "COLOR OPERATIONS\n" RESET);
		// color1 = colour_create(0.9, 0.6, 0.75);
		// color2 = colour_create(0.7, 0.1, 0.25);
		// t_trgb color3 = colour_sum(color1, color2);
		// print_color(&color3, "color3");

		// color3 = colour_subs(color1, color2);
		// print_color(&color3, "color3");

		// color1 = colour_create(0.2, 0.3, 0.4);
		// color3 = colour_scalar_mult(color1, 2);
		// print_color(&color3, "color3");

		// color1 = colour_create(1, 0.2, 0.4);
		// color2 = colour_create(0.9, 1, 0.1);
		// color3 = colour_hadamard_product(color1, color2);
		// print_color(&color3, "color3");
	}


	/** CHAPTER 3 - MATRIX TEST **/
	printf(RED "MATRIX TEST\n" RESET);
	{
		// printf(BLUE "MATRIX CREATE\n" RESET);
		// t_matrix	mat1;
		// t_matrix	mat2;

		// mat1 = matrix_create(4, 4);
		// mat2 = matrix_create(4, 4);

		// mat1.data[0][0] = 1; mat1.data[0][1] = 2; mat1.data[0][2] = 3; mat1.data[0][3] = 4;
		// mat1.data[1][0] = 5.5; mat1.data[1][1] = 6.5; mat1.data[1][2] = 7.5; mat1.data[1][3] = 8.5;
		// mat1.data[2][0] = 9; mat1.data[2][1] = 10; mat1.data[2][2] = 11; mat1.data[2][3] = 12;
		// mat1.data[3][0] = 13.5; mat1.data[3][1] = 14.5; mat1.data[3][2] = 15.5; mat1.data[3][3] = 16.5;
		// mat2.data[0][0] = 1; mat2.data[0][1] = 2; mat2.data[0][2] = 3; mat2.data[0][3] = 4;
		// mat2.data[1][0] = 5.5; mat2.data[1][1] = 6.5; mat2.data[1][2] = 7.5; mat2.data[1][3] = 8.5;
		// mat2.data[2][0] = 9; mat2.data[2][1] = 10; mat2.data[2][2] = 11; mat2.data[2][3] = 12;
		// mat2.data[3][0] = 13.5; mat2.data[3][1] = 14.5; mat2.data[3][2] = 15.5; mat2.data[3][3] = 16.5;

		// print_matrix(&mat1, "MATRIX 1");
		// print_matrix(&mat2, "MATRIX 2");

		// printf(BLUE "MATRIX COMPARISON\n" RESET);
		// int comparison = matrix_compare(&mat1, &mat2);
		// printf("Result of Matrix Comparison: %d\n", comparison);


		// mat1.data[0][0] = 1; mat1.data[0][1] = 2; mat1.data[0][2] = 3; mat1.data[0][3] = 4;
		// mat1.data[1][0] = 5; mat1.data[1][1] = 6; mat1.data[1][2] = 7; mat1.data[1][3] = 8;
		// mat1.data[2][0] = 9; mat1.data[2][1] = 8; mat1.data[2][2] = 7; mat1.data[2][3] = 6;
		// mat1.data[3][0] = 5; mat1.data[3][1] = 4; mat1.data[3][2] = 3; mat1.data[3][3] = 2;

		// mat2.data[0][0] = -2; mat2.data[0][1] = 1; mat2.data[0][2] = 2; mat2.data[0][3] = 3;
		// mat2.data[1][0] = 3; mat2.data[1][1] = 2; mat2.data[1][2] = 1; mat2.data[1][3] = -1;
		// mat2.data[2][0] = 4; mat2.data[2][1] = 3; mat2.data[2][2] = 6; mat2.data[2][3] = 5;
		// mat2.data[3][0] = 1; mat2.data[3][1] = 2; mat2.data[3][2] = 7; mat2.data[3][3] = 8;

		// printf(BLUE "MATRIX MULTUPLICATION\n" RESET);
		// t_matrix	mat3 = matrix_multiple(&mat1, &mat2);
		// print_matrix(&mat3, "MATRIX 3");

		// mat1.data[0][0] = 1; mat1.data[0][1] = 2; mat1.data[0][2] = 3; mat1.data[0][3] = 4;
		// mat1.data[1][0] = 2; mat1.data[1][1] = 4; mat1.data[1][2] = 4; mat1.data[1][3] = 2;
		// mat1.data[2][0] = 8; mat1.data[2][1] = 6; mat1.data[2][2] = 4; mat1.data[2][3] = 1;
		// mat1.data[3][0] = 0; mat1.data[3][1] = 0; mat1.data[3][2] = 0; mat1.data[3][3] = 1;
		// t_tuple	tup1 = point_create(1, 2, 3);
		// t_tuple	tup2 = matrix_tuple_multiple(&mat1, &tup1);
		// print_tuple(&tup2, "TUP 2 - MATRIX TUPLE MULTIPLE");

		// mat2 = matrix_identity(4);
		// print_matrix(&mat2, "MATRIX IDENTITY");

		// mat2 = matrix_transpose(&mat1);
		// print_matrix(&mat2, "MATRIX TRANSPOSE");

		// double	determinant;
		// t_matrix	mat2x2= matrix_create(2, 2);
		// mat2x2.data[0][0] = 1; mat2x2.data[0][1] = 5;
		// mat2x2.data[1][0] = -3; mat2x2.data[1][1] = 2;
		// determinant = matrix_determinants(&mat2x2);
		// printf("Result of Matrix DETERMNANT: %f\n", determinant);

		// mat1.data[0][0] = -2; mat1.data[0][1] = -8; mat1.data[0][2] = 3; mat1.data[0][3] = 5;
		// mat1.data[1][0] = -3; mat1.data[1][1] = 1; mat1.data[1][2] = 7; mat1.data[1][3] = 3;
		// mat1.data[2][0] = 1; mat1.data[2][1] = 2; mat1.data[2][2] = -9; mat1.data[2][3] = 6;
		// mat1.data[3][0] = -6; mat1.data[3][1] = 7; mat1.data[3][2] = 7; mat1.data[3][3] = -9;
		// determinant = matrix_determinants(&mat1);
		// printf("Result of Matrix DETERMNANT: %f\n", determinant);

		// printf(BLUE "MATRIX INVERSION\n" RESET);
		// mat1.data[0][0] = -5; mat1.data[0][1] = 2; mat1.data[0][2] = 6; mat1.data[0][3] = -8;
		// mat1.data[1][0] = 1; mat1.data[1][1] = -5; mat1.data[1][2] = 1; mat1.data[1][3] = 8;
		// mat1.data[2][0] = 7; mat1.data[2][1] = 7; mat1.data[2][2] = -6; mat1.data[2][3] = -7;
		// mat1.data[3][0] = 1; mat1.data[3][1] = -3; mat1.data[3][2] = 7; mat1.data[3][3] = 4;
		// mat2 = matrix_inverse(&mat1);
		// print_matrix(&mat2, "MATRIX INVERSE (mat2)");
	}


	/** CHAPTER 4 - MATRIX TRANSFORMATIONS **/
	printf(RED "MATRIX TRANSFORMATION TEST\n" RESET);
	{
		// printf(BLUE "TRANSLATION\n" RESET);
		// t_matrix	mat1;
		// t_matrix	mat2;
		// t_tuple		tup1;
		// t_tuple		tup2;

		// mat1 = object_translation(5, -3, 2);
		// tup1 = point_create(-3, 4, 5);
		// tup2 = matrix_tuple_multiple(&mat1, &tup1);
		// print_tuple(&tup2, "TRANSLATED TUP2");
		// mat2 = matrix_inverse(&mat1);
		// tup2 = matrix_tuple_multiple(&mat2, &tup1);
		// print_tuple(&tup2, "INVERSE TRANSLATED TUP2");

		// tup1 = vector_create(-3, 4, 5);
		// tup2 = matrix_tuple_multiple(&mat1, &tup1);
		// print_tuple(&tup2, "TRANSLATED TUP2");

		// printf(BLUE "SCALING\n" RESET);
		// mat1 = object_scaling(2, 3, 4);
		// tup1 = point_create(-4, 6, 8);
		// tup2 = matrix_tuple_multiple(&mat1, &tup1);
		// print_tuple(&tup2, "SCALED TUP2 POINT");

		// tup1 = vector_create(-4, 6, 8);
		// tup2 = matrix_tuple_multiple(&mat1, &tup1);
		// print_tuple(&tup2, "SCALED TUP2 VECTOR");

		// mat2 = matrix_inverse(&mat1);
		// tup2 = matrix_tuple_multiple(&mat2, &tup1);
		// print_tuple(&tup2, "SCALED TUP2 INVERSE VECTOR");

		// mat1 = object_scaling(-1, 1, 1);
		// tup1 = point_create(2, 3, 4);
		// tup2 = matrix_tuple_multiple(&mat1, &tup1);
		// print_tuple(&tup2, "SCALED TUP2 VECTOR");

		// printf(BLUE "ROTATE AROUND X\n" RESET);
		// tup1 = point_create(0, 1, 0);
		// mat1 = rotation_x(M_PI / 4);
		// mat2 = matrix_inverse(&mat1);
		// tup2 = matrix_tuple_multiple(&mat2, &tup1);
		// print_tuple(&tup2, "ROTATED TUP2 INVERSE AROUND X");

		// mat1 = rotation_y(M_PI / 4);
		// tup1 = point_create(0, 0, 1);
		// tup2 = matrix_tuple_multiple(&mat1, &tup1);
		// print_tuple(&tup2, "ROTATED TUP2 AROUND Y pi/4");
		// mat1 = rotation_y(M_PI / 2);
		// tup2 = matrix_tuple_multiple(&mat1, &tup1);
		// print_tuple(&tup2, "ROTATED TUP2 AROUND Y pi/2");

		// mat1 = rotation_z(M_PI / 4);
		// tup1 = point_create(0, 1, 0);
		// tup2 = matrix_tuple_multiple(&mat1, &tup1);
		// print_tuple(&tup2, "ROTATED TUP2 AROUND Z pi/4");
		// mat1 = rotation_z(M_PI / 2);
		// tup2 = matrix_tuple_multiple(&mat1, &tup1);
		// print_tuple(&tup2, "ROTATED TUP2 AROUND Z pi/2");

		// printf(BLUE "SHEARING\n" RESET);
		// mat1 = shearing(64);
		// tup1 = point_create(2, 3, 4);
		// tup2 = matrix_tuple_multiple(&mat1, &tup1);
		// print_tuple(&tup2, "SHEAR X IN PROPORTION TO Y");

		// mat1 = shearing(32);
		// tup2 = matrix_tuple_multiple(&mat1, &tup1);
		// print_tuple(&tup2, "SHEAR X IN PROPORTION TO Z");

		// mat1 = shearing(16);
		// tup2 = matrix_tuple_multiple(&mat1, &tup1);
		// print_tuple(&tup2, "SHEAR Y IN PROPORTION TO X");

		// mat1 = shearing(8);
		// tup2 = matrix_tuple_multiple(&mat1, &tup1);
		// print_tuple(&tup2, "SHEAR Y IN PROPORTION TO Z");

		// mat1 = shearing(4);
		// tup2 = matrix_tuple_multiple(&mat1, &tup1);
		// print_tuple(&tup2, "SHEAR Z IN PROPORTION TO X");

		// mat1 = shearing(2);
		// tup2 = matrix_tuple_multiple(&mat1, &tup1);
		// print_tuple(&tup2, "SHEAR Z IN PROPORTION TO Y");

		// t_tuple		point = point_create(1, 0, 1);
		// t_matrix	rot = rotation_x(M_PI / 2);
		// t_matrix	scale = object_scaling(5, 5, 5);
		// t_matrix	transl = object_translation(10, 5, 7);

		// t_tuple	temp = matrix_tuple_multiple(&rot, &point);
		// temp = matrix_tuple_multiple(&scale, &temp);
		// temp = matrix_tuple_multiple(&transl, &temp);
		// print_tuple(&temp, "ALL TRANSFORM");
	}


	/** CHAPTER 5 - RAY SPHERE INTERSECTIONS **/
	printf(RED "RAY SPHERE INTERSECTIONS\n" RESET);
	{
		// printf(BLUE "CREATE RAY\n" RESET);

		// t_ray	ray1;

		// ray1.origin = point_create(2, 3, 4);
		// ray1.direction = vector_create(1, 0, 0);
		// print_ray(&ray1, "RAY1");

		// t_tuple pos = ray_position(ray1, 0);
		// print_tuple(&pos, "pos at t 0");
		// pos = ray_position(ray1, 1);
		// print_tuple(&pos, "pos at t 1");
		// pos = ray_position(ray1, -1);
		// print_tuple(&pos, "pos at t -1");
		// pos = ray_position(ray1, 2.5);
		// print_tuple(&pos, "pos at t 2.5");

		// t_object sph;
		// sph.type = SPHERE;
		// sph.obj.sphere.color = colour_create(1,1,1); sph.obj.sphere.origin = point_create(0,0,0); 
		// sph.obj.sphere.radius = 1; sph.obj.sphere.transform = matrix_identity(4);
		
		// ray1.origin = point_create(0, 0, -5);
		// ray1.direction = vector_create(0, 0, 1);

		// printf(BLUE "RAY SPHERE INTERSECTION\n" RESET);
		// /* TEST 1 - Intersecting at 2 points */
		// t_isect **inter = ray_intersect_sphere(&sph, &ray1);
		// print_intersect(inter, "intersect sphere");

		// free_dptr((void **)inter);

		// /* TEST 2 - Intersecting at 1 points */
		// ray1.origin = point_create(0, 1, -5);
		// ray1.direction = vector_create(0, 0, 1);
		// inter = ray_intersect_sphere(&sph, &ray1);
		// print_intersect(inter, "intersect sphere tangent");

		// free_dptr((void **)inter);

		// /* TEST 3 - Intersecting at 0 points */
		// ray1.origin = point_create(0, 2, -5);
		// ray1.direction = vector_create(0, 0, 1);
		// inter = ray_intersect_sphere(&sph, &ray1);
		// print_intersect(inter, "intersect sphere tangent");

		// free_dptr((void **)inter);

		// /* TEST 4 - Intersecting ray inside obj */
		// ray1.origin = point_create(0, 0, 0);
		// ray1.direction = vector_create(0, 0, 1);
		// inter = ray_intersect_sphere(&sph, &ray1);
		// print_intersect(inter, "intersect sphere tangent");

		// free_dptr((void **)inter);

		// /* TEST 5 - Intersecting obj behind ray */
		// ray1.origin = point_create(0, 0, 5);
		// ray1.direction = vector_create(0, 0, 1);
		// inter = ray_intersect_sphere(&sph, &ray1);
		// print_intersect(inter, "intersect sphere tangent");

		// free_dptr((void **)inter);

		// printf(BLUE "RAY TRANSFORM\n" RESET);
		// t_ray	ray2;
		// ray2.origin = point_create(1,2,3);
		// ray2.direction = vector_create(0,1,0);
		// t_matrix	m = object_translation(3,4,5);
		// ray2 = ray_transform(&ray2, &m);
		// print_ray(&ray2, "Transformed ray2");

		// ray2.origin = point_create(1,2,3);
		// ray2.direction = vector_create(0,1,0);
		// m = object_scaling(2,3,4);
		// ray2 = ray_transform(&ray2, &m);
		// print_ray(&ray2, "SCALED ray2");

		// printf(BLUE "SPHERE TRANSFORM\n" RESET);
		// ray2.origin = point_create(0,0,-5);
		// ray2.direction = vector_create(0,0,1);
		// sph.obj.sphere.transform = object_scaling(2,2,2);
		// inter = ray_intersect_sphere(&sph, &ray2);
		// print_intersect(inter, "intersect sphere scaled sphere");

		// free_dptr((void **)inter);

		// ray2.origin = point_create(0,0,-5);
		// ray2.direction = vector_create(0,0,1);
		// sph.obj.sphere.transform = object_translation(5,0,0);
		// inter = ray_intersect_sphere(&sph, &ray2);
		// printf(BLUE "SPHERE TRANSFOfffffffffRM\n" RESET);
		// print_intersect(inter, "intersect sphere translated sphere");

		// free_dptr((void **)inter);
	}


	/** CHAPTER 6 - LIGHT AND SHADING **/
	printf(RED "LIGHT AND SHADING\n" RESET);
	{
		// printf(BLUE "SPHERE NORMALS\n" RESET);
		// t_object	sph;

		// sph.type = SPHERE;
		// sph.obj.sphere.origin = point_create(0,0,0); sph.obj.sphere.transform = matrix_identity(4); sph.obj.sphere.radius = 1;
		
		// t_tuple		normal;
		// t_tuple		poi;

		// poi = point_create(1,0,0);
		// normal = sphere_normal(&sph, &poi);
		// print_tuple(&normal, "Normal vector at 1 0 0");

		// poi = point_create(0,1,0);
		// normal = sphere_normal(&sph, &poi);
		// print_tuple(&normal, "Normal vector at 0 1 0");

		// poi = point_create(0,0,1);
		// normal = sphere_normal(&sph, &poi);
		// print_tuple(&normal, "Normal vector at 0 0 1");

		// poi = point_create(sqrt(3)/3,sqrt(3)/3,sqrt(3)/3);
		// normal = sphere_normal(&sph, &poi);
		// print_tuple(&normal, "Normal vector at sqrt(3)/3's");

		// t_matrix	scale = object_scaling(1,0.5,1);
		// t_matrix	rotate = rotation_z(M_PI/5);
		// sph.obj.sphere.transform = matrix_multiple(&scale, &rotate);
		// poi = point_create(0, sqrt(2)/2, -sqrt(2)/2);
		// normal = sphere_normal(&sph, &poi);
		// print_tuple(&normal, "Normal vector on translated sphere");

		// printf(BLUE "REFLECTION VECTORS\n" RESET);

		// t_tuple	vector;
		// vector = vector_create(1,-1,0);
		// normal = vector_create(0,1,0);
		// t_tuple	vreflect;
		// vreflect = reflect(&vector, &normal);
		// print_tuple(&vreflect, "Reflecting at 45 deg");

		// vector = vector_create(0, -1, 0);
		// normal = vector_create(sqrt(2)/2,sqrt(2)/2,0);
		// vreflect = reflect(&vector, &normal);
		// print_tuple(&vreflect, "Reflecting off a slanted surface");


		// printf(BLUE "PHOOOOOOOOOOOONG!!!\n" RESET);

		// printf(BLUE "TEST 1 - PHOOOOOOOOOOOONG!!!\n" RESET);
		// t_light	light;
		// light.color = colour_create(1,1,1); light.origin = point_create(0,0,-10);
		// t_mat	material;
		// material.colour = colour_create(1,1,1); material.ambient = 0.1; material.diffuse = 0.9; material.specular = 0.9; material.shininess = 200;

		// t_tuple 	normal_v;
		// t_mat		result;
		// t_rayt		lux;
		// t_camera	cam;
		
		// sph.material = material;
		// sph.obj.sphere.origin = point_create(0,0,0);
		// sph.obj.sphere.transform = matrix_identity(4);
		// lux.camera = &cam;
		// lux.p_light = &light;
		// light.brightness_ratio = 1;
		// cam.origin = point_create(0,0,-1);
		// cam.v_orient = vector_create(0,0,1); //IN THE LIGHTING THIS IS TAKEN WRONG, put a simple fix for now

		// normal_v = vector_create(0,0,-1);
		// result = lighting(&lux, material, sph.obj.sphere.origin, normal_v);
		// print_material(&result, "First Test");

		// cam.v_orient = vector_create(0, -sqrt(2)/2, sqrt(2)/2);
		// result = lighting(&lux, material, sph.obj.sphere.origin, normal_v);
		// print_material(&result, "Second Test eye at 45 degree");

		// cam.v_orient = vector_create(0, 0, 1);
		// light.origin = point_create(0,10,-10);
		// result = lighting(&lux, material, sph.obj.sphere.origin, normal_v);
		// print_material(&result, "Third Test light at 45 degree");

		// cam.v_orient = vector_create(0, sqrt(2)/2, sqrt(2)/2);
		// result = lighting(&lux, material, sph.obj.sphere.origin, normal_v);
		// print_material(&result, "4th Test eye and light at 45 degree");

		// cam.v_orient = vector_create(0, 0, 1);
		// light.origin = point_create(0,0,10);
		// result = lighting(&lux, material, sph.obj.sphere.origin, normal_v);
		// print_material(&result, "5th Test Light Behind the Object");
	}
	

	/** CHAPTER 7 - MAKING THE SCENE **/
	printf(RED "MAKING THE SCENE\n" RESET);
	{
		printf(BLUE "BUILDING THE WORLD\n" RESET);
		t_rayt		lux;

		t_mat	material;
		material.colour = colour_create(1,1,1); material.ambient = 0.1; material.diffuse = 0.9; material.specular = 0.9; material.shininess = 200;

		t_light	light;
		light.color = colour_create(1,1,1); light.origin = point_create(-10,10,-10); light.brightness_ratio = 1;

		t_object	sph1;
		sph1.material = material;
		sph1.type = SPHERE; sph1.material.colour = colour_create(0.8, 1, 0.6);
		sph1.material.diffuse = 0.8; sph1.material.specular = 0.2;
		sph1.obj.sphere.origin = point_create(0,0,0);
		sph1.obj.sphere.transform = matrix_identity(4);

		t_object	sph2;
		sph2.type = SPHERE; sph2.material = material;
		sph2.obj.sphere.origin = point_create(0,0,0);
		sph2.obj.sphere.transform = object_scaling(0.5,0.5,0.5);

		t_camera	cam;
		cam.origin = point_create(0,0,-1);
		cam.v_orient = vector_create(0,0,1);

		lux.camera = &cam;
		lux.p_light = &light;
		lux.objects = NULL;
		add_to_dptr((void ***)&lux.objects, (void *)&sph1);
		add_to_dptr((void ***)&lux.objects, (void *)&sph2);

		t_ray	ray1;
		ray1.origin = point_create(0,0,-5); ray1.direction = vector_create(0,0,1);

		t_isect **inter;
		// inter = ray_intersect_sphere(&sph1, &ray1);
		inter = ray_intersect_world(&lux, &ray1);
		print_intersect(inter, "Ray1 Intersecting the World");

		free(lux.objects);
		free_dptr((void **)inter);
	}
}
