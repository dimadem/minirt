/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_to_tuple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:50:57 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/24 15:52:07 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

t_tuple	*matrix_to_tuple(t_matrix *mat)
{
	t_tuple	*temp;

	temp = (t_tuple *)malloc(sizeof(t_tuple));
	if (temp == NULL)
		return (temp);
	temp->x = mat->data[0][0];
	temp->y = mat->data[1][0];
	temp->z = mat->data[2][0];
	temp->w = mat->data[3][0];
	return (temp);
}
