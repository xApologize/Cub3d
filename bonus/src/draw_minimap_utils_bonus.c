/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:43:31 by jrossign          #+#    #+#             */
/*   Updated: 2023/01/26 08:43:31 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_player_two(t_data *data)
{
	int		hold;
	double	x;
	double	y;

	y = (double)(data->ray->pos_y) * 10;
	x = (double)(data->ray->pos_x) * 10;
	hold = data->ray->ray_length * 10;
	while (hold-- >= 0 && y > 0 && x > 0
		&& x < data->map_width * 10 && y < data->map_height * 10)
	{
		mlx_put_pixel(data->ray->img, x, y, 0xFF0000FF);
		y += data->ray->dir_y;
		x += data->ray->dir_x;
	}
}

void	draw_map_two(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map_width * 10)
	{
		j = -1;
		while (++j < data->map_height * 10)
			mlx_put_pixel(data->ray->img, i, j, 0x4d4d4dFF);
	}
}
