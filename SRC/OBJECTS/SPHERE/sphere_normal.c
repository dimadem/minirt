/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:22:08 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/05 18:33:51 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"

t_matrix	*sphere_normal(t_object *curr, t_matrix *w_point)
{
	t_matrix	*o_point;
	t_matrix	*o_normal;
	t_matrix	*w_normal;
	t_matrix	*temp;

	// Add null checks for parameters
	if (!curr || !w_point)
		return (NULL);
	
	// Check for sphere transform existence
	if (!curr->obj.sphere.transform)
	{
		// If no transform exists, create a default normal (pointing outward from origin)
		w_normal = matrix_create(4, 1);
		if (!w_normal)
			return (NULL);
			
		// Calculate vector from sphere center to point
		if (curr->obj.sphere.origin)
		{
			w_normal->data[0][0] = w_point->data[0][0] - curr->obj.sphere.origin->data[0][0];
			w_normal->data[1][0] = w_point->data[1][0] - curr->obj.sphere.origin->data[1][0];
			w_normal->data[2][0] = w_point->data[2][0] - curr->obj.sphere.origin->data[2][0];
		}
		else
		{
			w_normal->data[0][0] = w_point->data[0][0];
			w_normal->data[1][0] = w_point->data[1][0];
			w_normal->data[2][0] = w_point->data[2][0];
		}
		w_normal->data[3][0] = 0;
		matrix_normalize(w_normal);
		return (w_normal);
	}
	
	// Calculate normal using transform matrix
	w_normal = matrix_inverse(curr->obj.sphere.transform);
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
	
	o_normal->data[3][0] = 0;
	temp = matrix_transpose(w_normal);
	free_matrix(w_normal);
	
	if (!temp)
	{
		free_matrix(o_point);
		free_matrix(o_normal);
		return (NULL);
	}
	
	w_normal = matrix_multiple(temp, o_normal);
	free_matrix(temp);
	free_matrix(o_normal);
	free_matrix(o_point);
	
	if (!w_normal)
		return (NULL);
	
	w_normal->data[3][0] = 0;
	matrix_normalize(w_normal);
	return (w_normal);
}
