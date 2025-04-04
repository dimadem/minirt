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
	t_ray	*c_ray;

	if (!original || !original->origin || !original->direction)
		return (NULL);
		
	// ray_create now internally clones the matrices
	c_ray = ray_create(original->origin, original->direction);
	return (c_ray);
}
