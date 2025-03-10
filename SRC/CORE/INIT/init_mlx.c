/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:38:23 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/12/24 12:52:39 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_init.h"
#include "core_cleanup.h"

void	init_mlx(t_rayt *lux)
{
	if (lux == NULL)
		exit_cleanup("Error - Lux is missing at mlx_init", NULL, -7);
	lux->mlx_ptr = mlx_init();
	if (lux->mlx_ptr == NULL)
		exit_cleanup ("Error - `mlx_init`\n", lux, errno);
	lux->win_ptr = mlx_new_window(lux->mlx_ptr, WINDOW_WIDTH, \
			WINDOW_HEIGHT, "minirt");
	if (lux->win_ptr == NULL)
		exit_cleanup ("Error - `mlx_new_win`\n", lux, errno);
	lux->image.img = mlx_new_image(lux->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (lux->image.img == NULL)
		exit_cleanup ("Error - `mlx_new_image`\n", lux, errno);
}
