/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:35:53 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/19 18:24:34 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"
#include "base_helpers.h"
#include "base_rays.h"
#include "muk_lib.h"
#include "base_rays.h"

static void	asgva(t_isect ***a_ix, t_ray *nray, t_matrix *sptoray, double delta)
{
	double	var;
	t_isect	*inter;

	inter = safe_malloc(sizeof(t_isect), 1);
	var = -1 * 2 * matrix_dot(nray->direction, sptoray) - sqrt(delta);
	inter->t_val = var / (2 * matrix_dot(nray->direction, nray->direction));
	add_to_dptr((void ***)a_ix, (void *)inter);
	inter = safe_malloc(sizeof(t_isect), 1);
	var = -1 * 2 * matrix_dot(nray->direction, sptoray) + sqrt(delta);
	inter->t_val = var / (2 * matrix_dot(nray->direction, nray->direction));
	add_to_dptr((void ***)a_ix, (void *)inter);
}

t_isect	**ray_intersect_sphere(t_object *obj, t_ray *ray)
{
	t_isect		**all_inter;
	t_matrix	*sptoray;
	double		delta;
	t_ray		*nray;

	all_inter = NULL;
	sptoray = matrix_inverse(obj->obj.sphere.transform);
	nray = ray_transform(ray, sptoray);
	free_matrix(sptoray);
	sptoray = matrix_subs(nray->origin, obj->obj.sphere.origin);
	delta = discriminant(nray, sptoray);
	if (delta < 0)
		return (free_ray(nray), free_matrix(sptoray), NULL);
	asgva(&all_inter, nray, sptoray, delta);
	free_matrix(sptoray);
	free_ray(nray);
	return (all_inter);
}

	// t_intersect	*const **to_return = (t_intersect **){NULL};
	// int arr[10] = {0};
	// struct s_struct { int x, y; int *ptr} el = {};
	// int *const retval = (int *)(int[1]){0};
	// t_intersect *const **all_inter_arr = (t_intersect **[1]){NULL};
	// matrix_create();
