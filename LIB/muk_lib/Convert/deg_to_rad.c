/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deg_to_rad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:14:40 by mcoskune          #+#    #+#             */
/*   Updated: 2024/12/23 13:54:30 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../muk_lib.h"

//	Conversion from degrees to radians.
double	deg_to_rad(double degree)
{
	double	rad;

	if (degree > 0)
	{
		while (degree > 360)
			degree -= 360;
	}
	else if (degree < 0)
	{
		while (degree < -360)
			degree += 360;
	}
	rad = 2 * M_PI * degree / 360;
	return (rad);
}
