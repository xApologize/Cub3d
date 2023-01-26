/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:25:16 by jrossign          #+#    #+#             */
/*   Updated: 2023/01/25 11:14:34 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_map(t_data *data)
{
	(void) data;
}

void	map(t_data *data)
{
	double	i;
	double	y;
	double	x;
	double	hold;

	i = -1;
	draw_map(data);
	while (i < WIDTH)
	{
		init_var(data, i);
		init_dist(data);
		dda(data);
		y = (double)(data->ray->pos_y) * 10;
		x = (double)(data->ray->pos_x) * 10;
		hold = data->ray->wall_dist * 10;
		while (hold-- >= 0 && y > 0 && x > 0 && x
			< data->map_width * 10 && y < data->map_height * 10)
		{
			mlx_put_pixel(data->ray->img, x, y, 0xFF0000FF);
			y += (double) data->ray->ray_y;
			x += (double) data->ray->ray_x;
		}
		i += 0.5;
	}
}
