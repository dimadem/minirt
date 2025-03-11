/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_determinants.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:22:25 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/02 13:30:26 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"
#include "muk_lib.h"

static void	populate_smol(t_matrix *matrix, t_matrix *smol, int column)
{
	int	i;
	int	j;
	int	x;
	int	y;

	j = 1;
	y = 0;
	while (j < matrix->n)
	{
		i = 0;
		x = 0;
		while (i < matrix->m)
		{
			if (i != column)
				smol->data[y][x++] = matrix->data[j][i++];
			else
				i++;
		}
		j++;
		y++;
	}
}

// Special case for 3x3 matrices to avoid recursion
static double	det3x3(t_matrix *mat)
{
	double	a, b, c, d, e, f, g, h, i;
	
	a = mat->data[0][0];
	b = mat->data[0][1];
	c = mat->data[0][2];
	d = mat->data[1][0];
	e = mat->data[1][1];
	f = mat->data[1][2];
	g = mat->data[2][0];
	h = mat->data[2][1];
	i = mat->data[2][2];
	
	return a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
}

double	matrix_determinants(t_matrix *matrix)
{
	int			i;
	t_matrix	*smol;
	int			sign;
	double		res;

	i = 0;
	sign = 1;
	res = 0;
	if (!matrix || matrix->n != matrix->m)
		return (0);
		
	if (matrix->n == 1)
		return (matrix->data[0][0]);
	else if (matrix->n == 2)
		return (matrix->data[0][0] * matrix->data[1][1] - 
				matrix->data[0][1] * matrix->data[1][0]);
	else if (matrix->n == 3)
		return (det3x3(matrix));
	else if (matrix->n > 3)
	{
		while (i < matrix->n)
		{
			smol = matrix_create(matrix->n - 1, matrix->m - 1);
			populate_smol(matrix, smol, i);
			res += sign * matrix->data[0][i] * matrix_determinants(smol);
			sign *= -1;
			free_matrix(smol);
			i++;
		}
	}
	return (res);
}
