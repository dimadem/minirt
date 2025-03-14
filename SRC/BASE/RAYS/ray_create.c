/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:11:01 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/02 13:23:07 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "muk_lib.h"

t_ray	*ray_create(t_matrix *origin, t_matrix *direction)
{
	t_ray	*temp;

	temp = safe_malloc(sizeof(t_ray), 1);
	if (temp == NULL)
		return (NULL);
	temp->origin = origin;
	temp->direction = direction;
	return (temp);
}

t_ray	ray_create_local(t_matrix *origin, t_uv *direction)
{
	t_ray	temp;

	temp.origin = origin;
	temp.direction->data[0][0] = direction->u;
	temp.direction->data[1][0] = direction->v;
	return (temp);
}
