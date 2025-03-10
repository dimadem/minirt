/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_cleanup.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:06:32 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/14 12:06:34 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_CLEANUP_H
# define CORE_CLEANUP_H

# include <X11/keysym.h>
# include "types.h"

void	exit_cleanup(char *msg, t_rayt *lux, int exit_code);
int		handle_x_button(t_rayt *lux);
int		handle_keys(int keysys, t_rayt *lux);

#endif
