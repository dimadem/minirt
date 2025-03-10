/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 22:29:56 by mcoskune          #+#    #+#             */
/*   Updated: 2024/12/30 13:39:24 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"
#include "base_helpers.h"

int	matrix_compare(t_matrix *mat1, t_matrix *mat2)
{
	int	i;
	int	j;

	if (!mat1 || !mat2)
		return (1);
	if (mat1->n != mat2->n || mat1->m != mat2->m)
		return (2);
	j = 0;
	while (j < mat1->n)
	{
		i = 0;
		while (i < mat1->m)
		{
			if (!epsilon(mat1->data[j][i], mat2->data[j][i]))
				return (3);
			i++;
		}
		j++;
	}
	return (0);
}
