/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:56:37 by mcoskune          #+#    #+#             */
/*   Updated: 2024/12/03 11:48:13 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../muk_lib.h"

static double	ft_atod_decimal(char *str, int i)
{
	int		j;
	double	dec;

	j = ft_strlen(str) - 1;
	dec = 0.0;
	while ((str[j] == ' ' || str[j] == '\t' || str[j] == '\n') && j > i)
		j--;
	while (j > i)
	{
		dec = dec / 10 + (str[j] - '0');
		j--;
	}
	dec /= 10;
	return (dec);
}

double	ft_atod(char *str)
{
	double	num;
	int		sign;
	int		i;

	num = 0.0;
	sign = 1;
	i = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] != '\n' && \
			(ft_isdigit(str[i]) || str[i] == '.'))
	{
		if (str[i] == '.')
		{
			num += ft_atod_decimal(str, i);
			break ;
		}
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (sign * num);
}
