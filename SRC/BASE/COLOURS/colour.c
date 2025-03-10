/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:13:10 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/08 16:17:04 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

t_trgb	colour_hadamard_product(t_trgb colour1, t_trgb colour2)
{
	t_trgb	temp;

	temp.t = 255;
	temp.r = colour1.r * colour2.r;
	temp.g = colour1.g * colour2.g;
	temp.b = colour1.b * colour2.b;
	return (temp);
}

t_trgb	colour_scalar_mult(t_trgb colour, double num)
{
	t_trgb	temp;

	temp.t = 0;
	temp.r = colour.r * num;
	temp.g = colour.g * num;
	temp.b = colour.b * num;
	return (temp);
}

t_trgb	colour_sum(t_trgb colour1, t_trgb colour2)
{
	t_trgb	temp;

	temp.t = 255;
	temp.r = colour1.r + colour2.r;
	temp.g = colour1.g + colour2.g;
	temp.b = colour1.b + colour2.b;
	return (temp);
}

t_trgb	colour_subs(t_trgb colour1, t_trgb colour2)
{
	t_trgb	temp;

	temp.t = 255;
	temp.r = colour1.r - colour2.r;
	temp.g = colour1.g - colour2.g;
	temp.b = colour1.b - colour2.b;
	return (temp);
}

t_trgb	colour(double red, double green, double blue)
{
	t_trgb	colour;

	colour.t = 255;
	colour.r = red;
	colour.g = green;
	colour.b = blue;
	return (colour);
}
