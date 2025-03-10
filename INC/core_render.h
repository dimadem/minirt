/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_render.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:06:43 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/14 12:06:44 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_RENDER_H
# define CORE_RENDER_H

# include "types.h"
# include "window_size.h"

void	render_main(t_rayt *lux);
int		create_image(t_rayt *lux);
void	pixel_to_image(t_rayt *lux, int **pixel, int i_width, int i_height);

#endif
