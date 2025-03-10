/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:23:40 by mcoskune          #+#    #+#             */
/*   Updated: 2024/12/02 18:03:22 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../muk_lib.h"

int	check_range(long double num, long double low, long double high, char *str)
{
	long double	new_num;

	if (str != NULL)
		new_num = ft_atod(str);
	else
		new_num = num;
	if (low <= new_num && new_num <= high)
		return (0);
	else if (low > new_num)
		return (-1);
	else if (new_num > high)
		return (1);
	return (2);
}
