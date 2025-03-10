/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:30:27 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/24 15:30:57 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "base_matrices.h"

void	free_camera(t_camera *camera)
{
	if (camera == NULL)
		return ;
	free_matrix(camera->origin);
	free_matrix(camera->v_orient);
	free(camera);
}
