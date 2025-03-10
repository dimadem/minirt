/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_helpers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:06:24 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/18 19:26:50 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HELPERS_H
# define BASE_HELPERS_H

# include "types.h"

double	discriminant(t_ray *ray, t_matrix *sphere_to_ray);
int		epsilon(double a, double b);
int		first_valid_intersection(t_isect **intersect);
t_comps	*prepare_computations(t_rayt *lux, t_isect **inter, t_ray *ray);

#endif
