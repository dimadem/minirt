/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:39:26 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/19 20:33:34 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "types.h"

// ************************************************************************** //
//                                 RENDER                                     //
// ************************************************************************** //
void		render_main(t_rayt *lux);

// ************************************************************************** //
//                                 IMAGE                                      //
// ************************************************************************** //
void		pixel_to_image(t_rayt *lux, int **pixel, int i_width, int i_height);
t_isect		**ray_intersect_sphere(t_object *obj, t_ray *ray);
t_ray		*ray_create(t_matrix *origin, t_matrix *vector);
t_ray		*ray_clone(t_ray *original);
t_matrix	*ray_position(t_ray *ray, double dt);
int			create_image(t_rayt *lux);

// ************************************************************************** //
//                               COLOUR_MANIP                                 //
// ************************************************************************** //
t_trgb		colour_sum(t_trgb colour1, t_trgb colour2);
t_trgb		colour_scalar_mult(t_trgb colour, double num);
t_trgb		colour_hadamard_product(t_trgb colour1, t_trgb colour2);
t_trgb		colour_subs(t_trgb colour1, t_trgb colour2);
t_trgb		colour(double red, double green, double blue);
void		t_trgb_to_addr(char *addr, t_trgb colour);
int			t_trgb_to_hex(t_trgb c);
char		*join_rgb_values(unsigned char r, unsigned char g, unsigned char b);
int			colour_to_int(t_trgb data);
t_mat		lighting(t_rayt *lux, t_mat mat, t_matrix *pos, t_matrix *v_normal);

#endif
