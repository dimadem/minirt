/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_dot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:42:41 by mcoskune          #+#    #+#             */
/*   Updated: 2024/12/28 20:46:58 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_tuples.h"
#include <math.h>

/**
 * @brief Function that finds the dot (.) product of 2 vectors
 * @param FLAG used to indicate whether we want to find the product itself or
 * the angle between the vectors. `FLAG = 0` for the result of dot product and
 * `FLAG != 0` for the angle between 2 vectors in RADIAN!
 * @warning ANGLE IS RETURNED IN RADIAN!
 */
double	tuple_dot(t_tuple *tup1, t_tuple *tup2, int flag)
{
	double	alpha;
	double	product;

	product = tup1->x * tup2->x + tup1->y * tup2->y + tup1->z * tup2->z;
	if (flag == 0)
		return (product);
	else
		alpha = acos(product / (tuple_length(tup1) * tuple_length(tup2)));
	return (alpha);
}
