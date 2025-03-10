/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:52:17 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/24 15:52:58 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"

/**
 * @brief This function creates a point in 3D space.
 * @param x [double] x coordinate of the point
 * @param y [double] y coordinate of the point
 * @param z [double] z coordinate of the point
 * @return t_matrix* returns a 4x1 matrix
 */
t_matrix	*create_point(double x, double y, double z)
{
	t_matrix	*point;

	point = matrix_create(4, 1);
	point->data[0][0] = x;
	point->data[1][0] = y;
	point->data[2][0] = z;
	point->data[3][0] = 1;
	return (point);
}
