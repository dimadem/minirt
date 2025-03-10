/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transpose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:44:02 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/02 13:27:44 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"

t_matrix	*matrix_transpose(t_matrix *matrix)
{
	int			i;
	int			j;
	t_matrix	*transpose;

	transpose = matrix_create(matrix->m, matrix->n);
	j = 0;
	while (j < matrix->n)
	{
		i = 0;
		while (i < matrix->m)
		{
			transpose->data[i][j] = matrix->data[j][i];
			i++;
		}
		j++;
	}
	return (transpose);
}
