/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:13:02 by mcoskune          #+#    #+#             */
/*   Updated: 2025/04/07 17:29:30 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_isect	**ray_intersect_sphere(t_object *obj, t_ray *ray)
{
	t_isect		**all_inter;
	// t_matrix	sptoray;
	// double		delta;
	// t_ray		*nray;
	// double		t1, t2, var;

	if (!obj || !ray || obj->type != SPHERE || !obj->obj.sphere.transform)
		return (NULL);
		
	// all_inter = NULL;
	// sptoray = matrix_inverse(obj->obj.sphere.transform);
		
	// nray = ray_transform(ray, sptoray);
	// if (!nray)
	// 	return (NULL);
		
	// sptoray = matrix_sub(&nray->origin, obj->obj.sphere.origin);
	// delta = discriminant(nray, &sptoray);
	// if (delta < 0)
	// {
	// 	return (NULL);
	// }
	
	// var = -1 * 2 * tuple_dot(&nray->direction, &sptoray);
	// t1 = (var - sqrt(delta)) / (2 * tuple_dot(&nray->direction, &nray->direction));
	// t2 = (var + sqrt(delta)) / (2 * tuple_dot(&nray->direction, &nray->direction));

	// create_sphere_intersections(&all_inter, t1, t2);
	all_inter = NULL;
	return (all_inter);
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