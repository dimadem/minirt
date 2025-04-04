/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discriminant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:57:12 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/14 12:27:40 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_helpers.h"
#include "base_tuples.h"
#include "base_matrices.h"

double	discriminant(t_ray *ray, t_matrix *sphere_to_ray)
{
	double	a;
	double	b;
	double	c;

	a = matrix_dot(ray->direction, ray->direction);
	b = 2 * matrix_dot(ray->direction, sphere_to_ray);
	c = matrix_dot(sphere_to_ray, sphere_to_ray) - 1;
	return (b * b - 4 * a * c);
}
