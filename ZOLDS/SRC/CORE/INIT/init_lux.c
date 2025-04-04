/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:19:38 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/09 13:23:17 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_init.h"
#include "core_cleanup.h"

//	Initializes variables inside main data structure to safe defaults
void	init_lux(t_rayt *lux)
{
	if (lux == NULL)
		exit_cleanup("Error - Lux could not be passed to init!\n", NULL, errno);
	lux->mlx_ptr = NULL;
	lux->win_ptr = NULL;
	lux->image.img = NULL;
	lux->image.addr = NULL;
	lux->image.bpp = -1;
	lux->image.line_len = -1;
	lux->image.endian = -1;
	lux->p_light = NULL;
	lux->a_light = NULL;
	lux->camera = NULL;
	lux->objects = NULL;
	lux->file_fd = -1;
}
