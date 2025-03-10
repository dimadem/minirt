/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_normalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:42:13 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/14 14:38:14 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_tuples.h"
#include "base_matrices.h"

/**
 * @brief This function converts the given vector into its normalized vector.
 * Normalize is used to convert the vector to a unit vector. Meaning, the length
 * of the given vector will be equal to 1 while still pointing in the same
 * direction.
 * @warning This function makes the passed parameter a unit vector. Therefore,
 * it does not return anything.
 */
void	tuple_normalize(t_tuple *tuple)
{
	double	len;

	len = tuple_length(tuple);
	if (len == 0)
		return ;
	tuple->x /= len;
	tuple->y /= len;
	tuple->z /= len;
}
