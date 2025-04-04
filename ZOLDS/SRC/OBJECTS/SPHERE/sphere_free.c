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

/**
 * Frees a sphere object and all of its associated matrices.
 * This function is safe to call with NULL.
 * 
 * @param sphere Pointer to the sphere object to free
 */
void	free_sphere(t_object *sphere)
{
	if (sphere == NULL)
		return ;
	if (sphere->obj.sphere.origin != NULL)
		free_matrix(sphere->obj.sphere.origin);
	if (sphere->obj.sphere.transform != NULL)
		free_matrix(sphere->obj.sphere.transform);
	free(sphere);
	// Note: setting fields to NULL has no effect since we're freeing sphere
}
