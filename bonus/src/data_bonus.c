/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 07:44:08 by jrossign          #+#    #+#             */
/*   Updated: 2023/02/07 11:36:59 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_var(t_data *data, double i)
{
	data->ray->camera = 2 * i / (double) WIDTH - 1;
	data->ray->ray_x = data->ray->dir_x + data->ray->plane_x
		* data->ray->camera;
	data->ray->ray_y = data->ray->dir_y + data->ray->plane_y
		* data->ray->camera;
	data->ray->map_x = data->ray->pos_x;
	data->ray->map_y = data->ray->pos_y;
	data->ray->delta_x = fabs(1 / data->ray->ray_x);
	data->ray->delta_y = fabs(1 / data->ray->ray_y);
}

void	init_dist(t_data *data)
{
	if (data->ray->ray_x < 0)
	{
		data->ray->step_x = -1;
		data->ray->dist_x = (data->ray->pos_x - data->ray->map_x)
			* data->ray->delta_x;
	}
	else
	{
		data->ray->step_x = 1;
		data->ray->dist_x = (data->ray->map_x - data->ray->pos_x + 1)
			* data->ray->delta_x;
	}
	if (data->ray->ray_y < 0)
	{
		data->ray->step_y = -1;
		data->ray->dist_y = (data->ray->pos_y - data->ray->map_y)
			* data->ray->delta_y;
	}
	else
	{
		data->ray->step_y = 1;
		data->ray->dist_y = (data->ray->map_y - data->ray->pos_y + 1)
			* data->ray->delta_y;
	}
}

void	orientation2(t_data *data)
{
	if (data->orientation == 'E')
	{
		data->ray->dir_x = 1;
		data->ray->dir_y = 0;
		data->ray->plane_x = 0;
		data->ray->plane_y = 0.66;
	}
	if (data->orientation == 'W')
	{
		data->ray->dir_x = -1;
		data->ray->dir_y = 0;
		data->ray->plane_x = 0;
		data->ray->plane_y = -0.66;
	}
}

void	orientation(t_data *data)
{
	if (data->orientation == 'N')
	{
		data->ray->dir_x = 0;
		data->ray->dir_y = -1;
		data->ray->plane_x = 0.66;
		data->ray->plane_y = 0;
	}
	if (data->orientation == 'S')
	{
		data->ray->dir_x = 0;
		data->ray->dir_y = 1;
		data->ray->plane_x = -0.66;
		data->ray->plane_y = 0;
	}
	else
		(orientation2(data));
}

void	start_var(t_data *data)
{
	data->ray->mlx = mlx_init(WIDTH, HEIGHT, "test", false);
	data->ray->img = mlx_new_image(data->ray->mlx, WIDTH, HEIGHT);
	data->minimap = mlx_new_image(data->ray->mlx, 210, 210);
	data->ray->pos_x = data->start_pos[1] + 0.5;
	data->ray->pos_y = data->start_pos[0] + 0.5;
	orientation(data);
	data->ray->m_speed = 0.15;
	data->ray->s_speed = 0.15;
	data->ray->rays = false;
	data->ray->ceiling = create_colour(data->map_data->ceiling_color[0],
			data->map_data->ceiling_color[1],
			data->map_data->ceiling_color[2], 255);
	data->ray->floor = create_colour(data->map_data->floor_color[0],
			data->map_data->floor_color[1],
			data->map_data->floor_color[2], 255);
}
