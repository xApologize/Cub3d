/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:16:39 by jrossign          #+#    #+#             */
/*   Updated: 2023/01/19 08:24:49 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_arguments(t_data *data)
{
	create_map_data(data);
	get_arguments(data);
}

void	get_arguments(t_data *data)
{
	int		i;

	i = 0;
	while (i < 6)
	{
		if (ft_isalpha(data->map[i][1]))
			set_map_data(data, ft_substr(data->map[i], 0, 2), data->map[i]);
		else
			set_map_data(data, ft_substr(data->map[i], 0, 1), data->map[i]);
		i++;
	}
}

void	set_map_data(t_data *data, char *arg, char *str)
{
	int	fd;

	fd = 0;
	if (!ft_strcmp(arg, "NO") || !ft_strcmp(arg, "SO")
		|| !ft_strcmp(arg, "EA") || !ft_strcmp(arg, "WE"))
	{
		fd = open_assets_file(ft_split(str, ' '));
		if (fd > 0)
			set_texture(data, arg, ft_split(str, ' '));
		if (fd < 0)
		{
			free(arg);
			error_and_free(data, ERR_ASSET_EXT, 1);
		}
	}
	else if (!ft_strcmp(arg, "C") || !ft_strcmp(arg, "F"))
		set_color(data, arg, str);
	else
	{
		free(arg);
		error_and_free(data, ERR_ARG_NAME, 1);
	}
	close(fd);
	free(arg);
}

int	open_assets_file(char **path)
{
	int		fd;

	if (!path[1])
	{
		ft_freepp((void **) path);
		return (CODE_PATH_ERR);
	}
	if (check_extension(path[1], EXTENSION_TEXTURE) == -1)
	{
		ft_freepp((void **) path);
		return (CODE_EXT_ERR);
	}
	fd = open(path[1], O_RDONLY);
	ft_freepp((void **)path);
	return (fd);
}
