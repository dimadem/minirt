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

double	matrix_determinants(t_matrix *matrix)
{
	int			i;
	t_matrix	*smol;
	int			sign;
	double		res;

	i = 0;
	sign = 1;
	res = 0;
	if (matrix->n == 1 && matrix->m == 1)
		return (matrix->data[0][0]);
	else if (matrix->n == 2 && matrix->m == 2)
		return (matrix->data[0][0] * matrix->data[1][1] - \
				matrix->data[0][1] * matrix->data[1][0]);
	else if (matrix->n > 2 && matrix->m == matrix->n)
	{
		while (i < matrix->n)
		{
			smol = matrix_create(matrix->n - 1, matrix->m - 1);
			populate_smol(matrix, smol, i);
			res += sign * matrix->data[0][i++] * matrix_determinants(smol);
			sign *= -1;
			free_matrix(smol);
		}
	}
	return (res);
}
