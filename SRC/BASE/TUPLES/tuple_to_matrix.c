/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_to_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 02:09:26 by mcoskune          #+#    #+#             */
/*   Updated: 2024/12/29 00:01:36 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"

t_matrix	*tuple_to_matrix(t_tuple *tuple)
{
	t_matrix	*temp;

	temp = matrix_create(4, 1);
	if (temp == NULL)
		return (temp);
	temp->data[0][0] = tuple->x;
	temp->data[1][0] = tuple->y;
	temp->data[2][0] = tuple->z;
	temp->data[3][0] = tuple->w;
	return (temp);
}
