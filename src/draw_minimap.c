/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:25:16 by jrossign          #+#    #+#             */
/*   Updated: 2023/02/07 08:03:58 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_player(t_data *data)
{
	double	x;
	double	y;

	x = 99;
	while (++x < 109)
	{
		y = 99;
		while (++y < 109)
		{
			mlx_put_pixel(data->minimap, x, y, 0xe303fcFF);
		}
	}
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
			mlx_put_pixel(data->minimap, x++, y, 0xFFFFFFFF);
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
			mlx_put_pixel(data->minimap, x++, y, 0x000000FF);
		y++;
		x -= 9;
	}
}

void	decide_draw(t_data *data, double *i, double *y)
{
	double	j;
	double	x;

	j = data->ray->pos_x - 9;
	x = 0;
	while (++x < 210)
	{
		if (*i >= 0 && j >= 0 && *i < data->map_height && j < data->map_width)
		{
			if (data->map[(int) *i][(int) j] != '0')
				draw_wall(data, x, *y);
			else
				draw_space(data, x, *y);
		}
		j++;
		x += 10;
	}
	*i += 1;
	*y += 10;
}

void	draw_map(t_data *data)
{
	double	i;
	double	j;
	double	y;

	i = -1;
	while (++i < 210)
	{
		j = -1;
		while (++j < 210)
			mlx_put_pixel(data->minimap, i, j, 0x4d4d4dFF);
	}
	i = data->ray->pos_y - 9;
	y = 0;
	while (++y < 210)
		decide_draw(data, &i, &y);
	draw_player(data);
}
