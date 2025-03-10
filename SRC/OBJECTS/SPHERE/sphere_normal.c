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

	w_normal = matrix_inverse(curr->obj.sphere.transform);
	o_point = matrix_multiple(w_normal, w_point);
	o_normal = matrix_clone(o_point);
	o_normal->data[3][0] = 0;
	temp = matrix_transpose(w_normal);
	free_matrix(w_normal);
	w_normal = matrix_multiple(temp, o_normal);
	free_matrix(temp);
	free_matrix(o_normal);
	free_matrix(o_point);
	w_normal->data[3][0] = 0;
	matrix_normalize(w_normal);
	return (w_normal);
}
