/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:13:10 by mcoskune          #+#    #+#             */
/*   Updated: 2025/04/08 10:53:57 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// int	colour_to_int(t_trgb data)
// {
// 	int	r;
// 	int	g;
// 	int	b;

// 	r = (int)(data.r * 255);
// 	g = (int)(data.g * 255);
// 	b = (int)(data.b * 255);
// 	if (r < 0)
// 		r = 0;
// 	if (r > 255)
// 		r = 255;
// 	if (g < 0)
// 		g = 0;
// 	if (g > 255)
// 		g = 255;
// 	if (b < 0)
// 		b = 0;
// 	if (b > 255)
// 		b = 255;
// 	return ((r << 16) | (g << 8) | b);
// }

// void	t_trgb_to_addr(char *addr, t_trgb colour)
// {
// 	addr[0] = (unsigned char)colour.b;
// 	addr[1] = (unsigned char)colour.g;
// 	addr[2] = (unsigned char)colour.r;
// 	addr[3] = (unsigned char)colour.t;
// }

// int	t_trgb_to_hex(t_trgb c)
// {
// 	return (((int)c.t << 24) | ((int)c.r << 16) | ((int)c.g << 8) | (int)c.b);
// }

// char	*join_rgb_values(unsigned char r, unsigned char g, unsigned char b)
// {
// 	char	*r_str;
// 	char	*g_str;
// 	char	*b_str;
// 	char	*temp;
// 	char	*result;

// 	r_str = ft_itoa(r);
// 	g_str = ft_itoa(g);
// 	b_str = ft_itoa(b);
// 	temp = ft_strjoin(r_str, " ");
// 	free(r_str);
// 	result = ft_strjoin(temp, g_str);
// 	free(temp);
// 	temp = ft_strjoin(result, " ");
// 	free(result);
// 	result = ft_strjoin(temp, b_str);
// 	free(temp);
// 	temp = ft_strjoin(result, " ");
// 	free(result);
// 	free(g_str);
// 	free(b_str);
// 	return (temp);
// }

t_trgb	colour_hadamard_product(t_trgb colour1, t_trgb colour2)
{
	t_trgb	temp;

	temp.t = 0;
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

t_trgb	colour_subs(t_trgb colour1, t_trgb colour2)
{
	t_trgb	temp;

	temp.t = 0;
	temp.r = colour1.r - colour2.r;
	temp.g = colour1.g - colour2.g;
	temp.b = colour1.b - colour2.b;
	return (temp);
}

t_trgb	colour_sum(t_trgb colour1, t_trgb colour2)
{
	t_trgb	temp;

	temp.t = 0;
	temp.r = colour1.r + colour2.r;
	temp.g = colour1.g + colour2.g;
	temp.b = colour1.b + colour2.b;
	return (temp);
}



t_trgb	colour_create(double red, double green, double blue)
{
	t_trgb	colour;

	colour.t = 0;
	colour.r = red;
	colour.g = green;
	colour.b = blue;
	return (colour);
}
