/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:31:11 by mcoskune          #+#    #+#             */
/*   Updated: 2024/12/03 11:47:49 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../muk_lib.h"

//	Checks if given string contains any characters that is not allowed
//	Exempt is string of characters that is acceptable besides normal

static int	check_exempt(char c, char *exempt)
{
	int	j;

	j = 0;
	if (exempt == NULL)
		return (0);
	while (exempt[j] != '\0')
	{
		if (c == exempt[j])
			return (1);
		j++;
	}
	return (0);
}

/**
* @brief Checks if a given string consists of valid characters.
* @param char *exempt - 
* Whitelisted string of characters or NULL for no exceptions
* @param int flag - 
* Type of check where `flag = 0` for CHAR, `flag = 1` for INT and
* `flag = 2` for ALNUM
* @warning For int numbers if symbols `+` or `-` can be given in exempt.
* However, this function cannot differentiate `-2` from `2-` and will validate
* both input as correct!
*/
int	ft_strval(char *str, char *exempt, int flag)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (flag == 0 && !ft_isalpha(str[i]))
		{
			if (check_exempt(str[i], exempt) == 0)
				return (1);
		}
		else if (flag == 1 && !ft_isdigit(str[i]))
		{
			if (check_exempt(str[i], exempt) == 0)
				return (2);
		}
		else if (flag == 2 && !ft_isalnum(str[i]))
		{
			if (check_exempt(str[i], exempt) == 0)
				return (3);
		}
		i++;
	}
	return (0);
}
