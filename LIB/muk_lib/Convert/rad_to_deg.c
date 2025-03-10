/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rad_to_deg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:30:52 by mcoskune          #+#    #+#             */
/*   Updated: 2024/11/25 22:34:28 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../muk_lib.h"

//	Conversion from radians to degrees.
double	rad_to_deg(double radian)
{
	double	deg;

	if (radian > 0)
	{
		while (radian > 2 * M_PI)
			radian -= 2 * M_PI;
	}
	else if (radian < 0)
	{
		while (radian < -2 * M_PI)
			radian += 2 * M_PI;
	}
	deg = 360 * radian / (2 * M_PI);
	return (deg);
}
