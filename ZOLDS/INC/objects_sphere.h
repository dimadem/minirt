/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_sphere.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:35:11 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/24 15:25:54 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_SPHERE_H
# define OBJECTS_SPHERE_H

# include "types.h"

t_matrix	*sphere_normal(t_object *obj, t_matrix *w_point);
void		free_sphere(t_object *sphere);

#endif
