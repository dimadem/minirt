/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics_light.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:35:31 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/14 14:35:55 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHYSICS_LIGHT_H
# define PHYSICS_LIGHT_H

# include "types.h"

t_mat		lighting(t_rayt *lux, t_mat mat, t_matrix *pos, t_matrix *v_normal);
t_matrix	*reflect(t_matrix *incoming, t_matrix *normal);

#endif
