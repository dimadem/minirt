/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:16:06 by mcoskune          #+#    #+#             */
/*   Updated: 2024/12/28 20:54:19 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "muk_lib.h"
#include "base_matrices.h"

static double	calculate_value(t_matrix *mat1, t_matrix *mat2, int i, int j)
{
	int		k;
	double	sum;

	k = 0;
	sum = 0;
	while (k < mat1->m)
	{
		sum += mat1->data[j][k] * mat2->data[k][i];
		k++;
	}
	return (sum);
}

static void	result_iterator(t_matrix *result, t_matrix *mat1, t_matrix *mat2)
{
	int	i;
	int	j;

	j = 0;
	while (j < mat1->n)
	{
		i = 0;
		while (i < mat2->m)
		{
			result->data[j][i] = calculate_value(mat1, mat2, i, j);
			i++;
		}
		j++;
	}
}

t_matrix	*matrix_multiple(t_matrix *matrix1, t_matrix *matrix2)
{
	t_matrix	*result;

	if (matrix1 == NULL || matrix2 == NULL)
		return (NULL);
	if (matrix1->m != matrix2->n)
		return (errmsg("Error - Matrix Mult is not legal!"), NULL);
	result = matrix_create(matrix1->n, matrix2->m);
	if (result == NULL)
		return (NULL);
	result_iterator(result, matrix1, matrix2);
	return (result);
}
