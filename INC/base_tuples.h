/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_tuples.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:06:29 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/14 14:36:09 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_TUPLES_H
# define BASE_TUPLES_H

# include "types.h"

int			tuple_comp(t_tuple *tup1, t_tuple *tup2);
t_tuple		tuple_create(double x, double y, double z, int w);
t_tuple		*tuple_cross(t_tuple *tup1, t_tuple *tup2);
void		tuple_scalar_divide(t_tuple *a, double scalar);
double		tuple_dot(t_tuple *tuple1, t_tuple *tuple2, int flag);
double		tuple_length(t_tuple *vec1);
void		tuple_negating(t_tuple *a);
void		tuple_normalize(t_tuple *tuple);
void		tuple_scalar_mult(t_tuple *tuple, double scalar);
t_tuple		*tuple_sum_sub(t_tuple *tuple1, t_tuple *tuple2, char op);
t_matrix	*tuple_to_matrix(t_tuple *tuple);
int			tuple_type(t_tuple *tuple);

#endif
