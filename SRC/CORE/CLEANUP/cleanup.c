/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:28:12 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/16 00:32:40 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "muk_lib.h"
#include "core_cleanup.h"
#include "base_matrices.h"
#include "objects_utils.h"
#include "libft.h"
#include <mlx.h>

static void	clear_mlx(t_rayt *lux)
{
	if (lux->win_ptr != NULL)
	{
		mlx_destroy_window(lux->mlx_ptr, lux->win_ptr);
		lux->win_ptr = NULL;
	}
	if (lux->image.img != NULL)
	{
		mlx_destroy_image(lux->mlx_ptr, lux->image.img);
		lux->image.img = NULL;
	}
	if (lux->mlx_ptr != NULL)
	{
		mlx_destroy_display(lux->mlx_ptr);
		free(lux->mlx_ptr);
		lux->mlx_ptr = NULL;
	}
	lux->image.addr = NULL;
}

void	exit_cleanup(char *msg, t_rayt *lux, int exit_code)
{
	if (msg != NULL)
		ft_putstr_fd(msg, 2);
	if (lux == NULL)
		exit(exit_code);
	if (lux->mlx_ptr != NULL || lux->win_ptr != NULL)
		clear_mlx(lux);
	if (lux->p_light)
	{
		free_matrix(lux->p_light->origin);
		free(lux->p_light);
	}
	if (lux->a_light)
		free(lux->a_light);
	if (lux->camera)
	{
		free_matrix(lux->camera->origin);
		free_matrix(lux->camera->v_orient);
		free(lux->camera);
	}
	free_objects(lux->objects);
	exit(exit_code);
}

int	handle_keys(int keysys, t_rayt *lux)
{
	if (keysys == XK_Escape)
		mlx_loop_end(lux->mlx_ptr);
	else if (keysys == XK_r)
	{
		free(lux->image.img);
		lux->image.img = NULL;
	}
	return (0);
}

int	handle_x_button(t_rayt *lux)
{
	mlx_loop_end(lux->mlx_ptr);
	return (0);
}
