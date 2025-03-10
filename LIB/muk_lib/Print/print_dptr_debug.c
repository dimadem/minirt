/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dptr_debug.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 23:23:34 by mcoskune          #+#    #+#             */
/*   Updated: 2024/12/04 19:44:45 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../muk_lib.h"

void	print_dptr_debug(void **dptr)
{
	int	i;

	if (dptr == NULL)
		return ;
	i = 0;
	while (dptr[i] != NULL)
	{
		printf("Contents pointed by ptr[%d]: %s\n", i, (char *)dptr[i]);
		i++;
	}
}
