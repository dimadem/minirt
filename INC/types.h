/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:07:14 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/24 15:29:40 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>

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

/**
 * @brief n x m size matrix where values are stored in double **data
 * @param n [int] Number of Rows
 * @param m [int] Number of Columns
 * @param data [double] Stored numbers for matrix calculations.
 * `matrix->data[2][1]` will return the value in row_id 2 and column_id 1
 */
typedef struct s_matrix
{
	int		n;
	int		m;
	double	**data;
}	t_matrix;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_trgb
{
	double	t;
	double	r;
	double	g;
	double	b;
}	t_trgb;

/**
 * @brief ordered list of coordinaes [x, y, z]
 * @param x [double]
 * @param y [double]
 * @param z [double]
 * @param w [int] 1 for point, 0 for vector
 */
typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	int		w;
}	t_tuple;

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

/**
 * @brief Material [Identifier M]
 * @param colour			[0 - 255] [0 - 255] [0 - 255] [0 - 255]
 * @param brightness_ratio	[0.0 - 1.0]
 * @param ambient			[0.0 - 1.0]
 * @param diffuse			[0.0 - 1.0]
 * @param specular			[0.0 - 1.0]
 * @param shininess			[0.0 - 1.0]
 */
typedef struct s_mat
{
	t_trgb	colour;
	double	brightness_ratio;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}	t_mat;

/**
 * @brief Ambient Light [Identifier A]
 * @param lighting_ratio	[0.0 - 1.0] 
 * @param color				[0 - 255] [0 - 255] [0 - 255] [0 - 255]
 */
typedef struct s_ambient
{
	t_type	type;
	double	lighting_ratio;
	t_trgb	color;
}	t_ambient;

/**
 * @brief Camera [Identifier C]
 * @param type 			[Identifier C]
 * @param origin		[x, y, z]
 * @param v_orient		[-1.0 - 1.0]
 * @param fov_deg		[0 - 180]
 * @param fov_ver		[0 - 180]
 * @param aspect_ratio	[double]
 * @param viewport		[u, v]
 */
typedef struct s_camera
{
	t_type			type;
	t_matrix		*origin;
	t_matrix		*v_orient;
	double			fov_deg;
	double			fov_ver;
	double			half_fov;
	double			half_height;
	double			half_width;
	double			aspect_ratio;
	t_uv			viewport;
}	t_camera;

/**
 * @brief Spot Light [Identifier L]
 * @param type 				[Identifier L]
 * @param coordinate		[x, y, z]
 * @param brightness_rattio [0.0 - 1.0]
 * @param color 			[0 - 255] [0 - 255] [0 - 255] [0 - 255]
 */
typedef struct s_light
{
	t_type			type;
	t_matrix		*origin;
	double			brightness_ratio;
	t_trgb			color;
}	t_light;

/**
 * @brief Object [Identifier O]
 * @param type		[Identifier sp, pl, cy]
 * @param obj		[Union of Sphere, Plane, Cylinder]
 */
typedef struct s_object
{
	t_type	type;
	union	u_data
	{
		/**
		 * @brief Sphere Object [Identifier sp]
		 * @param origin	[x, y, z, 1]	4x1 tuple
		 * @param transform	[x, y, z, 1]	4x4 matrix
		 * @param radius	[double]
		 * @param color		[0 - 255] [0 - 255] [0 - 255] [0 - 255]
		 */
		struct s_sphere
		{
			t_matrix	*origin;
			t_matrix	*transform;
			double		radius;
			t_trgb		color;
		}	sphere;
		/**
		 * @brief Plane Object [Identifier pl]
		 * @param origin	[x, y, z, 1]	4x1 tuple
		 * @param v_orient	[-1.0 - 1.0]	4x1 tuple
		 * @param color 	[0 - 255] [0 - 255] [0 - 255] [0 - 255]
		 */
		struct s_plane
		{
			t_matrix	*origin;
			t_matrix	*v_orient;
			t_trgb		color;
		}	plane;
		/**
		 * @brief Cylinder Object [Identifier cy]
		 * @param origin 	[x, y, z, 1] 				4x1 tuple
		 * @param v_orient	[x, y, z, 1] [-1.0 - 1.0] 	4x1 tuple
		 * @param diameter 	[double]
		 * @param height	[double]
		 * @param color 	[0 - 255] [0 - 255] [0 - 255] [0 - 255]
		 */
		struct s_cylinder
		{
			t_matrix	*origin;
			t_matrix	*v_orient;
			double		diameter;
			double		height;
			t_trgb		color;
		}	cylinder;
	}	obj;
}	t_object;

/**
 * @brief Ray [Identifier R]
 * @param origin	[x, y, z, 1]	4x1 tuple
 * @param direction	[x, y, z, 0]	4x1 tuple
 */
typedef struct s_ray
{
	t_matrix	*origin;
	t_matrix	*direction;
}	t_ray;

typedef struct s_comps
{
	t_type		type;
	int			obj_id;
	t_object	*object;
	double		t_val;
	t_matrix	*p_intersect;
	t_matrix	*v_eye;
	t_matrix	*v_normal;
}	t_comps;

typedef struct s_isect
{
	double		t_val;
	int			t_count;
	t_type		obj_type;
	int			obj_id;
	int			count;
}	t_isect;

/**
 * @brief Raytracer main structure
 * @param mlx_ptr		[void *]		mlx pointer
 * @param win_ptr		[void *]		window pointer
 * @param image			[t_image]		image structure
 * @param p_light		[t_light]		pointer to light structure
 * @param a_light		[t_ambient]		ambient light structure
 * @param camera		[t_camera]		camera structure
 * @param objects		[t_object]		objects array
 * @param file_fd		[int]			file descriptor
 */
typedef struct s_rayt
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		image;
	t_light		*p_light;
	t_ambient	*a_light;
	t_camera	*camera;
	t_object	**objects;
	int			file_fd;
}	t_rayt;

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
