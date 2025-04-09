/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:13:31 by mcoskune          #+#    #+#             */
/*   Updated: 2025/04/08 11:12:57 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

#include "types.h"

t_ray		ray_create(t_tuple *origin, t_tuple *direction);
t_tuple		ray_position(t_ray ray, double dt);
t_isect		**ray_intersect_sphere(t_object *obj, t_ray *ray);
t_ray		ray_transform(t_ray *ray, t_matrix *matrix);


#endif