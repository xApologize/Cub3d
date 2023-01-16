/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:20:12 by jrossign          #+#    #+#             */
/*   Updated: 2023/01/11 08:10:49 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//to remove before we push the project
void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

void	flood_fill(t_data *data)
{
	data->copy = copy_map(data);
	flood_fill_algo(data->start_pos[0], data->start_pos[1], data);
}

void	flood_fill_algo(int x, int y, t_data *data)
{
	int	i;

	i = 0;
	while (data->copy[i])
		i++;
	if (((x - 1 < 0 || y - 1 < 0 || x + 1 >= i
				|| (size_t)y + 1 >= ft_strlen(data->copy[x]))
			&& ft_strchr("0 ", data->copy[x][y])) || data->copy[x][y] == ' ')
		error_and_free(data, ERR_MAP_OPEN, 1);
	if (data->copy[x][y] == '0'
		|| ft_strchr(VALID_STARTING_POINT, data->copy[x][y]))
		data->copy[x][y] = '.';
	else
		return ;
	flood_fill_algo(x - 1, y, data);
	flood_fill_algo(x, y + 1, data);
	flood_fill_algo(x + 1, y, data);
	flood_fill_algo(x, y - 1, data);
	flood_fill_algo(x + 1, y + 1, data);
	flood_fill_algo(x - 1, y + 1, data);
	flood_fill_algo(x + 1, y - 1, data);
	flood_fill_algo(x - 1, y - 1, data);
}
