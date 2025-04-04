/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_rays.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:34:29 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/19 20:33:55 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_RAYS_H
# define BASE_RAYS_H

# include "types.h"

t_ray		*ray_clone(t_ray *original);
t_ray		*ray_create(t_matrix *origin, t_matrix *vector);
t_ray		*ray_create_local(t_matrix *origin, t_uv *vector);
void		free_ray(t_ray *ray);
t_isect		**ray_intersect_sphere(t_object *obj, t_ray *ray);
t_isect		**ray_intersect_plane(t_object *obj, t_ray *ray);
t_isect		**ray_intersect_cylinder(t_object *obj, t_ray *ray);
t_matrix	*ray_position(t_ray *ray, double dt);
t_ray		*ray_transform(t_ray *ray, t_matrix *matrix);
t_isect		**ray_intersect_world(t_rayt *lux, t_ray *ray);

#endif
