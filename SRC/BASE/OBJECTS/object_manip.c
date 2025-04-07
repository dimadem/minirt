/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:57:39 by mcoskune          #+#    #+#             */
/*   Updated: 2025/04/07 12:06:05 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function is used to shear given objects.
 * @param type is using int to determine which deformations are allowed. This
 * implementation uses bitwise operations to determine if its more than 1.
 * `x in proportion to y` `type == 64`,
 * `x in proportion to z` `type == 32`,
 * `y in proportion to x` `type == 16`,
 * `y in proportion to z` `type == 8`,
 * `z in proportion to x` `type == 4`,
 * `z in proportion to y` `type == 2`.
 * In order to calculate type, sum the required type ints.
 * @return This function will return you the shearing matrix which is an
 * identity matrix with modified data depending on type value.
 */
t_matrix	shearing(int type)
{
	t_matrix	result;

	result = matrix_identity(4);
	if (type >> 6 & 1)
		result.data[0][1] = 1;
	if (type >> 5 & 1)
		result.data[0][2] = 1;
	if (type >> 4 & 1)
		result.data[1][0] = 1;
	if (type >> 3 & 1)
		result.data[1][2] = 1;
	if (type >> 2 & 1)
		result.data[2][0] = 1;
	if (type >> 1 & 1)
		result.data[2][1] = 1;
	return (result);
}

t_matrix	rotation_z(double radian)
{
	t_matrix	result;

	result = matrix_identity(4);
	result.data[0][0] = cos(radian);
	result.data[0][1] = -sin(radian);
	result.data[1][0] = sin(radian);
	result.data[1][1] = cos(radian);
	return (result);
}

t_matrix	rotation_y(double radian)
{
	t_matrix	result;

	result = matrix_identity(4);
	result.data[0][0] = cos(radian);
	result.data[0][2] = sin(radian);
	result.data[2][0] = -sin(radian);
	result.data[2][2] = cos(radian);
	return (result);
}

t_matrix	rotation_x(double radian)
{
	t_matrix	result;

	result = matrix_identity(4);
	result.data[1][1] = cos(radian);
	result.data[1][2] = -sin(radian);
	result.data[2][1] = sin(radian);
	result.data[2][2] = cos(radian);
	return (result);
}

t_matrix	object_scaling(double x, double y, double z)
{
	t_matrix	scale;

	scale = matrix_identity(4);
	scale.data[0][0] = x;
	scale.data[1][1] = y;
	scale.data[2][2] = z;
	return (scale);
}

t_matrix	object_translation(double x, double y, double z)
{
	t_matrix	translate;

	translate = matrix_identity(4);
	translate.data[0][3] = x;
	translate.data[1][3] = y;
	translate.data[2][3] = z;
	return (translate);
}