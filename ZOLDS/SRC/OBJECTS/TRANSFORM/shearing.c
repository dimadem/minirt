/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:09:09 by mcoskune          #+#    #+#             */
/*   Updated: 2024/12/30 19:10:23 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"

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
t_matrix	*shearing(int type)
{
	t_matrix	*result;

	result = matrix_identity(4);
	if (type >> 6 & 1)
		result->data[0][1] = 1;
	if (type >> 5 & 1)
		result->data[0][2] = 1;
	if (type >> 4 & 1)
		result->data[1][0] = 1;
	if (type >> 3 & 1)
		result->data[1][2] = 1;
	if (type >> 2 & 1)
		result->data[2][0] = 1;
	if (type >> 1 & 1)
		result->data[2][1] = 1;
	return (result);
}
