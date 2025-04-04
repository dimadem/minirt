/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:38:31 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/07 16:53:54 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "libft.h"

/**
 * @brief This function convert t_trgb to char pointer
 * @param addr part of t_lux.image
 * @param colour t_trgb formated colour
 * addr[0] = (unsigned char)colour.b;        // Blue
 * addr[1] = (unsigned char)colour.g;        // Green
 * addr[2] = (unsigned char)colour.r;        // Red
 * addr[3] = (unsigned char)colour.t;        // Alpha/Transparency
 */
void	t_trgb_to_addr(char *addr, t_trgb colour)
{
	addr[0] = (unsigned char)colour.b;
	addr[1] = (unsigned char)colour.g;
	addr[2] = (unsigned char)colour.r;
	addr[3] = (unsigned char)colour.t;
}

int	t_trgb_to_hex(t_trgb c)
{
	return (((int)c.t << 24) | ((int)c.r << 16) | \
			((int)c.g << 8) | (int)c.b);
}

char	*join_rgb_values(unsigned char r, unsigned char g, unsigned char b)
{
	char	*r_str;
	char	*g_str;
	char	*b_str;
	char	*temp;
	char	*result;

	r_str = ft_itoa(r);
	g_str = ft_itoa(g);
	b_str = ft_itoa(b);
	temp = ft_strjoin(r_str, " ");
	free(r_str);
	result = ft_strjoin(temp, g_str);
	free(temp);
	temp = ft_strjoin(result, " ");
	free(result);
	result = ft_strjoin(temp, b_str);
	free(temp);
	temp = ft_strjoin(result, " ");
	free(result);
	free(g_str);
	free(b_str);
	return (temp);
}
