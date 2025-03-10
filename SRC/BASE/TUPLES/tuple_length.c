/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:05:06 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/03 15:11:54 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include <math.h>

/**
 * @brief This function is used to calculate length of vectors using the
 * x^2 + y^2 + z^2 = len^2 and finding the len.
 * @warning This function does not include the `w` component.
 * @return This function returns a `double` value.
 */
double	tuple_length(t_tuple *tuple)
{
	return (sqrt(pow(tuple->x, 2) + pow(tuple->y, 2) + pow(tuple->z, 2)));
}
