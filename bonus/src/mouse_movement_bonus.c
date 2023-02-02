/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_movement_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:11:56 by jrossign          #+#    #+#             */
/*   Updated: 2023/02/02 11:12:13 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	mouse_move(double xpos, double ypos, void *tmp)
{
	t_data	*data;
	double	old_dir_x;
	double	old_plane_x;
	double	delta_x;

	(void) ypos;
	data = (void *)tmp;
	old_plane_x = data->ray->plane_x;
	old_dir_x = data->ray->dir_x;
	delta_x = xpos - data->old_x;
	delta_x *= 0.005;
	data->ray->dir_x = data->ray->dir_x * cos(delta_x)
		- data->ray->dir_y * sin(delta_x);
	data->ray->dir_y = old_dir_x * sin(delta_x)
		+ data->ray->dir_y * cos(delta_x);
	data->ray->plane_x = data->ray->plane_x
		* cos(delta_x) - data->ray->plane_y * sin(delta_x);
	data->ray->plane_y = old_plane_x * sin(delta_x)
		+ data->ray->plane_y * cos(delta_x);
	data->old_x = xpos;
}
