/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:07:14 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/04/09 14:50:13 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>




typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_orient
{
	double	x;
	double	y;
	double	z;
}	t_orient;

/**
 * @brief UV Coordinates [Identifier uv]
 * @param u [double]
 * @param v [double]
 */
typedef struct s_uv
{
	double	u;
	double	v;
}	t_uv;


typedef struct s_ambient
{
	t_type	type;
	double	lighting_ratio;
	t_trgb	color;
}	t_ambient;








// ************************************************************************** //
//                             TYPEDEF FOR PARSE                              //
// ************************************************************************** //

typedef struct s_parse
{
	int		count_a;
	int		count_c;
	int		count_l;
	int		count_sp;
	int		count_pl;
	int		count_cy;
	bool	error_encountered;
	t_rayt	*lux;
}	t_parse;

#endif
