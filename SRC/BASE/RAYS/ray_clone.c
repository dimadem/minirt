/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_clone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:22:55 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/02 13:21:59 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"
#include "base_rays.h"

t_ray	*ray_clone(t_ray *original)
{
	t_ray		*c_ray;
	t_matrix	*c_origin;
	t_matrix	*c_vector;

	if (original == NULL)
		return (NULL);
	c_origin = matrix_clone(original->origin);
	if (c_origin == NULL)
		return (NULL);
	c_vector = matrix_clone(original->direction);
	if (c_vector == NULL)
		return (free(c_origin), NULL);
	c_ray = ray_create(c_origin, c_vector);
	if (c_ray == NULL)
		return (free(c_origin), free(c_vector), NULL);
	return (c_ray);
}
