/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validate_obj_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:12:55 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/12/03 12:15:39 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_parse.h"
#include "muk_lib.h"

bool	validate_ambient(char **split_line)
{
	return (parse_check_length(split_line) == 3 \
			&& ft_strval(split_line[1], ".+", 1) == 0 \
			&& check_range(-1, 0.0, 1.0, split_line[1]) == 0);
}

bool	validate_camera(char **split_line)
{
	return (parse_check_length(split_line) == 4 \
			&& ft_strval(split_line[3], "+", 1) == 0 \
			&& check_range(-1, 0, 180, split_line[3]) == 0);
}

bool	validate_light(char **split_line)
{
	return (parse_check_length(split_line) == 4 \
			&& ft_strval(split_line[2], "+.", 1) == 0 \
			&& check_range(-1, 0, 1, split_line[2]) == 0);
}

bool	validate_sphere(char **split_line)
{
	return (parse_check_length(split_line) == 4 \
			&& ft_strval(split_line[2], "+.", 1) == 0 \
			&& check_range(-1, 0, INT_MAX, split_line[2]) == 0);
}

bool	validate_cylinder(char **split_line)
{
	return (parse_check_length(split_line) == 6 \
			&& ft_strval(split_line[3], "+.", 1) == 0 \
			&& check_range(-1, 0, INT_MAX, split_line[3]) == 0 \
			&& ft_strval(split_line[4], "+.", 1) == 0 \
			&& check_range(-1, 0, INT_MAX, split_line[4]) == 0);
}
