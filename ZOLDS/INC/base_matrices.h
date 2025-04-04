/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_matrices.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:06:26 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/24 15:27:23 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_MATRICES_H
# define BASE_MATRICES_H

# include "types.h"

void		free_matrix(t_matrix *mat);
t_matrix	*matrix_clone(t_matrix *original);
int			matrix_compare(t_matrix *mat1, t_matrix *mat2);
t_matrix	*matrix_create(int n, int m);
double		matrix_determinants(t_matrix *matrix);
double		matrix_dot(t_matrix *mat1, t_matrix *mat2);
t_matrix	*matrix_identity(int n);
t_matrix	*matrix_inverse(t_matrix *matrix);
double		matrix_length(t_matrix *matrix);
t_matrix	*matrix_multiple(t_matrix *matrix1, t_matrix *matrix2);
void		matrix_normalize(t_matrix *matrix);
t_matrix	*create_point(double x, double y, double z);
void		matrix_scalar_mult(t_matrix *matrix, double scalar);
t_matrix	*matrix_sum(t_matrix *mat1, t_matrix *mat2);
t_matrix	*matrix_subs(t_matrix *mat1, t_matrix *mat2);
t_matrix	*matrix_transpose(t_matrix *matrix);
t_matrix	*create_vector(double x, double y, double z);

#endif
