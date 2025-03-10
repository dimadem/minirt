/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:06:19 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/15 21:00:06 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"

void	free_matrix(t_matrix *mat)
{
	int	i;

	i = 0;
	if (mat == NULL)
		return ;
	if (mat->data != NULL)
	{
		while (i < mat->n)
		{
			if (mat->data[i])
				free(mat->data[i]);
			i++;
		}
		free(mat->data);
	}
	free(mat);
	mat = NULL;
}
