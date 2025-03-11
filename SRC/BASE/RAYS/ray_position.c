/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:16:45 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/18 19:29:39 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"

t_matrix	*ray_position(t_ray *ray, double dt)
{
	t_matrix	*pos;

	if (!ray || !ray->origin || !ray->direction)
		return (NULL);
		
	pos = matrix_create(4, 1);
	if (pos == NULL)
		return (NULL);
		
	pos->data[0][0] = ray->origin->data[0][0] + ray->direction->data[0][0] * dt;
	pos->data[1][0] = ray->origin->data[1][0] + ray->direction->data[1][0] * dt;
	pos->data[2][0] = ray->origin->data[2][0] + ray->direction->data[2][0] * dt;
	pos->data[3][0] = 1;
	return (pos);
}
