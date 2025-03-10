/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_sum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 00:10:01 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/03 21:27:58 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"

t_matrix	*matrix_subs(t_matrix *mat1, t_matrix *mat2)
{
	int			i;
	int			j;
	t_matrix	*result;

	if (!mat1 || !mat2 || mat1->n != mat2->n || mat1->m != mat2->m)
		return (NULL);
	result = matrix_create(mat1->n, mat1->m);
	if (!result)
		return (NULL);
	j = 0;
	while (j < mat1->n)
	{
		i = 0;
		while (i < mat1->m)
		{
			result->data[j][i] = mat1->data[j][i] - mat2->data[j][i];
			i++;
		}
		j++;
	}
	return (result);
}

t_matrix	*matrix_sum(t_matrix *mat1, t_matrix *mat2)
{
	int			i;
	int			j;
	t_matrix	*result;

	if (!mat1 || !mat2 || mat1->n != mat2->n || mat1->m != mat2->m)
		return (NULL);
	result = matrix_create(mat1->n, mat1->m);
	if (!result)
		return (NULL);
	j = 0;
	while (j < mat1->n)
	{
		i = 0;
		while (i < mat1->m)
		{
			result->data[j][i] = mat1->data[j][i] + mat2->data[j][i];
			i++;
		}
		j++;
	}
	return (result);
}
