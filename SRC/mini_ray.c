/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:46:43 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/14 23:17:12 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_init.h"
#include "core_parse.h"
#include "core_cleanup.h"
#include "core_render.h"

int	main(int ac, char **av)
{
	t_rayt	lux;

	input_validate(ac, av);
	init_lux(&lux);
	parse_rt_main(av, &lux);
	init_mlx(&lux);
	render_main(&lux);
	exit_cleanup("Reached end of MAIN!\n", &lux, 0);
}
