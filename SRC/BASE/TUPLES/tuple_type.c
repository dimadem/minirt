/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:57:48 by mcoskune          #+#    #+#             */
/*   Updated: 2024/12/23 01:15:46 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

int	tuple_type(t_tuple *tuple)
{
	if (tuple->w == 0)
		return (0);
	else if (tuple->w == 1)
		return (1);
	else
		return (-1);
}
