/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections_feature.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:00:00 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/18 19:26:41 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

int	first_valid_intersection(t_isect **intersect)
{
	int	i;
	int	nearest;

	if (intersect == NULL)
		return (-1);
	i = 0;
	nearest = 0;
	while (i < 2)
	{
		if (intersect[i]->t_val >= 0 && \
			intersect[i]->t_val < intersect[nearest]->t_val)
			nearest = i;
		i++;
	}
	return (nearest);
}
