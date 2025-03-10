/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_assign_vec_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:09:34 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/07 21:54:04 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "muk_lib.h"
#include "libft.h"

bool	is_valid_format(char *str)
{
	return (ft_strval(str, "+-.,", 1) == 0);
}

bool	parse_vector_components(char **dptr, t_matrix *orient)
{
	int	i;

	i = 0;
	while (dptr[i] != NULL)
	{
		if (check_range(-1, -1, 1, dptr[i]) != 0)
			return (false);
		i++;
	}
	i -= 3;
	orient->data[0][0] = ft_atod(dptr[i++]);
	orient->data[1][0] = ft_atod(dptr[i++]);
	orient->data[2][0] = ft_atod(dptr[i]);
	orient->data[3][0] = 0;
	return (true);
}

char	**split_vector_string(char *str)
{
	return (ft_split(str, ','));
}
