/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:53:26 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/15 20:54:17 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"

void	free_ray(t_ray *ray)
{
	if (ray == NULL)
		return ;
	if (ray->origin)
		free_matrix(ray->origin);
	if (ray->direction)
		free_matrix(ray->direction);
	free(ray);
	ray = NULL;
}
