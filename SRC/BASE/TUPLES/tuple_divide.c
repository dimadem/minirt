/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_divide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:49:02 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/12/23 16:49:39 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

/**
 * @brief Divide a given tuple with a scalar value. 
 * This does not change the orientation of the
 * vector, only its direction and/or its magnitude.
 * @warning This function modifies the passed tuple. Therefore, there is no
 * return type.
 */
void	tuple_scalar_divide(t_tuple *a, double scalar)
{
	a->x = a->x / scalar;
	a->y = a->y / scalar;
	a->z = a->z / scalar;
	a->w = a->w / scalar;
}
