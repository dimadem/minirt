/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:27:53 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/24 15:27:55 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_UTILS_H
# define OBJECTS_UTILS_H

# include "types.h"

void	free_objects(t_object **objects);
void	free_object(t_object *obj);
void	obj_render(int **pixel, t_object **objects, t_camera *camera);

#endif
