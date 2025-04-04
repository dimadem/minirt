/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:02:25 by mcoskune          #+#    #+#             */
/*   Updated: 2025/04/04 14:38:47 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_matrix
{
	int		n;
	int		m;
	double	data[4][4];
}	t_matrix;

typedef struct s_tuple
{
	int		n;
	int		m;
	double	data[4][1];
}	t_tuple;

typedef struct s_trgb
{
	double	t;
	double	r;
	double	g;
	double	b;
}	t_trgb;

typedef struct s_rayt
{
	void		*mlx_ptr;
	void		*win_ptr;
	// t_image		image;
	// t_light		*p_light;
	// t_ambient	*a_light;
	// t_camera	*camera;
	// t_object	**objects;
	int			file_fd;
}	t_rayt;


#endif