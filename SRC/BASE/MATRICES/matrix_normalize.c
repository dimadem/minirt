/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_normalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:36:52 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/14 14:36:53 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"

void	matrix_normalize(t_matrix *matrix)
{
	double	len;

	len = matrix_length(matrix);
	if (len == 0)
		return ;
	matrix->data[0][0] /= len;
	matrix->data[1][0] /= len;
	matrix->data[2][0] /= len;
}
