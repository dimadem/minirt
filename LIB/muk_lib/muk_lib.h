/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   muk_lib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:09:19 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/08 16:42:46 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUK_LIB_H
# define MUK_LIB_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
// # include "raytracing/INC/types.h"

# define M_PI 3.14159265358979323846
# define EPSILON 0.0001

// typedef struct s_tuple
// {
// 	double	x;
// 	double	y;
// 	double	z;
// 	int		w;
// }	t_tuple;

// typedef struct s_matrix
// {
// 	int		n;
// 	int		m;
// 	double	**elements;
// }	t_matrix;

// ************************************************************************** //
//                               CONVERSION                                   //
// ************************************************************************** //
double	deg_to_rad(double degree);
double	ft_atod(char *str);
double	rad_to_deg(double radian);

// ************************************************************************** //
//                                  FILES                                     //
// ************************************************************************** //
int		check_extension(char *filename, char *extension);
int		check_access(char *filename, int flag);

// ************************************************************************** //
//                                  MATHS                                     //
// ************************************************************************** //
int		check_range(long double num, long double low, long double hig, char *s);

// ************************************************************************** //
//                               MEMORY_HEAP                                  //
// ************************************************************************** //
int		add_to_dptr(void ***dptr, void *to_add);
int		add_to_ptr(void **ptr, void *to_add);
void	*safe_malloc(unsigned int size_of_type, int num_of_obj);
void	ft_bzero(void *s, size_t n);
void	free_dptr(void **dptr);

// ************************************************************************** //
//                              DEBUG - PRINTF                                //
// ************************************************************************** //
void	errmsg(char *msg);
void	print_dptr_debug(void **dptr);

// ************************************************************************** //
//                              STRING - CHAR                                 //
// ************************************************************************** //
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
int		ft_strval(char *str, char *exempt, int flag);

#endif
