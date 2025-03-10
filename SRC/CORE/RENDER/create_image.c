/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:17:46 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/24 15:48:50 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_render.h"
#include "features_ppm.h"
#include "objects_utils.h"
#include "muk_lib.h"
#include <mlx.h>

void	pixel_to_image(t_rayt *lux, int **pixel, int i_width, int i_height)
{
	int		i;
	int		j;
	char	*add;
	int		offset;

	i = 0;
	j = 0;
	add = lux->image.addr;
	while (j < i_height)
	{
		i = 0;
		while (i < i_width)
		{
			offset = j * lux->image.line_len + i * (lux->image.bpp / 8);
			add[offset] = (pixel[j][i] & 0xFF);
			add[offset + 1] = (pixel[j][i] >> 8) & 0xFF;
			add[offset + 2] = (pixel[j][i] >> 16) & 0xFF;
			add[offset + 3] = (pixel[j][i] >> 24) & 0xFF;
			i++;
		}
		j++;
	}
}

int	create_image(t_rayt *lux)
{
	int	**pixel;
	int	i;

	i = 0;
	pixel = safe_malloc(sizeof(int *), WINDOW_HEIGHT);
	while (i < WINDOW_HEIGHT)
		pixel[i++] = safe_malloc(sizeof(int), WINDOW_WIDTH);
	if (lux->image.img != NULL)
	{
		mlx_destroy_image(lux->mlx_ptr, lux->image.img);
		lux->image.img = NULL;
	}
	lux->image.img = mlx_new_image(lux->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	lux->image.addr = mlx_get_data_addr(lux->image.img, &lux->image.bpp, \
			&lux->image.line_len, &lux->image.endian);
	obj_render(pixel, lux->objects, lux->camera);
	pixel_to_image(lux, pixel, WINDOW_WIDTH, WINDOW_HEIGHT);
	canvas_to_ppm("./canvas.ppm", lux, WINDOW_WIDTH, WINDOW_HEIGHT);
	i = 0;
	while (i < WINDOW_HEIGHT)
		free(pixel[i++]);
	free(pixel);
	mlx_put_image_to_window(lux->mlx_ptr, lux->win_ptr, lux->image.img, 0, 0);
	return (0);
}
