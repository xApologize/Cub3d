
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
		if (i == WIDTH / 2)
			data->ray->rayLenght = data->ray->wallDist;
	}
	draw_map(data);
}

void cursor_hook(double x, double y, void *temp)
{
	t_data *data;

	data = temp;
	data->cursor->instances->x = x;
	data->cursor->instances->y = y;
}

void	init_mlx(t_data *data)
{
	xpm_t *overlay;
	mlx_image_t *img;
	xpm_t	*cursor;
	int		x;
	int		y;

	data->ray = ft_calloc(1, sizeof(t_ray));
	start_var(data);
	overlay = mlx_load_xpm42("./asset/weapon.xpm42");
	img = mlx_texture_to_image(data->ray->mlx, &overlay->texture);
	cursor = mlx_load_xpm42("./asset/scimitar.xpm42");
	data->cursor = mlx_texture_to_image(data->ray->mlx, &cursor->texture);
	mlx_set_cursor_mode(data->ray->mlx, MLX_MOUSE_HIDDEN);
	create_texture(data);
	raycaster(data); 
	mlx_image_to_window(data->ray->mlx, data->ray->img, 0, 0);
	mlx_image_to_window(data->ray->mlx, data->minimap, 0, 0);
	mlx_image_to_window(data->ray->mlx, img, 730, 674);
	mlx_get_mouse_pos(data->ray->mlx, &x, &y);
	mlx_image_to_window(data->ray->mlx, data->cursor, x, y);
	mlx_key_hook(data->ray->mlx, &hook, (void *) data);
	mlx_cursor_hook(data->ray->mlx, &cursor_hook, (void *) data);
	mlx_loop(data->ray->mlx);
	mlx_delete_xpm42(data->tex->east_tex);
	mlx_delete_xpm42(data->tex->west_tex);
	mlx_delete_xpm42(data->tex->north_tex);
	mlx_delete_xpm42(data->tex->south_tex);
	mlx_delete_image(data->ray->mlx, data->ray->img);
	mlx_terminate(data->ray->mlx);
}
