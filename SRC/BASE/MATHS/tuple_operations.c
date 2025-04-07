/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:05:34 by mcoskune          #+#    #+#             */
/*   Updated: 2025/04/07 15:16:36 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	tuple_comp(t_tuple *tup1, t_tuple *tup2)
{
	if (tup1 == NULL || tup2 == NULL)
		return (1);
	if (!(epsilon(tup1->data[0][0], tup2->data[0][0])))
		return (2);
	else if (!(epsilon(tup1->data[1][0], tup2->data[1][0])))
		return (3);
	else if (!(epsilon(tup1->data[2][0], tup2->data[2][0])))
		return (4);
	else if (!(epsilon(tup1->data[3][0], tup2->data[3][0])))
		return (5);
	return (0);
}

t_tuple	vector_create(double x, double y, double z)
{
	t_tuple	a;

	a.n = 4;
	a.m = 1;
	a.data[0][0] = x;
	a.data[1][0] = y;
	a.data[2][0] = z;
	a.data[3][0] = 0;
	return (a);
}

t_tuple	point_create(double x, double y, double z)
{
	t_tuple	a;

	a.n = 4;
	a.m = 1;
	a.data[0][0] = x;
	a.data[1][0] = y;
	a.data[2][0] = z;
	a.data[3][0] = 1;
	return (a);
}

t_tuple	tuple_create(double x, double y, double z, int w)
{
	t_tuple	a;

	a.n = 4;
	a.m = 1;
	a.data[0][0] = x;
	a.data[1][0] = y;
	a.data[2][0] = z;
	a.data[3][0] = w;
	return (a);
}

t_tuple	tuple_cross(t_tuple *tup1, t_tuple *tup2)
{
	t_tuple	result;

	result.n = 4;
	result.m = 1;
	result.data[0][0] = tup1->data[1][0] * tup2->data[2][0] \
						- tup1->data[2][0] * tup2->data[1][0];
	result.data[1][0] = tup1->data[2][0] * tup2->data[0][0] \
						- tup1->data[0][0] * tup2->data[2][0];
	result.data[2][0] = tup1->data[0][0] * tup2->data[1][0] \
						- tup1->data[1][0] * tup2->data[0][0];
	result.data[3][0] = 0;
	return (result);
}

double	tuple_dot(t_tuple *tup1, t_tuple *tup2)
{
	return (tup1->data[0][0] * tup2->data[0][0] \
			+ tup1->data[1][0]* tup2->data[1][0] \
				+ tup1->data[2][0] * tup2->data[2][0] \
					+ tup1->data[3][0] * tup2->data[3][0]);
}


t_tuple	tuple_normalize(t_tuple *tuple)
{
	double	len;
	t_tuple	result;

	len = tuple_magnitude(tuple);
	result.n = 4;
	result.m = 1;
	if (len != 0)
	{
		result.data[0][0] = tuple->data[0][0] / len;
		result.data[1][0] = tuple->data[1][0] / len;
		result.data[2][0] = tuple->data[2][0] / len;
		result.data[3][0] = tuple->data[3][0] / len;
	}
	else
	{
		result.data[0][0] = 0;
		result.data[1][0] = 0;
		result.data[2][0] = 0;
		result.data[3][0] = 0;
	}
	return (result);
}

double	tuple_magnitude(t_tuple *tuple)
{
	return (sqrt(pow(tuple->data[0][0], 2) \
				+ pow(tuple->data[1][0], 2) \
					+ pow(tuple->data[2][0], 2)
						+ pow(tuple->data[3][0], 2)));
}

t_tuple	tuple_scalar_mult(t_tuple *tuple, double scalar)
{
	t_tuple	result;

	result.n = 4;
	result.m = 1;
	result.data[0][0] = tuple->data[0][0] * scalar;
	result.data[1][0] = tuple->data[1][0] * scalar;
	result.data[2][0] = tuple->data[2][0] * scalar;
	result.data[3][0] = tuple->data[3][0] * scalar;
	return (result);
}

t_tuple	tuple_sub(t_tuple *tuple1, t_tuple *tuple2)
{
	t_tuple	result;

	result.n = 4;
	result.m = 1;
	result.data[0][0] = tuple1->data[0][0] - tuple2->data[0][0];
	result.data[1][0] = tuple1->data[1][0] - tuple2->data[1][0];
	result.data[2][0] = tuple1->data[2][0] - tuple2->data[2][0];
	result.data[3][0] = tuple1->data[3][0] - tuple2->data[3][0];
	return (result);
}

t_tuple	tuple_sum(t_tuple *tuple1, t_tuple *tuple2)
{
	t_tuple	result;

	result.n = 4;
	result.m = 1;
	result.data[0][0] = tuple1->data[0][0] + tuple2->data[0][0];
	result.data[1][0] = tuple1->data[1][0] + tuple2->data[1][0];
	result.data[2][0] = tuple1->data[2][0] + tuple2->data[2][0];
	result.data[3][0] = tuple1->data[3][0] + tuple2->data[3][0];
	return (result);
}
