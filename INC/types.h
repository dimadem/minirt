/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:02:25 by mcoskune          #+#    #+#             */
/*   Updated: 2025/04/09 14:52:11 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef enum e_type
{
	AMBIENT = 0,
	CAMERA = 1,
	LIGHT = 2,
	SPHERE = 3,
	PLANE = 4,
	CYLINDER = 5,
	OTHER = 6,
	ERROR = 7,
	EMPTY = 8
}	t_type;

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

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_light
{
	t_type			type;
	t_tuple			origin;
	double			brightness_ratio;
	t_trgb			color;
}	t_light;

typedef struct s_mat
{
	t_trgb	colour;
	double	brightness_ratio;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}	t_mat;

typedef struct s_isect
{
	double		t_val;
	int			t_count;
	t_type		obj_type;
	int			obj_id;
	int			count;
}	t_isect;

typedef struct s_object
{
	t_type	type;
	t_mat	material;
	union	u_data
	{
		struct s_sphere
		{
			t_tuple		origin;
			t_matrix	transform;
			double		radius;
			t_trgb		color;
		}	sphere;
		struct s_plane
		{
			t_tuple		*origin;
			t_tuple		*v_orient;
			t_trgb		color;
		}	plane;
		struct s_cylinder
		{
			t_tuple		*origin;
			t_tuple		*v_orient;
			double		diameter;
			double		height;
			t_trgb		color;
		}	cylinder;
	}	obj;
}	t_object;

typedef struct s_camera
{
	t_type			type;
	t_tuple			origin;
	t_tuple			v_orient;
	double			fov_deg;
	double			fov_ver;
	double			half_fov;
	double			half_height;
	double			half_width;
	double			aspect_ratio;
	// t_uv			viewport;
}	t_camera;

typedef struct s_comps
{
	t_type		type;
	int			obj_id;
	t_object	*object;
	double		t_val;
	t_tuple		*p_intersect;
	t_tuple		v_eye;
	t_tuple		v_normal;
}	t_comps;

typedef struct s_rayt
{
	void		*mlx_ptr;
	void		*win_ptr;
	// t_image		image;
	t_light		*p_light;
	// t_ambient	*a_light;
	t_camera	*camera;
	t_object	**objects;
	int			file_fd;
}	t_rayt;


#endif