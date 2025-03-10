/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:47:50 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/24 15:48:17 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "objects_sphere.h"
#include "base_matrices.h"

void	free_sphere(t_object *sphere)
{
	if (sphere == NULL)
		return ;
	if (sphere->obj.sphere.origin != NULL)
	{
		free_matrix(sphere->obj.sphere.origin);
		sphere->obj.sphere.origin = NULL;
	}
	if (sphere->obj.sphere.transform != NULL)
	{
		free_matrix(sphere->obj.sphere.transform);
		sphere->obj.sphere.transform = NULL;
	}
	free(sphere);
}
