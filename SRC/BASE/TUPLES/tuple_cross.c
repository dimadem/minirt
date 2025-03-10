/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_cross.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:17:12 by mcoskune          #+#    #+#             */
/*   Updated: 2024/12/12 11:39:38 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "muk_lib.h"

/**
 * @brief This function find the cross product of 2 vectors (tup1 x tup2).
 * This is used to find a vertical vector to passed vectors.
 * @warning This function returns a `malloc` memory that needs to be freed.
 */
t_tuple	*tuple_cross(t_tuple *tup1, t_tuple *tup2)
{
	t_tuple	*result;

	if (tup1->w == 1 || tup2->w == 1)
		return (errmsg("Error - tuple_cross - non-vector given"), NULL);
	result = safe_malloc(sizeof(t_tuple), 1);
	if (result == NULL)
		return (NULL);
	result->x = tup1->y * tup2->z - tup1->z * tup2->y;
	result->y = tup1->z * tup2->x - tup1->x * tup2->z;
	result->z = tup1->x * tup2->y - tup1->y * tup2->x;
	result->w = 0;
	return (result);
}
