/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:35:35 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/24 15:33:06 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"

t_matrix	*object_scaling(double x, double y, double z)
{
	t_matrix	*scale;

	scale = matrix_identity(4);
	scale->data[0][0] = x;
	scale->data[1][1] = y;
	scale->data[2][2] = z;
	return (scale);
}
