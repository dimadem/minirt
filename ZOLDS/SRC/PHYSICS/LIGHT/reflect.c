/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:58:28 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/03 21:27:51 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"

t_matrix	*reflect(t_matrix *incoming, t_matrix *normal)
{
	t_matrix	*temp;
	t_matrix	*v_ref;
	double		dot;

	temp = matrix_clone(normal);
	dot = matrix_dot(incoming, normal);
	matrix_scalar_mult(temp, 2 * dot);
	v_ref = matrix_subs(incoming, temp);
	free_matrix(temp);
	return (v_ref);
}
