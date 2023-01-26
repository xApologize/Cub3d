/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 07:56:22 by jrossign          #+#    #+#             */
/*   Updated: 2023/01/26 08:43:17 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_player(t_data *data)
{
	int		hold;
	int		hold2;
	double	x;
	double	y;

	y = (double)(data->ray->pos_y) * 10 - 4.5;
	x = (double)(data->ray->pos_x) * 10 - 4.5;
	hold = y + 9;
	while (y < hold)
	{
		hold2 = x + 9;
		while (x < hold2)
			mlx_put_pixel(data->ray->img, x++, y, 0x8a15bdFF);
		y++;
		x -= 9;
	}
	draw_player_two(data);
}

void	draw_wall(t_data *data, int x, int y)
{
	int	hold;
	int	hold2;

	hold = y + 9;
	while (y < hold)
	{
		hold2 = x + 9;
		while (x < hold2)
			mlx_put_pixel(data->ray->img, x++, y, 0xFFFFFFFF);
		y++;
		x -= 9;
	}
}

void	draw_space(t_data *data, int x, int y)
{
	int	hold;
	int	hold2;

	hold = y + 9;
	while (y < hold)
	{
		hold2 = x + 9;
		while (x < hold2)
			mlx_put_pixel(data->ray->img, x++, y, 0x000000FF);
		y++;
		x -= 9;
	}
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	y = 0;
	draw_map_two(data);
	while (++i < data->map_height)
	{
		j = -1;
		x = 0;
		while (++j < data->map_width)
		{
			if (data->map[i][j] != '0')
				draw_wall(data, x, y);
			else
				draw_space(data, x, y);
			x += 10;
		}
		y += 10;
	}
	draw_player(data);
}

//line 125 to 127 + 4.5
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
		while (hold-- >= 0 && y > 0 && x > 0
			&& x < data->map_width * 10 && y < data->map_height * 10)
		{
			mlx_put_pixel(data->ray->img, x, y, 0xFF0000FF);
			y += (double) data->ray->ray_y;
			x += (double) data->ray->ray_x;
		}
		i += 0.5;
	}
}
