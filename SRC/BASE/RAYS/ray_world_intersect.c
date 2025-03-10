/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_world_intersect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:03:10 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/20 12:14:03 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "base_rays.h"
#include "muk_lib.h"

static void	sort_w_isect(t_isect **w_isect)
{
	t_isect	*temp;
	int		i;

	i = 0;
	while (w_isect[i + 1] != NULL)
	{
		if (w_isect[i]->t_val > w_isect[i + 1]->t_val)
		{
			temp = w_isect[i + 1];
			w_isect[i + 1] = w_isect[i];
			w_isect[i] = temp;
			i = 0;
		}
		else
			i++;
	}
	w_isect[0]->count = i + 1;
}

t_isect	**ray_intersect_world(t_rayt *lux, t_ray *ray)
{
	t_isect		**w_inter;
	t_isect		**inter;
	int			i;
	int			j;

	if (!lux || !ray)
		return (NULL);
	w_inter = NULL;
	i = -1;
	while (lux->objects[++i])
	{
		inter = ray_intersect_sphere(lux->objects[i], ray);
		j = 0;
		while (j < 2)
		{
			inter[j]->obj_id = i;
			inter[j]->obj_type = lux->objects[i]->type;
			add_to_dptr((void ***)&w_inter, (void *)inter[j++]);
		}
		free(inter);
	}
	sort_w_isect(w_inter);
	return (w_inter);
}
