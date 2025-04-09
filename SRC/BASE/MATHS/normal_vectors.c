/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_vectors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:43:44 by mcoskune          #+#    #+#             */
/*   Updated: 2025/04/08 21:50:14 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	sphere_normal(t_object *curr, t_tuple *w_point)
{
	t_tuple	o_point;
	t_tuple	o_normal;
	t_tuple	w_normal;
	t_tuple	temp;

	// Check for sphere transform existence
	// if (!curr.obj.sphere.transform)
	// {
	// 	// If no transform exists, create a default normal (pointing outward from origin)
	// 	w_normal = matrix_create(4, 1);

	// 	// Calculate vector from sphere center to point
	// 	if (curr.obj.sphere.origin)
	// 	{
	// 		w_normal.data[0][0] = w_point.data[0][0] - curr.obj.sphere.origin.data[0][0];
	// 		w_normal.data[1][0] = w_point.data[1][0] - curr.obj.sphere.origin.data[1][0];
	// 		w_normal.data[2][0] = w_point.data[2][0] - curr.obj.sphere.origin.data[2][0];
	// 	}
	// 	else
	// 	{
	// 		w_normal.data[0][0] = w_point.data[0][0];
	// 		w_normal.data[1][0] = w_point.data[1][0];
	// 		w_normal.data[2][0] = w_point.data[2][0];
	// 	}
	// 	w_normal.data[3][0] = 0;
	// 	matrix_normalize(w_normal);
	// 	return (w_normal);
	// }
	
	// Calculate normal using transform matrix
	w_normal = matrix_inverse(curr.obj.sphere.transform);
	if (!w_normal)
		return (NULL);
	
	o_point = matrix_multiple(w_normal, w_point);
	if (!o_point)
	{
		free_matrix(w_normal);
		return (NULL);
	}
	
	o_normal = matrix_clone(o_point);
	if (!o_normal)
	{
		free_matrix(w_normal);
		free_matrix(o_point);
		return (NULL);
	}
	
	o_normal.data[3][0] = 0;
	temp = matrix_transpose(w_normal);

	
	w_normal = matrix_multiple(temp, o_normal);
	free_matrix(temp);
	free_matrix(o_normal);
	free_matrix(o_point);
	
	w_normal.data[3][0] = 0;
	matrix_normalize(w_normal);
	return (w_normal);
}


// t_matrix	*sphere_normal(t_object *curr, t_matrix *w_point)
// {
// 	t_matrix	*o_point;
// 	t_matrix	*o_normal;
// 	t_matrix	*w_normal;
// 	t_matrix	*temp;

// 	w_normal = matrix_inverse(curr->obj.sphere.transform);
// 	o_point = matrix_multiple(w_normal, w_point);
// 	o_normal = matrix_clone(o_point);
// 	// o_normal->data[3][0] = 0;
// 	temp = matrix_transpose(w_normal);
// 	free_matrix(w_normal);
// 	w_normal = matrix_multiple(temp, o_normal);
// 	free_matrix(temp);
// 	free_matrix(o_normal);
// 	free_matrix(o_point);
// 	w_normal->data[3][0] = 0;
// 	matrix_normalize(w_normal);
// 	return (w_normal);
// }