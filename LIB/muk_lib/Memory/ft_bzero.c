/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:20:31 by mcoskune          #+#    #+#             */
/*   Updated: 2024/11/14 12:41:33 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../muk_lib.h"

//This function will fill n bytes of space pointed by the `s` pointer with null

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
	{
		*p++ = '\0';
	}
}
