/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discriminant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:57:12 by mcoskune          #+#    #+#             */
/*   Updated: 2025/04/07 15:43:57 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	discriminant(t_ray *ray, t_tuple *sphere_to_ray)
{
	double	a;
	double	b;
	double	c;

	a = tuple_dot(&ray->direction, &ray->direction);
	b = 2 * tuple_dot(&ray->direction, sphere_to_ray);
	c = tuple_dot(sphere_to_ray, sphere_to_ray) - 1;
	return (b * b - 4 * a * c);
}
