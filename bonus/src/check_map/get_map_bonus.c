/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:17:55 by jrossign          #+#    #+#             */
/*   Updated: 2023/01/19 08:28:17 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_map(char *map, t_data *data)
{
	data->map = NULL;
	if (check_extension(map, EXTENSION_MAP) == -1)
		error_and_free(data, ERR_MAP_EXT, 0);
	get_map(check_map_exist(map), data);
	if (ft_get_pp_length(data->map) == 0)
		error_and_free(data, ERR_MAP_EMPTY, 0);
}

void	get_map(int map_fd, t_data *data)
{
	char	*gnl_ret;
	char	*map;

	map = NULL;
	gnl_ret = NULL;
	gnl_ret = get_next_line(map_fd);
	map = ft_strjoinfree(map, gnl_ret);
	while (1)
	{
		gnl_ret = get_next_line(map_fd);
		if (gnl_ret == NULL)
			break ;
		map = ft_strjoinfree(map, gnl_ret);
	}
	data->map = ft_split(map, '\n');
	free(map);
	close(map_fd);
}

void	set_height_width(t_data *data)
{
	data->map_height = ft_get_pp_length(data->map);
	data->map_width = get_longest_row(data);
}
