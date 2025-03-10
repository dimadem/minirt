/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:45:37 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/24 15:49:58 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

t_tuple	tuple_create(double x, double y, double z, int w)
{
	t_tuple	a;

	a.x = x;
	a.y = y;
	a.z = z;
	a.w = w;
	return (a);
}
