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

void	free_objects(t_object **objects)
{
	int	i;

	if (objects == NULL)
		return ;
	i = 0;
	while (objects[i] != NULL)
	{
		if (objects[i]->type == SPHERE)
		{
			free_matrix(objects[i]->obj.sphere.origin);
			free_matrix(objects[i]->obj.sphere.transform);
		}
		else if (objects[i]->type == PLANE)
		{
			free_matrix(objects[i]->obj.plane.origin);
			free_matrix(objects[i]->obj.plane.v_orient);
		}
		else if (objects[i]->type == CYLINDER)
		{
			free_matrix(objects[i]->obj.cylinder.origin);
			free_matrix(objects[i]->obj.cylinder.v_orient);
		}
		free(objects[i++]);
	}
	free(objects);
}

void	free_object(t_object *obj)
{
	if (obj == NULL)
		return ;
	if (obj->type == SPHERE)
	{
		free_matrix(obj->obj.sphere.origin);
		free_matrix(obj->obj.sphere.transform);
	}
	else if (obj->type == PLANE)
	{
		free_matrix(obj->obj.plane.origin);
		free_matrix(obj->obj.plane.v_orient);
	}
	else if (obj->type == CYLINDER)
	{
		free_matrix(obj->obj.cylinder.origin);
		free_matrix(obj->obj.cylinder.v_orient);
	}
	free(obj);
}
