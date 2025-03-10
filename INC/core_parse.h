/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_parse.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:06:40 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/14 12:25:12 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_PARSE_H
# define CORE_PARSE_H

# include "types.h"
# include <errno.h>

// ************************************************************************** //
//                              PARSE_RT_FILE                                 //
// ************************************************************************** //
void	parse_rt_main(char **av, t_rayt *lux);
void	parse_rt_read_line(t_rayt *lux, t_parse *pars);
void	parse_func_redir(t_parse *pars, char **split_line);
void	init_pars(t_parse *pars);

// ************************************************************************** //
//                             SCENARIO_ELEMENTS                              //
// ************************************************************************** //
void	parse_ambient(t_parse *pars, char **split_line);
void	parse_camera(t_parse *pars, char **split_line);
void	parse_light(t_parse *pars, char **split_line);
void	parse_plane(t_parse *pars, char **split_line);
void	parse_sphere(t_parse *pars, char **split_line);
void	parse_cylinder(t_parse *pars, char **split_line);

// ************************************************************************** //
//                               UTILITY_FUNCS                                //
// ************************************************************************** //
void	parse_assign_trgb(t_parse *pars, char *trgb_str, t_trgb *colour);
void	parse_assign_coord(t_parse *pars, char *str, t_matrix *origin);
void	parse_assign_vec(t_parse *pars, char *str, t_matrix *orient);
void	parse_validate_obj(t_parse *pars, char **split_line, t_type type);
int		parse_check_length(char **line);

// ************************************************************************** //
//                           PARSE_VALIDATE_UTILS                             //
// ************************************************************************** //
bool	validate_ambient(char **split_line);
bool	validate_camera(char **split_line);
bool	validate_light(char **split_line);
bool	validate_sphere(char **split_line);
bool	validate_cylinder(char **split_line);

// ************************************************************************** //
//                       PARSE_VALIDATE_ASSIGN_RGB_UTILS                      //
// ************************************************************************** //
bool	validate_rgb_string(char *rgb_str);
bool	split_and_validate_components(char *rgb_str, char ***dptr);
void	parse_transparency(char **dptr, t_trgb *colour);
bool	validate_rgb_ranges(char **dptr, int start_index);
void	assign_rgb_values(char **dptr, t_trgb *colour, int start_index);

// ************************************************************************** //
//                         PARSE_ASSIGN_COORD_UTILS                           //
// ************************************************************************** //
bool	validate_input_string(const char *str);
char	**split_coordinates(const char *str);
bool	validate_coordinate_values(char **coordinates, int expected_length);
void	assign_coordinates(char **coordinates, t_matrix *origin);

// ************************************************************************** //
//                         PARSE_ASSIGN_COORD_UTILS                           //
// ************************************************************************** //
bool	is_valid_format(char *str);
bool	parse_vector_components(char **dptr, t_matrix *orient);
char	**split_vector_string(char *str);

#endif
