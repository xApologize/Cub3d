#include "cub3d.h"

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
		if (i == WIDTH / 2)
			data->ray->rayLenght = data->ray->wallDist;
	}
	if (data->ray->rays == true)
		map(data);
	else 
		draw_map(data);
}

void	init_mlx(t_data *data)
{
	data->ray = ft_calloc(1, sizeof(t_ray));
	start_var(data);
	data->tex->overlay = mlx_load_xpm42("./asset/weapon.xpm42");
	data->tex->overlay_img = mlx_texture_to_image(data->ray->mlx,
			&data->tex->overlay->texture);
	create_texture(data);
	raycaster(data); 
	mlx_image_to_window(data->ray->mlx, data->ray->img, 0, 0);
	mlx_image_to_window(data->ray->mlx, data->tex->overlay_img, 730, 674);
	mlx_key_hook(data->ray->mlx, &hook, (void *) data);
	mlx_loop(data->ray->mlx);
	mlx_terminate(data->ray->mlx);
}
