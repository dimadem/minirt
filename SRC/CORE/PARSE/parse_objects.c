/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:34:16 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/24 17:35:20 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_parse.h"
#include "base_matrices.h"
#include "muk_lib.h"
#include "objects_transform.h"
#include "objects_utils.h"

/**
 * Parses plane data from the given line and adds it to the scene.
 * Validates input, allocates memory, and initializes plane properties.
 * 
 * Error handling: Sets error_encountered flag on failure and performs cleanup.
 * Resource management: Frees allocated resources on error.
 * 
 * @param pars The parser state
 * @param split_line Array of strings containing plane parameters
 */
void	parse_plane(t_parse *pars, char **split_line)
{
	t_object	*curr;

	parse_validate_obj(pars, split_line, PLANE);
	if (pars->error_encountered)
		return;
		
	curr = (t_object *)safe_malloc(sizeof(t_object), 1);
	if (!curr)
	{
		pars->error_encountered = true;
		return;
	}
	
	curr->type = PLANE;
	curr->obj.plane.origin = matrix_create(4, 1);
	if (!curr->obj.plane.origin)
	{
		free(curr);
		pars->error_encountered = true;
		return;
	}
	
	curr->obj.plane.v_orient = matrix_create(4, 1);
	if (!curr->obj.plane.v_orient)
	{
		free_matrix(curr->obj.plane.origin);
		free(curr);
		pars->error_encountered = true;
		return;
	}
	
	parse_assign_coord(pars, split_line[1], curr->obj.plane.origin);
	parse_assign_vec(pars, split_line[2], curr->obj.plane.v_orient);
	parse_assign_trgb(pars, split_line[3], &curr->obj.plane.color);
	
	if (pars->error_encountered || 
		add_to_dptr((void ***)&pars->lux->objects, (void *)curr))
	{
		// Free resources in correct order
		free_matrix(curr->obj.plane.v_orient);
		free_matrix(curr->obj.plane.origin);
		free(curr);
		return;
	}
	
	pars->count_pl++;
}

/**
 * Creates a transformation matrix for a sphere with the given radius.
 * Combines identity and scaling matrices to create the final transform.
 * 
 * Error handling: Returns NULL on any allocation failure.
 * Resource management: Frees intermediate matrices even on success path.
 * 
 * @param radius The radius of the sphere
 * @return A transformation matrix or NULL on failure
 */
static t_matrix	*create_sphere_transform(double radius)
{
	t_matrix	*identity;
	t_matrix	*scaling;
	t_matrix	*transform;

	identity = matrix_identity(4);
	if (!identity)
		return (NULL);
		
	scaling = object_scaling(radius, radius, radius);
	if (!scaling)
	{
		free_matrix(identity);
		return (NULL);
	}
	
	transform = matrix_multiple(identity, scaling);
	
	// Always clean up intermediate matrices
	free_matrix(identity);
	free_matrix(scaling);
	
	// transform could be NULL if matrix_multiple failed
	return (transform);
}

/**
 * Initializes a sphere object from the given parameters.
 * Creates matrices for origin and transform, and sets color and radius.
 * 
 * Error handling: Returns NULL and sets error_encountered flag on failure.
 * Resource management: Frees allocated resources on error path.
 * 
 * @param pars The parser state
 * @param split_line Array of strings containing sphere parameters
 * @return An initialized sphere object or NULL on failure
 */
static t_object	*init_sphere(t_parse *pars, char **split_line)
{
	t_object	*curr;
	double		radius;

	if (!pars || !split_line)
	{
		if (pars)
			pars->error_encountered = true;
		return (NULL);
	}

	curr = (t_object *)safe_malloc(sizeof(t_object), 1);
	if (!curr)
	{
		pars->error_encountered = true;
		return (NULL);
	}
	
	curr->type = SPHERE;
	curr->obj.sphere.origin = matrix_create(4, 1);
	if (!curr->obj.sphere.origin)
	{
		free(curr);
		pars->error_encountered = true;
		return (NULL);
	}
	
	parse_assign_coord(pars, split_line[1], curr->obj.sphere.origin);
	parse_assign_trgb(pars, split_line[3], &curr->obj.sphere.color);
	
	radius = ft_atod(split_line[2]) / 2;
	curr->obj.sphere.radius = radius;
	curr->obj.sphere.transform = create_sphere_transform(radius);
	
	if (!curr->obj.sphere.transform || pars->error_encountered)
	{
		free_matrix(curr->obj.sphere.origin);
		free(curr);
		pars->error_encountered = true;
		return (NULL);
	}
	
	return (curr);
}

/**
 * Parses sphere data from the given line and adds it to the scene.
 * Uses init_sphere to create the sphere object, then adds it to the objects list.
 * 
 * Error handling: Sets error_encountered flag on failure and performs cleanup.
 * Resource management: Calls free_object on error, which handles internal matrices.
 * 
 * @param pars The parser state
 * @param split_line Array of strings containing sphere parameters
 */
void	parse_sphere(t_parse *pars, char **split_line)
{
	t_object	*curr;

	parse_validate_obj(pars, split_line, SPHERE);
	if (pars->error_encountered)
		return;
		
	curr = init_sphere(pars, split_line);
	if (!curr)
		return;
		
	if (pars->error_encountered || 
		add_to_dptr((void ***)&pars->lux->objects, (void *)curr))
	{
		// free_object handles freeing internal matrices
		free_object(curr);
		// Note: curr is already freed by free_object, do not free again
		return;
	}
	
	pars->count_sp++;
}

/**
 * Parses cylinder data from the given line and adds it to the scene.
 * Validates input, allocates memory, and initializes cylinder properties.
 * 
 * Error handling: Sets error_encountered flag on failure and performs cleanup.
 * Resource management: Frees allocated resources on error.
 * 
 * @param pars The parser state
 * @param split_line Array of strings containing cylinder parameters
 */
void	parse_cylinder(t_parse *pars, char **split_line)
{
	t_object	*curr;

	parse_validate_obj(pars, split_line, CYLINDER);
	if (pars->error_encountered)
		return;
		
	curr = (t_object *)safe_malloc(sizeof(t_object), 1);
	if (!curr)
	{
		pars->error_encountered = true;
		return;
	}
	
	curr->type = CYLINDER;
	curr->obj.cylinder.origin = matrix_create(4, 1);
	if (!curr->obj.cylinder.origin)
	{
		free(curr);
		pars->error_encountered = true;
		return;
	}
	
	curr->obj.cylinder.v_orient = matrix_create(4, 1);
	if (!curr->obj.cylinder.v_orient)
	{
		free_matrix(curr->obj.cylinder.origin);
		free(curr);
		pars->error_encountered = true;
		return;
	}
	
	parse_assign_coord(pars, split_line[1], curr->obj.cylinder.origin);
	parse_assign_vec(pars, split_line[2], curr->obj.cylinder.v_orient);
	curr->obj.cylinder.diameter = ft_atod(split_line[3]);
	curr->obj.cylinder.height = ft_atod(split_line[4]);
	parse_assign_trgb(pars, split_line[5], &curr->obj.cylinder.color);
	
	if (pars->error_encountered || 
		add_to_dptr((void ***)&pars->lux->objects, (void *)curr))
	{
		// Free resources in correct order
		free_matrix(curr->obj.cylinder.v_orient);
		free_matrix(curr->obj.cylinder.origin);
		free(curr);
		return;
	}
	
	pars->count_cy++;
}
