/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:36:23 by mcoskune          #+#    #+#             */
/*   Updated: 2024/12/30 12:09:08 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"

t_matrix	*object_translation(double x, double y, double z)
{
	t_matrix	*translate;

	translate = matrix_identity(4);
	translate->data[0][3] = x;
	translate->data[1][3] = y;
	translate->data[2][3] = z;
	return (translate);
}
