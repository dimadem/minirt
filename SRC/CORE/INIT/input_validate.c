/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:48:22 by mcoskune          #+#    #+#             */
/*   Updated: 2024/12/09 15:11:53 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "muk_lib.h"
#include "core_cleanup.h"

/**
 * @brief Validating if argument count is 2 (exe and 1 extra) and the extra is
 * a .rt file and we have permission to access to the said file.
 */
void	input_validate(int ac, char **av)
{
	if (ac != 2)
		exit_cleanup("Error - Wrong AC\n", NULL, -1);
	if (ft_strlen(av[1]) <= 3)
		exit_cleanup("Error - File name too short!\n", NULL, -2);
	if (check_extension(av[1], ".rt") != 0)
		exit_cleanup("Error - Wrong file extension!\n", NULL, -3);
	if (check_access(av[1], 0) != 0)
		exit_cleanup("Error - File Permissions!\n", NULL, -4);
}
