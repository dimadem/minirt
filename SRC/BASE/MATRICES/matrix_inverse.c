/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:40:27 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/24 15:53:22 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"
#include "muk_lib.h"

static void	handle_upper_triangle(t_matrix *matrix_neo, t_matrix *invert, int j)
{
	double	c;
	int		i;
	int		y;

	y = j - 1;
	while (y >= 0)
	{
		c = matrix_neo->data[y][j] / matrix_neo->data[j][j] * -1;
		i = 0;
		while (i < matrix_neo->m)
		{
			matrix_neo->data[y][i] += matrix_neo->data[j][i] * c;
			invert->data[y][i] += invert->data[j][i] * c;
			i++;
		}
		c = matrix_neo->data[j][j];
		while (--i >= 0)
		{
			matrix_neo->data[j][i] /= c;
			invert->data[j][i] /= c;
		}
		y--;
	}
}

static void	handle_lower_triangle(t_matrix *matrix_neo, t_matrix *invert, int j)
{
	double	c;
	int		i;
	int		y;

	y = j + 1;
	while (y < matrix_neo->n)
	{
		c = matrix_neo->data[y][j] / matrix_neo->data[j][j] * -1;
		i = 0;
		while (i < matrix_neo->m)
		{
			matrix_neo->data[y][i] += matrix_neo->data[j][i] * c;
			invert->data[y][i] += invert->data[j][i] * c;
			i++;
		}
		c = matrix_neo->data[j][j];
		while (--i >= 0)
		{
			matrix_neo->data[j][i] /= c;
			invert->data[j][i] /= c;
		}
		y++;
	}
}

static void	invert(t_matrix *matrix_neo, t_matrix *invert)
{
	int	j;

	j = 0;
	while (j < matrix_neo->n)
	{
		handle_lower_triangle(matrix_neo, invert, j);
		j++;
	}
	j = 0;
	while (j < matrix_neo->n)
	{
		handle_upper_triangle(matrix_neo, invert, j);
		j++;
	}
}

static int	check_invertibility(t_matrix *matrix)
{
	if (matrix->n != matrix->m)
		return (1);
	if (matrix_determinants(matrix) == 0)
		return (2);
	return (0);
}

t_matrix	*matrix_inverse(t_matrix *matrix)
{
	t_matrix	*matrix_neo;
	t_matrix	*inverse;
	int			i;
	int			j;

	if (matrix == NULL || check_invertibility(matrix) != 0)
		return (NULL);
	matrix_neo = matrix_create(matrix->n, matrix->m);
	if (matrix_neo == NULL)
		return (NULL);
	inverse = matrix_identity(matrix->n);
	if (inverse == NULL)
		return (free_matrix(matrix_neo), NULL);
	j = -1;
	while (++j < matrix->n)
	{
		i = -1;
		while (++i < matrix->m)
			matrix_neo->data[j][i] = matrix->data[j][i];
	}
	invert(matrix_neo, inverse);
	free_matrix(matrix_neo);
	return (inverse);
}
