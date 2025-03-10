/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:50:37 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/24 15:50:49 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"

/**
 * @brief This function is used to create a vector in 3D space.
 * @param x [double]
 * @param y [double]
 * @param z [double]
 * @return This function returns a `t_matrix` vector.
 */
t_matrix	*create_vector(double x, double y, double z)
{
	t_matrix	*point;

	point = matrix_create(4, 1);
	point->data[0][0] = x;
	point->data[1][0] = y;
	point->data[2][0] = z;
	point->data[3][0] = 0;
	return (point);
}
