
#include "cub3d.h"

void	turn_right(t_data *data)
{
	double oldDirX = data->ray->dirX;
	data->ray->dirX = data->ray->dirX * cos(RSPEED) - data->ray->dirY * sin(RSPEED);
	data->ray->dirY = oldDirX * sin(RSPEED) + data->ray->dirY * cos(RSPEED);
	double oldPlaneX = data->ray->planeX;
	data->ray->planeX = data->ray->planeX * cos(RSPEED) - data->ray->planeY * sin(RSPEED);
	data->ray->planeY = oldPlaneX * sin(RSPEED) + data->ray->planeY * cos(RSPEED);
}

void	turn_left(t_data *data)
{
	double oldDirX = data->ray->dirX;
	data->ray->dirX = data->ray->dirX * cos(-RSPEED) - data->ray->dirY * sin(-RSPEED);
	data->ray->dirY = oldDirX * sin(-RSPEED) + data->ray->dirY * cos(-RSPEED);
	double oldPlaneX = data->ray->planeX;
	data->ray->planeX = data->ray->planeX * cos(-RSPEED) - data->ray->planeY * sin(-RSPEED);
	data->ray->planeY = oldPlaneX * sin(-RSPEED) + data->ray->planeY * cos(-RSPEED);
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
		if (data->ray->mSpeed < 0.95)
			data->ray->mSpeed += 0.05;
	if (keydata.key == MLX_KEY_DOWN)
		if (data->ray->mSpeed > 0.15)
			data->ray->mSpeed -= 0.05;
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_RELEASE)
	{
		if (data->ray->rays == true)
			data->ray->rays = false;
		else
			data->ray->rays = true;
	}
	raycaster(data);
}