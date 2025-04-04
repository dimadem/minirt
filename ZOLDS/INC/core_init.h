/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_init.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:06:38 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/14 12:06:38 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_INIT_H
# define CORE_INIT_H

# include "types.h"
# include <mlx.h>
# include <errno.h>
# include "window_size.h"

void	input_validate(int ac, char **av);
void	init_lux(t_rayt *lux);
void	init_mlx(t_rayt *lux);

#endif
