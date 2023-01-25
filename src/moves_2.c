/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:35:20 by jrossign          #+#    #+#             */
/*   Updated: 2023/01/25 10:35:21 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// faut fix que quand tes tout droits tu clip un peu a travers le mur
void	forward(t_data *data)
{
	double	i;

	i = 0;
	while (data->ray->m_speed - i >= 0.15)
	{
		if (data->map[(int)(data->ray->pos_y)][(int)(data->ray->pos_x
				+ data->ray->dir_x * (data->ray->m_speed - i))] == '0')
		{
			data->ray->pos_x += data->ray->dir_x * data->ray->m_speed - i;
			break ;
		}
		i += 0.05;
	}
	i = 0;
	while (data->ray->m_speed - i >= 0.15)
	{
		if (data->map[(int)(data->ray->pos_y + data->ray->dir_y
				* (data->ray->m_speed - i))][(int)(data->ray->pos_x)] == '0')
		{
			data->ray->pos_y += data->ray->dir_y * data->ray->m_speed - i;
			break ;
		}
		i += 0.05;
	}
}

void	backward(t_data *data)
{
	double	i;

	i = 0;
	while (data->ray->m_speed - i >= 0.15)
	{
		if (data->map[(int)(data->ray->pos_y)][(int)(data->ray->pos_x
				- data->ray->dir_x * (data->ray->m_speed - i))] == '0')
		{
			data->ray->pos_x -= data->ray->dir_x * data->ray->m_speed - i;
			break ;
		}
		i += 0.05;
	}
	i = 0;
	while (data->ray->m_speed - i >= 0.15)
	{
		if (data->map[(int)(data->ray->pos_y - data->ray->dir_y
				* (data->ray->m_speed - i))][(int)(data->ray->pos_x)] == '0')
		{
			data->ray->pos_y -= data->ray->dir_y * data->ray->m_speed - i;
			break ;
		}
		i += 0.05;
	}
}

void	right(t_data *data)
{
	if (data->map[(int)(data->ray->pos_y)][(int)(data->ray->pos_x
			+ data->ray->plane_x * data->ray->s_speed)] == '0')
		data->ray->pos_x += data->ray->plane_x * data->ray->s_speed;
	if (data->map[(int)(data->ray->pos_y + data->ray->plane_y
			* data->ray->s_speed)][(int)(data->ray->pos_x)] == '0')
		data->ray->pos_y += data->ray->plane_y * data->ray->s_speed;
}

void	left(t_data *data)
{
	if (data->map[(int)(data->ray->pos_y)][(int)(data->ray->pos_x
			- data->ray->plane_x * data->ray->s_speed)] == '0')
		data->ray->pos_x -= data->ray->plane_x * data->ray->s_speed;
	if (data->map[(int)(data->ray->pos_y - data->ray->plane_y
			* data->ray->s_speed)][(int)(data->ray->pos_x)] == '0')
		data->ray->pos_y -= data->ray->plane_y * data->ray->s_speed;
}
