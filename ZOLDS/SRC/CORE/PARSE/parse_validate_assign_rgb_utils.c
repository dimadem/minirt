/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validate_assign_rgb_utils.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:08:57 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/12/03 12:12:48 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_parse.h"
#include "muk_lib.h"
#include "libft.h"

bool	validate_rgb_string(char *rgb_str)
{
	return (ft_strval(rgb_str, "+,", 1) == 0);
}

bool	split_and_validate_components(char *rgb_str, char ***dptr)
{
	int	length;

	*dptr = ft_split(rgb_str, ',');
	if (*dptr == NULL)
		return (false);
	length = parse_check_length(*dptr);
	if (length != 3 && length != 4)
	{
		free_dptr((void **)*dptr);
		return (false);
	}
	return (true);
}

void	parse_transparency(char **dptr, t_trgb *colour)
{
	if (parse_check_length(dptr) == 4)
	{
		check_range(-1, 0, 255, dptr[0]);
		colour->t = ft_atoi(dptr[0]);
	}
	else
		colour->t = 0;
}

bool	validate_rgb_ranges(char **dptr, int start_index)
{
	int	i;

	i = start_index;
	while (dptr[i] != NULL)
	{
		if (check_range(-1, 0, 255, dptr[i]) != 0)
			return (false);
		i++;
	}
	return (true);
}

void	assign_rgb_values(char **dptr, t_trgb *colour, int start_index)
{
	colour->r = ft_atoi(dptr[start_index]);
	colour->g = ft_atoi(dptr[start_index + 1]);
	colour->b = ft_atoi(dptr[start_index + 2]);
}
