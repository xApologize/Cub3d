/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:36:37 by jrossign          #+#    #+#             */
/*   Updated: 2023/02/08 09:37:25 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	texture_picker(t_data *data, int i)
{
	if (data->ray->side == 0)
	{
		find_hit(data, data->tex->east_tex);
		draw_line(data, data->tex->east_tex, data->tex->east, i);
	}
	else if (data->ray->side == 1)
	{
		find_hit(data, data->tex->west_tex);
		draw_line(data, data->tex->west_tex, data->tex->west, i);
	}
	else if (data->ray->side == 2)
	{
		find_hit(data, data->tex->south_tex);
		draw_line(data, data->tex->south_tex, data->tex->south, i);
	}
	else
	{
		find_hit(data, data->tex->north_tex);
		draw_line(data, data->tex->north_tex, data->tex->north, i);
	}
}

void	raycaster(t_data *data)
{
	int		i;

	i = -1;
	clear_image(data);
	while (++i < WIDTH)
	{
		init_var(data, i);
		init_dist(data);
		dda(data);
		calc_line(data);
		texture_picker(data, i);
	}
	draw_map(data);
}

void	cursor_hook(double x, double y, void *temp)
{
	t_data	*data;

	data = temp;
	data->cursor->instances->x = x;
	data->cursor->instances->y = y;
	if (x > 1919 || x < 1 || y > 1079 || y < 1)
		mlx_set_mouse_pos(data->ray->mlx, 960, 540);
}

void	init_mlx(t_data *data)
{
	data->ray = ft_calloc(1, sizeof(t_ray));
	start_var(data);
	create_texture(data);
	data->tex->overlay = mlx_load_xpm42("./asset/weapon.xpm42");
	data->tex->overlay_img = mlx_texture_to_image(data->ray->mlx,
			&data->tex->overlay->texture);
	raycaster(data);
	mlx_image_to_window(data->ray->mlx, data->ray->img, 0, 0);
	mlx_image_to_window(data->ray->mlx, data->tex->overlay_img, 730, 674);
	mlx_image_to_window(data->ray->mlx, data->minimap, 0, 0);
	cursor(data);
	mlx_key_hook(data->ray->mlx, &hook, (void *) data);
	mlx_cursor_hook(data->ray->mlx, &cursor_hook, (void *) data);
	mlx_loop(data->ray->mlx);
	mlx_delete_image(data->ray->mlx, data->ray->img);
	mlx_delete_image(data->ray->mlx, data->tex->overlay_img);
	mlx_delete_image(data->ray->mlx, data->minimap);
	mlx_delete_image(data->ray->mlx, data->cursor);
	mlx_terminate(data->ray->mlx);
}
