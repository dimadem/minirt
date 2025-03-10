/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:36:40 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/14 14:36:41 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include <math.h>

double	matrix_length(t_matrix *matrix)
{
	return (sqrt(pow(matrix->data[0][0], 2) + \
			pow(matrix->data[1][0], 2) + pow(matrix->data[2][0], 2)));
}
