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

/**
 * Sorts an array of intersections by their t-values in ascending order.
 * Uses bubble sort algorithm for simplicity. Also stores the count of
 * intersections in the first element's count field.
 * 
 * Error handling: Returns silently if input is NULL or empty.
 * Resource management: No memory allocation or deallocation.
 * 
 * @param w_isect The array of intersections to sort
 */
static void	sort_w_isect(t_isect **w_isect)
{
	t_isect	*temp;
	int		i;
	int		j;
	int		count;

	if (!w_isect)
		return;
	
	// Count the number of intersections
	count = 0;
	while (w_isect[count] != NULL)
		count++;
	
	if (count <= 0)
		return;
		
	// Bubble sort by t-value
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
	
	// Store the count for later use
	w_isect[0]->count = count;
}

/**
 * Dispatches to the appropriate intersection function based on object type.
 * 
 * Error handling: Returns NULL if input parameters are invalid or if
 * the object type is unknown.
 * Resource management: Delegates to type-specific intersection functions.
 * 
 * @param obj The object to test for intersection
 * @param ray The ray to test for intersection
 * @return Array of intersections or NULL if none exist or on error
 */
static t_isect **get_intersections(t_object *obj, t_ray *ray)
{
	if (!obj || !ray)
		return (NULL);
	
	printf("DEBUG: get_intersections checking object of type %d\n", obj->type);
		
	// Dispatch to the appropriate intersection function based on object type
	switch (obj->type)
	{
		case SPHERE:
			printf("DEBUG: Testing intersection with SPHERE\n");
			return (ray_intersect_sphere(obj, ray));
		case PLANE:
			printf("DEBUG: Testing intersection with PLANE\n");
			return (ray_intersect_plane(obj, ray));
		case CYLINDER:
			printf("DEBUG: Testing intersection with CYLINDER\n");
			return (ray_intersect_cylinder(obj, ray));
		default:
			printf("DEBUG: Unknown object type: %d\n", obj->type);
			return (NULL);  // Unknown object type
	}
}

/**
 * Finds all intersections between a ray and objects in the scene.
 * Collects intersections from all objects, adds metadata, and sorts by t-value.
 * 
 * Error handling: Returns NULL if input parameters are invalid.
 * Resource management: Transfers ownership of individual intersection records
 * to the returned array. Caller is responsible for freeing the returned array
 * and all its contents with free_dptr.
 * 
 * @param lux The scene data structure containing all objects
 * @param ray The ray to test for intersections
 * @return Array of all intersections sorted by t-value, or NULL on error
 */
t_isect	**ray_intersect_world(t_rayt *lux, t_ray *ray)
{
	t_isect		**w_inter;
	t_isect		**inter;
	int			i;
	int			j;

	if (!lux || !ray || !lux->objects)
		return (NULL);
		
	w_inter = NULL;
	i = -1;
	while (lux->objects[++i])
	{
		// Get intersections for the current object
		inter = get_intersections(lux->objects[i], ray);
		if (!inter)
			continue;  // Skip to next object if no intersections
			
		// Process all intersections
		j = 0;
		while (inter[j] != NULL)
		{
			// Add metadata to each intersection
			inter[j]->obj_id = i;
			inter[j]->obj_type = lux->objects[i]->type;
			
			// Transfer ownership to the world intersection array
			if (add_to_dptr((void ***)&w_inter, (void *)inter[j++]))
			{
				// Handle allocation failure in add_to_dptr
				// Note: We don't free existing elements in w_inter as they're still needed
				free(inter);
				return (w_inter);  // Return what we have so far
			}
		}
		
		// Free only the array container, contents were transferred to w_inter
		free(inter);
	}
	
	// Sort intersections by t-value for proper rendering
	if (w_inter)
		sort_w_isect(w_inter);
	
	return (w_inter);
}
