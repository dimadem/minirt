/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:23:43 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/19 18:22:10 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"
#include "muk_lib.h"

t_matrix	*matrix_create(int n, int m)
{
	t_matrix	*matrix;
	int			i;

	matrix = safe_malloc(sizeof(t_matrix), 1);
	if (matrix == NULL)
		return (NULL);
	matrix->n = n;
	matrix->m = m;
	matrix->data = safe_malloc(sizeof(double *), n);
	if (matrix->data == NULL)
		return (free(matrix), NULL);
	i = 0;
	while (i < n)
	{
		matrix->data[i] = safe_malloc(sizeof(double), m);
		if (matrix->data[i] == NULL)
		{
			free_dptr((void **)matrix->data);
			free(matrix);
			return (NULL);
		}
		i++;
	}
	return (matrix);
}

	// int arr[n];
	// int (**arr2)[m] = (int **)malloc(n * m * sizeof(int));
	// (*arr)[2][3];
