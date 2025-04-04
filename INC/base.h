/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:02:10 by mcoskune          #+#    #+#             */
/*   Updated: 2025/04/04 15:27:40 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

# include "types.h"

/* MATHS */
int			epsilon(double a, double b);

/* TUPLES */
t_tuple		tuple_sum(t_tuple *tuple1, t_tuple *tuple2);
t_tuple		tuple_sub(t_tuple *tuple1, t_tuple *tuple2);
t_tuple		tuple_scalar_mult(t_tuple *tuple, double scalar);
double		tuple_magnitude(t_tuple *tuple);
t_tuple		tuple_normalize(t_tuple *tuple);
double		tuple_dot(t_tuple *tup1, t_tuple *tup2);
t_tuple		tuple_create(double x, double y, double z, int w);
int			tuple_comp(t_tuple *tup1, t_tuple *tup2);

/* MATRIX */
t_matrix	matrix_sum(t_matrix *mat1, t_matrix *mat2);
t_matrix	matrix_sub(t_matrix *mat1, t_matrix *mat2);
t_matrix	matrix_scalar_mult(t_matrix *matrix, double scalar);
int			matrix_compare(t_matrix *mat1, t_matrix *mat2);
t_matrix	matrix_multiple(t_matrix *matrix1, t_matrix *matrix2);
t_tuple		matrix_tuple_multiple(t_matrix *matrix1, t_tuple *tup1);
t_matrix	matrix_transpose(t_matrix *matrix);
t_matrix	matrix_identity(int n);
t_matrix	matrix_create(int n, int m);
t_matrix	matrix_inverse(t_matrix *matrix);
t_matrix	matrix_clone(t_matrix *original);
double		matrix_determinants(t_matrix *matrix);


/* COLOURS */
t_trgb		colour_create(double red, double green, double blue);
t_trgb		colour_sum(t_trgb colour1, t_trgb colour2);
t_trgb		colour_subs(t_trgb colour1, t_trgb colour2);
t_trgb		colour_scalar_mult(t_trgb colour, double num);
t_trgb		colour_hadamard_product(t_trgb colour1, t_trgb colour2);

#endif