/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:39:38 by jrossign          #+#    #+#             */
/*   Updated: 2023/01/26 07:28:05 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda(t_data *data)
{
	while (1)
	{
		dda_calc(data);
		if (data->map[data->ray->map_y][data->ray->map_x] != '0')
			break ;
	}
	if (data->ray->side < 2)
		data->ray->wall_dist = data->ray->dist_x - data->ray->delta_x;
	else
		data->ray->wall_dist = data->ray->dist_y - data->ray->delta_y;
}

void	dda_calc(t_data *data)
{
	if (data->ray->dist_x < data->ray->dist_y)
	{
		data->ray->dist_x += data->ray->delta_x;
		data->ray->map_x += data->ray->step_x;
		if (data->ray->ray_x > 0)
			data->ray->side = 0;
		else
			data->ray->side = 1;
	}
	else
	{
		data->ray->dist_y += data->ray->delta_y;
		data->ray->map_y += data->ray->step_y;
		if (data->ray->ray_y > 0)
			data->ray->side = 2;
		else
			data->ray->side = 3;
	}
}

void	calc_line(t_data *data)
{
	data->ray->line = HEIGHT / data->ray->wall_dist;
	data->ray->start = -data->ray->line / 2 + HEIGHT / 2;
	if (data->ray->start < 0)
		data->ray->start = 0;
	data->ray->end = data->ray->line / 2 + HEIGHT / 2;
	if (data->ray->end >= HEIGHT)
		data->ray->end = HEIGHT - 1;
}

void	find_hit(t_data *data, xpm_t *texture)
{
	double	hit;

	hit = 0;
	if (data->ray->side == 0 || data->ray->side == 1)
		hit = data->ray->pos_y + data->ray->wall_dist * data->ray->ray_y;
	else
		hit = data->ray->pos_x + data->ray->wall_dist * data->ray->ray_x;
	hit -= (int) hit;
	data->ray->tex_x = (int)(hit * (double) texture->texture.width);
	if ((data->ray->side == 0 || data->ray->side == 1) && data->ray->ray_x > 0)
		data->ray->tex_x = texture->texture.width - data->ray->tex_x - 1;
	if ((data->ray->side == 2 || data->ray->side == 3) && data->ray->ray_y < 0)
		data->ray->tex_x = texture->texture.width - data->ray->tex_x - 1;
}

void	draw_line(t_data *data, xpm_t *texture, int **arr, int i)
{
	double	dist;
	double	pos;
	int		tex_y;
	int		j;

	dist = 1.0 * texture->texture.height / data->ray->line;
	pos = ((double) data->ray->start - (double) HEIGHT / 2
			+ (double) data->ray->line / 2) * dist;
	if (pos < 0)
		pos = 0;
	j = data->ray->start - 1;
	while (++j < data->ray->end)
	{
		tex_y = (int) pos;
		if (pos > texture->texture.height - 1)
			pos = texture->texture.height - 1;
		pos += dist;
		mlx_put_pixel(data->ray->img, i, j, arr[tex_y][data->ray->tex_x]);
	}
}
