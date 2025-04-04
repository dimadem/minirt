/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:12:59 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/07 22:18:04 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_parse.h"
#include "core_cleanup.h"
#include "muk_lib.h"
#include "libft.h"

t_type	parse_obj_type(char *str)
{
	if (str[0] == 'A' && str[1] == '\0')
		return (AMBIENT);
	else if (str[0] == 'C' && str[1] == '\0')
		return (CAMERA);
	else if (str[0] == 'L' && str[1] == '\0')
		return (LIGHT);
	else if (str[0] == 's' && str[1] == 'p' && str[2] == '\0')
		return (SPHERE);
	else if (str[0] == 'p' && str[1] == 'l' && str[2] == '\0')
		return (PLANE);
	else if (str[0] == 'c' && str[1] == 'y' && str[2] == '\0')
		return (CYLINDER);
	else if (str[0] == '\n' || str[0] == '\0')
		return (EMPTY);
	else
		return (ERROR);
}

void	parse_func_redir(t_parse *pars, char **split_line)
{
	t_type	type;

	if (split_line[0] == NULL)
		return ;
	type = parse_obj_type(split_line[0]);
	if (type == AMBIENT)
		parse_ambient(pars, split_line);
	else if (type == CAMERA)
		parse_camera(pars, split_line);
	else if (type == LIGHT)
		parse_light(pars, split_line);
	else if (type == SPHERE)
		parse_sphere(pars, split_line);
	else if (type == PLANE)
		parse_plane(pars, split_line);
	else if (type == CYLINDER)
		parse_cylinder(pars, split_line);
	else if (type == EMPTY)
		return ;
	else
		pars->error_encountered = true;
}

/**
 * @brief Processes a single line from the .rt file
 * @param pars Parser structure
 * @param line The line to process
 */
static void	process_single_line(t_parse *pars, char *line)
{
	char	**split_line;

	if (!line || pars->error_encountered)
		return;
		
	split_line = ft_split(line, ' ');
	if (split_line != NULL && pars->error_encountered == false)
		parse_func_redir(pars, split_line);
		
	free_dptr((void **)split_line);
}

/**
 * @brief Checks if the file is empty and handles the error
 * @param lux Ray tracer structure
 * @param line The first line read from the file
 */
static void	check_empty_file(t_rayt *lux, char *line)
{
	if (line == NULL)
	{
		close(lux->file_fd);
		exit_cleanup("Error - Empty File!\n", lux, -6);
	}
}

/**
 * @brief Reads lines from the .rt file, splits each line by space,
 * and passes the split lines to processing functions.
 * @param lux Ray tracer structure
 * @param pars Parser structure
 */
void	parse_rt_read_line(t_rayt *lux, t_parse *pars)
{
	char	*line;

	line = get_next_line(lux->file_fd);
	check_empty_file(lux, line);
	
	while (line != NULL)
	{
		process_single_line(pars, line);
		free(line);
		line = get_next_line(lux->file_fd);
	}
}

/**
 * @brief Entry function to parsing .rt file where the file is attempted 
 * to be opened, t_parse structure is initialized and 
 * neccessary functions are called.
 */

void	parse_rt_main(char **av, t_rayt *lux)
{
	t_parse	pars;

	if (av == NULL || lux == NULL)
		exit_cleanup("Error - Parse - NULL Input\n", lux, -5);
	lux->file_fd = open(av[1], O_RDONLY);
	if (lux->file_fd == -1)
		exit_cleanup("Error - Open Failed!\n", lux, errno);
	init_pars(&pars);
	pars.lux = lux;
	parse_rt_read_line(lux, &pars);
	close(lux->file_fd);
	lux->file_fd = -1;
	if (pars.count_a > 1 || pars.count_c > 1 || pars.count_l > 1)
		pars.error_encountered = true;
	if (pars.error_encountered == true)
		exit_cleanup("Error - Syntax Error! (.rt)\n", lux, -9);
}
