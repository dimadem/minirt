/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_sum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:11:03 by mcoskune          #+#    #+#             */
/*   Updated: 2024/12/23 17:55:00 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_tuples.h"
#include "muk_lib.h"

static void	tuple_sub(t_tuple *tuple1, t_tuple *tuple2, t_tuple *result)
{
	result->x = tuple1->x - tuple2->x;
	result->y = tuple1->y - tuple2->y;
	result->z = tuple1->z - tuple2->z;
	result->w = tuple1->w - tuple2->w;
}

static void	tuple_sum(t_tuple *tuple1, t_tuple *tuple2, t_tuple *result)
{
	result->x = tuple1->x + tuple2->x;
	result->y = tuple1->y + tuple2->y;
	result->z = tuple1->z + tuple2->z;
	result->w = tuple1->w + tuple2->w;
}

/**
 * @brief This function is used to `sum` or `substract` 2 tuples.
 * @param op takes a single char of either `+` or `-` to determine the
 * operation.
 * @warning This function returns a malloced memory!
 * @warning This function does not check the value of `w`. For instance, if a
 * calculation requests `vector - point` this will result in `w = -1` which
 * has no meaning!
 * @return A malloced memory of `t_tuple` after calculation or NULL in failure
 */
t_tuple	*tuple_sum_sub(t_tuple *tuple1, t_tuple *tuple2, char op)
{
	t_tuple	*result;

	result = safe_malloc(sizeof(t_tuple), 1);
	if (result == NULL)
		return (NULL);
	if (op == '+')
		tuple_sum(tuple1, tuple2, result);
	else if (op == '-')
		tuple_sub(tuple1, tuple2, result);
	else
	{
		free(result);
		return (NULL);
	}
	return (result);
}
