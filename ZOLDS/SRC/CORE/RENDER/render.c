/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:38:59 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/05 18:31:11 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_render.h"
#include "core_cleanup.h"
#include <stdio.h>
#include <mlx.h>

void	print_matrix(t_matrix *mat, const char *name)
{
	int	i;
	int	j;

	j = 0;
	if (name)
		printf("%s:\n", name);
	while (j < mat->n)
	{
		i = 0;
		while (i < mat->m)
		{
			printf("%.5f ", mat->data[j++][i++]);
		}
		printf("\n");
	}
	printf("\n");
}

void	render_main(t_rayt *lux)
{
	mlx_loop_hook(lux->mlx_ptr, create_image, lux);
	mlx_hook(lux->win_ptr, 17, 0, handle_x_button, lux);
	mlx_key_hook(lux->win_ptr, handle_keys, lux);
	mlx_loop(lux->mlx_ptr);
}
