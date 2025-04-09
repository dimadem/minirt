/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:13:02 by mcoskune          #+#    #+#             */
/*   Updated: 2025/04/08 21:36:17 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	create_sphere_intersections(t_isect ***a_ix, double t1, double t2)
{
	t_isect	*inter1;
	t_isect	*inter2;

	if (!a_ix)
		return;
		
	inter1 = safe_malloc(sizeof(t_isect), 1);
	if (!inter1)
		return;
		
	inter1->t_val = t1;
	add_to_dptr((void ***)a_ix, (void *)inter1);
	
	inter2 = safe_malloc(sizeof(t_isect), 1);
	if (!inter2)
	{
		free((*a_ix)[0]);
		*a_ix = NULL;
		return;
	}
	
	inter2->t_val = t2;
	add_to_dptr((void ***)a_ix, (void *)inter2);
}

t_isect	**ray_intersect_sphere(t_object *obj, t_ray *ray)
{
	t_isect		**all_inter;
	t_matrix	sptoray;
	double		delta;
	t_ray		nray;
	t_tuple		temp;
	double		t1, t2, var;

	if (!obj || !ray || obj->type != SPHERE)
		return (NULL);
	all_inter = NULL;
	sptoray = matrix_inverse(&obj->obj.sphere.transform);
	nray = ray_transform(ray, &sptoray);
	temp = tuple_sub(&nray.origin, &obj->obj.sphere.origin);
	delta = discriminant(&nray, &temp);
	if (delta < 0)
	{
		return (NULL);
	}
	var = -1 * 2 * tuple_dot(&nray.direction, &temp);
	t1 = (var - sqrt(delta)) / (2 * tuple_dot(&nray.direction, &nray.direction));
	t2 = (var + sqrt(delta)) / (2 * tuple_dot(&nray.direction, &nray.direction));
	create_sphere_intersections(&all_inter, t1, t2);
	return (all_inter);
}

t_ray	ray_transform(t_ray *ray, t_matrix *matrix)
{
	t_ray		new_ray;
	t_tuple		new_origin;
	t_tuple		new_direction;

	new_origin = matrix_tuple_multiple(matrix, &ray->origin);
	new_direction = matrix_tuple_multiple(matrix, &ray->direction);
	new_ray.origin = new_origin;
	new_ray.direction = new_direction;
	return (new_ray);
}

t_tuple	ray_position(t_ray ray, double dt)
{
	t_tuple	pos;

	pos.n = 4;
	pos.m = 1;
	pos.data[0][0] = ray.origin.data[0][0] + ray.direction.data[0][0] * dt;
	pos.data[1][0] = ray.origin.data[1][0] + ray.direction.data[1][0] * dt;
	pos.data[2][0] = ray.origin.data[2][0] + ray.direction.data[2][0] * dt;
	pos.data[3][0] = 1;
	return (pos);
}

t_ray	ray_create(t_tuple *origin, t_tuple *direction)
{
	t_ray	temp;

	temp.origin = *origin;
	temp.direction = *direction;
	return (temp);
}

// t_ray	*ray_create_local(t_matrix *origin, t_uv *direction)
// {
// 	t_ray	*temp;
// 	t_matrix *dir;

// 	if (!origin || !direction)
// 		return (NULL);
		
// 	dir = matrix_create(4, 1);
// 	if (!dir)
// 		return (NULL);
		
// 	dir->data[0][0] = direction->u;
// 	dir->data[1][0] = direction->v;
// 	dir->data[2][0] = 1.0;
// 	dir->data[3][0] = 0.0;
	
// 	temp = safe_malloc(sizeof(t_ray), 1);
// 	if (!temp)
// 	{
// 		free_matrix(dir);
// 		return (NULL);
// 	}
	
// 	temp->origin = matrix_clone(origin);
// 	if (!temp->origin)
// 	{
// 		free_matrix(dir);
// 		free(temp);
// 		return (NULL);
// 	}
	
// 	temp->direction = dir;
// 	return (temp);
// }