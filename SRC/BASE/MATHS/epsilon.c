/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epsilon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:47:23 by mcoskune          #+#    #+#             */
/*   Updated: 2025/04/04 13:01:38 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

/**
 * @brief EPSILON function that checks if 2 doubles are equivalent. This
 * function is needed as round off errors can cause issues when comparing
 * doubles
 * @return `1` if they are equal, `0` if they are not
 */
int	epsilon(double a, double b)
{
	if (fabs(a - b) <= 0.0001)
		return (1);
	return (0);
}
