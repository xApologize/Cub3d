#include "cub3d.h"

void	turn_right(t_data *data)
{
	double old_dir_x = data->ray->dir_x;
	data->ray->dir_x = data->ray->dir_x * cos(RSPEED) - data->ray->dir_y * sin(RSPEED);
	data->ray->dir_y = old_dir_x * sin(RSPEED) + data->ray->dir_y * cos(RSPEED);
	double oldPlaneX = data->ray->plane_x;
	data->ray->plane_x = data->ray->plane_x * cos(RSPEED) - data->ray->plane_y * sin(RSPEED);
	data->ray->plane_y = oldPlaneX * sin(RSPEED) + data->ray->plane_y * cos(RSPEED);
}

void	turn_left(t_data *data)
{
	double old_dir_x = data->ray->dir_x;
	data->ray->dir_x = data->ray->dir_x * cos(-RSPEED) - data->ray->dir_y * sin(-RSPEED);
	data->ray->dir_y = old_dir_x * sin(-RSPEED) + data->ray->dir_y * cos(-RSPEED);
	double oldPlaneX = data->ray->plane_x;
	data->ray->plane_x = data->ray->plane_x * cos(-RSPEED) - data->ray->plane_y * sin(-RSPEED);
	data->ray->plane_y = oldPlaneX * sin(-RSPEED) + data->ray->plane_y * cos(-RSPEED);
}

void	hook(mlx_key_data_t keydata, void *temp)
{
	t_data *data;

	data = temp;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(data->ray->mlx);
		return ;
	}
	if (keydata.key == MLX_KEY_RIGHT)
		turn_right(data);
	if (keydata.key == MLX_KEY_LEFT)
		turn_left(data);
	if (keydata.key == MLX_KEY_W)
		forward(data);
	if (keydata.key == MLX_KEY_S)
		backward(data);
	if (keydata.key == MLX_KEY_A)
		left(data);
	if (keydata.key == MLX_KEY_D)
		right(data);
	if (keydata.key == MLX_KEY_UP)
		if (data->ray->m_speed < 0.95)
			data->ray->m_speed += 0.05;
	if (keydata.key == MLX_KEY_DOWN)
		if (data->ray->m_speed > 0.15)
			data->ray->m_speed -= 0.05;
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_RELEASE)
	{
		if (data->ray->rays == true)
			data->ray->rays = false;
		else
			data->ray->rays = true;
	}
	raycaster(data);
}
