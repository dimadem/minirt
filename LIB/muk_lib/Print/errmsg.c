/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errmsg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:14:05 by mcoskune          #+#    #+#             */
/*   Updated: 2024/12/04 20:21:41 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../muk_lib.h"

void	errmsg(char *msg)
{
	int	i;
	int	count;

	if (msg == NULL)
		return ;
	i = 0;
	while (msg[i] != '\0')
	{
		count = write(2, &msg[i], 1);
		i++;
	}
	(void) count;
}
