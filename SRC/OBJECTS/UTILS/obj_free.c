/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:32:33 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/24 17:28:03 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"

/**
 * Frees a single object and all of its associated matrices.
 * This function is safe to call with NULL.
 * 
 * @param obj Pointer to the object to free
 */
void	free_object(t_object *obj)
{
	if (obj == NULL)
		return ;
	if (obj->type == SPHERE)
	{
		if (obj->obj.sphere.origin)
			free_matrix(obj->obj.sphere.origin);
		if (obj->obj.sphere.transform)
			free_matrix(obj->obj.sphere.transform);
	}
	else if (obj->type == PLANE)
	{
		if (obj->obj.plane.origin)
			free_matrix(obj->obj.plane.origin);
		if (obj->obj.plane.v_orient)
			free_matrix(obj->obj.plane.v_orient);
	}
	else if (obj->type == CYLINDER)
	{
		if (obj->obj.cylinder.origin)
			free_matrix(obj->obj.cylinder.origin);
		if (obj->obj.cylinder.v_orient)
			free_matrix(obj->obj.cylinder.v_orient);
	}
	free(obj);
}

/**
 * Frees an array of objects and all their associated matrices.
 * This function is safe to call with NULL.
 * 
 * @param objects Pointer to the array of object pointers to free
 */
void	free_objects(t_object **objects)
{
	int	i;

	if (objects == NULL)
		return ;
	i = 0;
	while (objects[i] != NULL)
	{
		free_object(objects[i]);
		i++;
	}
	free(objects);
}
