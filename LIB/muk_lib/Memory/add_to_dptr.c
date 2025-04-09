/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_dptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:00:30 by mcoskune          #+#    #+#             */
/*   Updated: 2025/04/07 22:32:23 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../muk_lib.h"
#include "../../../INC/minirt.h"

void	free_matrix(t_matrix *mat);

static void	copy_dptr(void ***old_dptr, void **new_dptr, void *to_add)
{
	int	i;

	i = 0;
	while ((*old_dptr)[i] != NULL)
	{
		new_dptr[i] = (*old_dptr)[i];
		i++;
	}
	new_dptr[i] = to_add;
	new_dptr[i + 1] = NULL;
	if (old_dptr && *old_dptr)
		free(*old_dptr);
	*old_dptr = new_dptr;
}

int	add_to_dptr(void ***dptr, void *to_add)
{
	int		i;
	void	**new_dptr;

	i = 0;
	if (dptr == NULL || to_add == NULL)
		return (1);
	if (*dptr == NULL)
	{
		*dptr = (void **)malloc(sizeof(void *) * 2);
		if (*dptr == NULL)
			return (2);
		(*dptr)[0] = to_add;
		(*dptr)[1] = NULL;
	}
	else
	{
		while ((*dptr)[i] != NULL)
			i++;
		new_dptr = (void **)malloc(sizeof(void *) * (i + 2));
		if (new_dptr == NULL)
			return (2);
		copy_dptr(dptr, new_dptr, to_add);
	}
	return (0);
}
/*
// static void	copy_ptr(void **old_ptr, void **new_ptr, void *to_add)
// {
// 	int	i;

// 	i = 0;
// 	while ((old_ptr)[i] != NULL)
// 	{
// 		new_ptr[i] = (old_ptr)[i];
// 		i++;
// 	}
// 	new_ptr[i] = to_add;
// 	new_ptr[i + 1] = NULL;
// 	free(*old_ptr);
// 	old_ptr = new_ptr;
// }

// int	add_to_ptr(void **ptr, void *to_add)
// {
// 	void	*new_ptr;
// 	t_plane	*temp;

// 	new_ptr = NULL;
// 	if (ptr == NULL || to_add == NULL)
// 		return (1);
// 	if (ptr == NULL)
// 		(*ptr) = to_add;
// 	else
// 	{
// 		temp = (t_plane *)to_add;
// 		if (temp->type != AMBIENT)
// 			free_matrix(temp->origin);
// 		if (temp->type == CYLINDER || 
// temp->type == PLANE || \
// 		temp->type == CYLINDER 
//|| temp->type == CAMERA || temp->type == SPHERE)
// 			free_matrix(temp->v_orient);
// 		free (*ptr);
// 		*ptr = NULL;
// 		copy_ptr(ptr, new_ptr, to_add);
// 	}
// 	return (0);
// }
 */

int	add_to_ptr(void **ptr, void *to_add)
{
	if (ptr == NULL || to_add == NULL)
		return (1);
	if (*ptr != NULL)
	{
		// if (((t_ambient *)*ptr)->type == AMBIENT)
		// 	free(*ptr);
		// else if (((t_camera *)*ptr)->type == CAMERA)
		// {
		// 	free_matrix(((t_camera *)*ptr)->origin);
		// 	free_matrix(((t_camera *)*ptr)->v_orient);
		// 	free(*ptr);
		// }
		// else if (((t_light *)*ptr)->type == LIGHT)
		// {
		// 	free_matrix(((t_light *)*ptr)->origin);
		// 	free(*ptr);
		// }
	}
	*ptr = to_add;
	return (0);
}
