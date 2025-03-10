/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_negating.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:49:45 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/12/23 16:50:10 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

/**
 * @brief This function is used to negating tuple. Like a => -a
 * @param a takes pointer of current t_tuple and negating it.
 * @warning This function modifies the passed tuple. Therefore, there is no
 * return type.
 */
void	tuple_negating(t_tuple *a)
{
	a->w = a->w * -1;
	a->x = a->x * -1;
	a->y = a->y * -1;
	a->z = a->z * -1;
}
