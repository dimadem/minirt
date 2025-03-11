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
	int		j;
	int		count;

	if (!w_isect)
		return;
	
	count = 0;
	while (w_isect[count] != NULL)
		count++;
	
	if (count <= 0)
		return;
		
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (w_isect[j]->t_val > w_isect[j + 1]->t_val)
			{
				temp = w_isect[j];
				w_isect[j] = w_isect[j + 1];
				w_isect[j + 1] = temp;
			}
		}
	}
	
	w_isect[0]->count = count;
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
		if (inter)  // Only process if intersections were found
		{
			j = 0;
			while (j < 2)
			{
				inter[j]->obj_id = i;
				inter[j]->obj_type = lux->objects[i]->type;
				add_to_dptr((void ***)&w_inter, (void *)inter[j++]);
			}
			free(inter);
		}
	}
	// Only sort if we have intersections
	if (w_inter)
		sort_w_isect(w_inter);
	
	return (w_inter);
}
