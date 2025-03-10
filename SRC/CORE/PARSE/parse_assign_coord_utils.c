/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_assign_coord_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:08:09 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/02 13:33:37 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_parse.h"
#include "muk_lib.h"

bool	validate_input_string(const char *str)
{
	return (ft_strval((char *)str, "+-,.", 1) == 0);
}

char	**split_coordinates(const char *str)
{
	return (ft_split(str, ','));
}

bool	validate_coordinate_values(char **coordinates, int expected_length)
{
	int	i;

	if (parse_check_length(coordinates) != expected_length)
		return (false);
	i = 0;
	while (coordinates[i] != NULL)
	{
		if (check_range(-1, INT_MIN, INT_MAX, coordinates[i]) != 0)
			return (false);
		i++;
	}
	return (true);
}

void	assign_coordinates(char **coordinates, t_matrix *origin)
{
	int	i;

	i = 0;
	origin->data[0][0] = ft_atod(coordinates[i++]);
	origin->data[1][0] = ft_atod(coordinates[i++]);
	origin->data[2][0] = ft_atod(coordinates[i]);
	origin->data[3][0] = 1;
}
