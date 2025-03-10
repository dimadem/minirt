/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:33:46 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/16 00:30:04 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"
#include <math.h>

/**
 * @brief Creates a 4x4 rotation matrix around the Z axis (vertical)
 * @param radian The rotation angle in radians
 * @return A new 4x4 matrix representing Z-axis rotation
 * @details Rotation is counter clockwise when looking down the Z axis
 * (from top view)
 * 		The matrix follow the right-hand coordinate system where Z points up
 */
t_matrix	*rotation_z(double radian)
{
	t_matrix	*result;

	result = matrix_identity(4);
	result->data[0][0] = cos(radian);
	result->data[0][1] = -sin(radian);
	result->data[1][0] = sin(radian);
	result->data[1][1] = cos(radian);
	return (result);
}

/**
 * @brief Creates a 4x4 rotation matrix around the Y axis (front/back)
 * @param radian The rotation angle in radians
 * @return A new 4x4 matrix representing Y-axis rotation
 * @details Rotation is counter clockwise when looking down the Y axis
 * (from front view)
 * 		The matrix follow the right-hand coordinate system where Z points up
 */
t_matrix	*rotation_y(double radian)
{
	t_matrix	*result;

	result = matrix_identity(4);
	result->data[0][0] = cos(radian);
	result->data[0][2] = sin(radian);
	result->data[2][0] = -sin(radian);
	result->data[2][2] = cos(radian);
	return (result);
}

/**
 * @brief Creates a 4x4 rotation matrix around the X axis (left/right)
 * @param radian The rotation angle in radians
 * @return A new 4x4 matrix representing X-axis rotation
 * @details Rotation is counter clockwise when looking down the X axis
 * (from right view)
 * 		The matrix follow the right-hand coordinate system where Z points up
 */
t_matrix	*rotation_x(double radian)
{
	t_matrix	*result;

	result = matrix_identity(4);
	result->data[1][1] = cos(radian);
	result->data[1][2] = -sin(radian);
	result->data[2][1] = sin(radian);
	result->data[2][2] = cos(radian);
	return (result);
}
