/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_scalarmult.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:40:50 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/03 21:02:32 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

/**
 * @brief Multiples a given tuple with a scalar value. This can be also used
 * to divide the tuple by a scalar. This does not change the orientation of the
 * vector, only its direction and/or its magnitude.
 * @warning This function modifies the passed tuple. Therefore, there is no
 * return type.
 */
void	tuple_scalar_mult(t_tuple *tuple, double scalar)
{
	if (tuple == NULL)
		return ;
	tuple->x *= scalar;
	tuple->y *= scalar;
	tuple->z *= scalar;
	tuple->w *= scalar;
}
