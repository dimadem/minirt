/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_compare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:14:56 by mcoskune          #+#    #+#             */
/*   Updated: 2024/12/12 11:39:40 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "base_helpers.h"

/**
 * @brief Function comparing equivalancy of 2 tuples using user defined Macro.
 * This macro is implemented to avoid errors caused by rounding doubles.
 * @return If tuples are same, function returns 0, otherwise, returns a positive
 * integer.
 */
int	tuple_comp(t_tuple *tup1, t_tuple *tup2)
{
	if (tup1 == NULL || tup2 == NULL)
		return (1);
	if (!(epsilon(tup1->x, tup2->x)))
		return (2);
	else if (!(epsilon(tup1->y, tup2->y)))
		return (3);
	else if (!(epsilon(tup1->z, tup2->z)))
		return (4);
	else if (!(epsilon(tup1->w, tup2->w)))
		return (5);
	return (0);
}
