/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:56:00 by mcoskune          #+#    #+#             */
/*   Updated: 2024/11/25 22:33:53 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../muk_lib.h"

void	*safe_malloc(unsigned int size_of_type, int num_of_obj)
{
	void	*ptr;
	int		i;
	int		byte;

	ptr = NULL;
	byte = size_of_type * num_of_obj;
	ptr = (void *)malloc(byte);
	if (!ptr)
	{
		i = write(2, "Malloc Attempt Failed", 22);
		(void) i;
		return (NULL);
	}
	ft_bzero(ptr, byte);
	return (ptr);
}
