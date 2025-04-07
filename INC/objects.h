/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:56:37 by mcoskune          #+#    #+#             */
/*   Updated: 2025/04/07 17:01:44 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H


/* OBJECT MANIPULATION */
t_matrix	object_translation(double x, double y, double z);
t_matrix	object_scaling(double x, double y, double z);
t_matrix	rotation_x(double radian);
t_matrix	rotation_y(double radian);
t_matrix	rotation_z(double radian);
t_matrix	shearing(int type);

#endif