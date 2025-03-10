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
	t_ray	*new_ray;

	new_ray = ray_create(NULL, NULL);
	new_ray->origin = matrix_multiple(matrix, ray->origin);
	new_ray->direction = matrix_multiple(matrix, ray->direction);
	return (new_ray);
}
