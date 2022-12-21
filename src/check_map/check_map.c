/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:16:59 by jrossign          #+#    #+#             */
/*   Updated: 2022/12/21 14:17:00 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map(t_data *data)
{
	set_map_only(data);
	check_map_char(data);
	set_start_pos(data);
	flood_fill(data);
}

void	check_map_char(t_data *data)
{
	int	i;
	int	j;
	int	starting_point;

	i = 0;
	j = 0;
	starting_point = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (!ft_strchr(VALID_MAP_CHAR, data->map[i][j]))
				error_and_free(data, ERR_WRONG_CHAR_MAP, 1);
			if (ft_strchr(VALID_STARTING_POINT, data->map[i][j]))
				starting_point++;
			j++;
		}
		j = 0;
		i++;
	}
	if (starting_point != 1)
		error_and_free(data, ERR_START_POINT, 1);
}

void	set_start_pos(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (ft_strchr(VALID_STARTING_POINT, data->map[y][x]))
			{
				data->start_pos[0] = y;
				data->start_pos[1] = x;
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}
