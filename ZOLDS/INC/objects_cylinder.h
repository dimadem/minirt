/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_cylinder.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:00:00 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/03/12 15:00:00 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_CYLINDER_H
# define OBJECTS_CYLINDER_H

# include "types.h"

/**
 * Calculates the normal vector at a point on a cylinder.
 * 
 * @param curr The cylinder object
 * @param point The point on the cylinder surface to calculate the normal for
 * @return A new matrix representing the normalized normal vector, or NULL on error
 */
t_matrix	*cylinder_normal(t_object *curr, t_matrix *point);

#endif