/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_camera.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:28:15 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/24 15:28:38 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_CAMERA_H
# define OBJECTS_CAMERA_H

# include "types.h"

void		camera_init(t_camera *camera);
void		free_camera(t_camera *camera);
double		aspect_ratio(int width, int height);

#endif
