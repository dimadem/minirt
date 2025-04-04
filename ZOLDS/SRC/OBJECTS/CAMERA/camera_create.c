/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:30:22 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/24 15:31:24 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "window_size.h"
#include "objects_camera.h"
#include <math.h>
#include "muk_lib.h"

void	camera_init(t_camera *camera)
{
	camera->aspect_ratio = aspect_ratio(WINDOW_WIDTH, WINDOW_HEIGHT);
	camera->fov_ver = camera->fov_deg / camera->aspect_ratio;
	camera->viewport.u = 0;
	camera->viewport.v = 0;
	camera->half_fov = (camera->fov_deg * M_PI / 180.0) / 2.0;
	camera->half_height = tan(camera->half_fov);
	camera->half_width = camera->half_height * camera->aspect_ratio;
}
