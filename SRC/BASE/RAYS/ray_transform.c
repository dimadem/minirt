/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:13:14 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/02 14:23:48 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"
#include "base_rays.h"

t_ray	*ray_transform(t_ray *ray, t_matrix *matrix)
{
	t_ray		*new_ray;
	t_matrix	*new_origin;
	t_matrix	*new_direction;

	if (!ray || !matrix)
		return (NULL);
		
	new_origin = matrix_multiple(matrix, ray->origin);
	if (!new_origin)
		return (NULL);
		
	new_direction = matrix_multiple(matrix, ray->direction);
	if (!new_direction)
	{
		free_matrix(new_origin);
		return (NULL);
	}
	
	new_ray = safe_malloc(sizeof(t_ray), 1);
	if (!new_ray)
	{
		free_matrix(new_origin);
		free_matrix(new_direction);
		return (NULL);
	}
	
	new_ray->origin = new_origin;
	new_ray->direction = new_direction;
	return (new_ray);
}
