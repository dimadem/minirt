/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:00:00 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/03/11 15:00:00 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_matrices.h"
#include "objects_plane.h"

t_matrix	*plane_normal(t_object *curr, t_matrix *point)
{
	t_matrix	*normal;

	// For planes, the normal is always the same regardless of intersection point
	(void)point;  // Unused parameter

	// Add null checks for parameters
	if (!curr || curr->type != PLANE || !curr->obj.plane.v_orient)
		return (NULL);
	
	// Clone the orientation vector for the normal
	normal = matrix_clone(curr->obj.plane.v_orient);
	if (!normal)
		return (NULL);
	
	// Ensure it's a proper vector (w = 0)
	normal->data[3][0] = 0;
	
	// Normalize the vector
	matrix_normalize(normal);
	
	return (normal);
}