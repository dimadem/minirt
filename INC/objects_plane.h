/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_plane.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:00:00 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/03/11 15:00:00 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_PLANE_H
# define OBJECTS_PLANE_H

# include "types.h"

t_matrix	*plane_normal(t_object *curr, t_matrix *point);

#endif