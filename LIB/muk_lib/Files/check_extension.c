/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:08:14 by mcoskune          #+#    #+#             */
/*   Updated: 2024/12/09 15:05:39 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../muk_lib.h"

/**
 * @brief Function specifically checking if the given file has expected
 * extension.
 * @param filename Entire name of the file
 * @param extension The expected extension format. Albeit it is not checked,
 * it is expected to start with `.`. For instance `.txt`.
 * @return Function returns `0` if the extension is correct or `a positive int`
 * if the value is wrong
 */
int	check_extension(char *filename, char *extension)
{
	int	i;
	int	j;

	if (filename == NULL || extension == NULL)
		return (1);
	i = ft_strlen(filename) - ft_strlen(extension);
	j = 0;
	while (filename[i] != '\0')
	{
		if (filename[i++] != extension[j++])
			return (2);
	}
	return (0);
}
