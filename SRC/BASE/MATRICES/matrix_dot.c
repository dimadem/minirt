/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_dot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:47:25 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/18 14:01:33 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

/**
 * @brief Function that finds the dot (.) product of 2 vectors
 * @param FLAG used to indicate whether we want to find the product itself or
 * the angle between the vectors. `FLAG = 0` for the result of dot product and
 * `FLAG != 0` for the angle between 2 vectors in RADIAN!
 */
double	matrix_dot(t_matrix *mat1, t_matrix *mat2)
{
	double	product;

	if (mat1 == NULL || mat2 == NULL || \
		mat1->n != 4 || mat1->m != 1 || mat2->n != 4 || mat2->m != 1)
		return (0);
	product = mat1->data[0][0] * mat2->data[0][0] + \
				mat1->data[1][0] * mat2->data[1][0] + \
					mat1->data[2][0] * mat2->data[2][0];
	return (product);
}

	// double (*real_array1)[mat1->m] = mat1->data;

	// *real_array1[]