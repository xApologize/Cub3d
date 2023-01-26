/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:16:16 by jrossign          #+#    #+#             */
/*   Updated: 2023/01/26 08:16:18 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	turn_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_plane_x = data->ray->plane_x;
	old_dir_x = data->ray->dir_x;
	data->ray->dir_x = data->ray->dir_x * cos(RSPEED)
		- data->ray->dir_y * sin(RSPEED);
	data->ray->dir_y = old_dir_x * sin(RSPEED)
		+ data->ray->dir_y * cos(RSPEED);
	data->ray->plane_x = data->ray->plane_x
		* cos(RSPEED) - data->ray->plane_y * sin(RSPEED);
	data->ray->plane_y = old_plane_x * sin(RSPEED)
		+ data->ray->plane_y * cos(RSPEED);
}

void	turn_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_plane_x = data->ray->plane_x;
	old_dir_x = data->ray->dir_x;
	data->ray->dir_x = data->ray->dir_x * cos(-RSPEED)
		- data->ray->dir_y * sin(-RSPEED);
	data->ray->dir_y = old_dir_x * sin(-RSPEED)
		+ data->ray->dir_y * cos(-RSPEED);
	data->ray->plane_x = data->ray->plane_x
		* cos(-RSPEED) - data->ray->plane_y * sin(-RSPEED);
	data->ray->plane_y = old_plane_x * sin(-RSPEED)
		+ data->ray->plane_y * cos(-RSPEED);
}

void	hook_two(mlx_key_data_t keydata, t_data *data)
{
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
}

void	hook(mlx_key_data_t keydata, void *temp)
{
	t_data	*data;

	data = temp;
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		data->anim->spell = 1;
	if (keydata.key == MLX_KEY_UP)
		if (data->ray->m_speed < 0.90)
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
	else
		hook_two(keydata, data);
	raycaster(data);
}

void	loop_hook(void *temp)
{
	t_data	*data;

	data = (t_data *)temp;
	if (data->anim->spell == true)
	{
		if (data->anim->frame == 0)
		{
			system("afplay ./sound/ice-barrage1.mp3&");
			data->tex->player->instances->enabled = false;
		}
		if (data->anim->frame == 11)
			data->tex->player->instances->enabled = true;
		animation_spell(data);
	}
}
