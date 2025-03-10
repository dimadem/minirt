/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_identity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:34:38 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/02 13:30:36 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"
/**
 * @brief Function that creates an identity matrix of size n
 * 1 0 0 0
 * 0 1 0 0
 * 0 0 1 0
 * 0 0 0 1
 */
t_matrix	*matrix_identity(int n)
{
	t_matrix	*identity;
	int			i;
	int			j;

	identity = matrix_create(n, n);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			identity->data[i][j] = (double)0;
			if (i == j)
				identity->data[i][j] = (double)1;
			j++;
		}
		i++;
	}
	return (identity);
}
