/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_clone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:33:59 by mcoskune          #+#    #+#             */
/*   Updated: 2024/12/28 20:37:48 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"

t_matrix	*matrix_clone(t_matrix *original)
{
	t_matrix	*c_matrix;
	int			i;
	int			j;

	if (original == NULL)
		return (NULL);
	c_matrix = matrix_create(original->n, original->m);
	if (c_matrix == NULL)
		return (NULL);
	j = 0;
	while (j < original->n)
	{
		i = 0;
		while (i < original->m)
		{
			c_matrix->data[j][i] = original->data[j][i];
			i++;
		}
		j++;
	}
	return (c_matrix);
}
