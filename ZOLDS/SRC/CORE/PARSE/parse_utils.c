/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:46:35 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/07 22:03:26 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_parse.h"
#include "muk_lib.h"

int	parse_check_length(char **line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (line == NULL)
		return (-1);
	while (line[i] != NULL)
	{
		if (line[i][0] != ' ' && line[i][0] != '\n' && line[i][0] != '\0')
			count++;
		i++;
	}
	return (count);
}

void	parse_validate_obj(t_parse *pars, char **split_line, t_type type)
{
	bool	is_valid;

	is_valid = false;
	if (type == AMBIENT)
		is_valid = validate_ambient(split_line);
	else if (type == CAMERA)
		is_valid = validate_camera(split_line);
	else if (type == LIGHT)
		is_valid = validate_light(split_line);
	else if (type == PLANE)
		is_valid = (parse_check_length(split_line) == 4);
	else if (type == SPHERE)
		is_valid = validate_sphere(split_line);
	else if (type == CYLINDER)
		is_valid = validate_cylinder(split_line);
	if (!is_valid)
		pars->error_encountered = true;
}

void	parse_assign_trgb(t_parse *pars, char *rgb_str, t_trgb *colour)
{
	char	**dptr;
	int		start_index;

	start_index = 0;
	if (!validate_rgb_string(rgb_str))
	{
		pars->error_encountered = true;
		return ;
	}
	if (!split_and_validate_components(rgb_str, &dptr))
	{
		pars->error_encountered = true;
		return ;
	}
	parse_transparency(dptr, colour);
	if (parse_check_length(dptr) == 4)
		start_index = 1;
	if (!validate_rgb_ranges(dptr, start_index))
		pars->error_encountered = true;
	assign_rgb_values(dptr, colour, start_index);
	free_dptr((void **)dptr);
}

void	parse_assign_coord(t_parse *pars, char *str, t_matrix *origin)
{
	char	**coordinates;

	if (!validate_input_string(str))
	{
		pars->error_encountered = true;
		return ;
	}
	coordinates = split_coordinates(str);
	if (coordinates == NULL)
	{
		pars->error_encountered = true;
		return ;
	}
	if (!validate_coordinate_values(coordinates, 3))
	{
		pars->error_encountered = true;
		free_dptr((void **)coordinates);
		return ;
	}
	assign_coordinates(coordinates, origin);
	free_dptr((void **)coordinates);
}

void	parse_assign_vec(t_parse *pars, char *str, t_matrix *orient)
{
	char	**dptr;

	if (!is_valid_format(str))
	{
		pars->error_encountered = true;
		return ;
	}
	dptr = split_vector_string(str);
	if (dptr == NULL)
	{
		pars->error_encountered = true;
		return ;
	}
	if (parse_check_length(dptr) != 3)
	{
		pars->error_encountered = true;
		free_dptr((void **)dptr);
		return ;
	}
	if (!parse_vector_components(dptr, orient))
		pars->error_encountered = true;
	free_dptr((void **)dptr);
}
