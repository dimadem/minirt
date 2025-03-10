/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_scalar_mult.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:37:02 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/14 14:37:03 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	matrix_scalar_mult(t_matrix *matrix, double scalar)
{
	if (matrix == NULL)
		return ;
	matrix->data[0][0] *= scalar;
	matrix->data[1][0] *= scalar;
	matrix->data[2][0] *= scalar;
	matrix->data[3][0] *= scalar;
}
