/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_transform.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:06:55 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/14 12:06:56 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_TRANSFORM_H
# define OBJECTS_TRANSFORM_H

# include "types.h"

t_matrix	*rotation_z(double radian);
t_matrix	*rotation_y(double radian);
t_matrix	*rotation_x(double radian);
t_matrix	*object_scaling(double x, double y, double z);
t_matrix	*shearing(int type);
t_matrix	*object_translation(double x, double y, double z);

t_matrix	*transform_chain(t_matrix *a, t_matrix *b);

#endif
