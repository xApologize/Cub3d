/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:18:05 by jrossign          #+#    #+#             */
/*   Updated: 2022/12/21 14:18:06 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_map_data(t_data *data)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		error_and_free(data, ERR_MALLOC, 1);
	map->north_wall = 0;
	map->south_wall = 0;
	map->east_wall = 0;
	map->west_wall = 0;
	map->ceiling_color = NULL;
	map->floor_color = NULL;
	data->map_data = map;
}

void	set_texture(t_data *data, char *arg, int fd)
{
	if (fd < 0)
	{
		free(arg);
		error_code_arg(data, fd);
	}
	else if (!ft_strncmp(arg, "NO", ft_strlen(arg))
		&& !data->map_data->north_wall)
		data->map_data->north_wall = fd;
	else if (!ft_strncmp(arg, "SO", ft_strlen(arg))
		&& !data->map_data->south_wall)
		data->map_data->south_wall = fd;
	else if (!ft_strncmp(arg, "EA", ft_strlen(arg))
		&& !data->map_data->east_wall)
		data->map_data->east_wall = fd;
	else if (!ft_strncmp(arg, "WE", ft_strlen(arg))
		&& !data->map_data->west_wall)
		data->map_data->west_wall = fd;
}

void	set_color(t_data *data, char *arg, char *str)
{
	int	*colors;

	colors = get_colors(data, ft_split(str, ' '), arg);
	if (!colors)
	{
		free(arg);
		error_and_free(data, ERR_COL_LINE, 1);
	}
	if (!ft_strcmp(arg, "C"))
		data->map_data->ceiling_color = colors;
	if (!ft_strcmp(arg, "F"))
		data->map_data->floor_color = colors;
}
