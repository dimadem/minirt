/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:58:41 by mcoskune          #+#    #+#             */
/*   Updated: 2024/12/09 15:11:31 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../muk_lib.h"

/**
 * @brief Function to check if a file passed with `filename` can be opened.
 * @param filename Name of the file we are trying to access.
 * @param flag Indicator of open type. `flag == 0` will check `O_RDONLY`, 
 * `flag == 1` will check `O_WRONLY`, and `flag == 2` will check `O_RDWR`.
 * @return Function will return `0` if file can be accessed with given
 * permission and `1` if a failure is encountered.
 * @warning This function does not return a fd! If file can be opened 
 * succesfully, file will be closed to avoid fd leak!
 */
int	check_access(char *filename, int flag)
{
	int	i;

	i = -1;
	if (flag == 0)
	{
		i = open(filename, O_RDONLY);
		if (i == -1)
			return (1);
	}
	else if (flag == 1)
	{
		i = open(filename, O_WRONLY);
		if (i == -1)
			return (1);
	}
	else if (flag == 2)
	{
		i = open(filename, O_RDWR);
		if (i == -1)
			return (1);
	}
	if (i != -1)
		close (i);
	return (0);
}
