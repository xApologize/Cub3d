#include "cub3d.h"

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
	//need to change how this thing work, to have less repetition
	if (!ft_strncmp(arg, "NO", ft_strlen(arg))
		&& !data->map_data->north_wall)
		data->map_data->north_wall = open_assets_file(ft_split(str, ' '), data, arg);
	else if (!ft_strncmp(arg, "SO", ft_strlen(arg))
		&& !data->map_data->south_wall)
		data->map_data->south_wall = open_assets_file(ft_split(str, ' '), data, arg);
	else if (!ft_strncmp(arg, "EA", ft_strlen(arg))
		&& !data->map_data->east_wall)
		data->map_data->east_wall = open_assets_file(ft_split(str, ' '), data, arg);
	else if (!ft_strncmp(arg, "WE", ft_strlen(arg))
		&& !data->map_data->west_wall)
		data->map_data->west_wall = open_assets_file(ft_split(str, ' '), data, arg);
	else if (!ft_strncmp(arg, "C", ft_strlen(arg))
		&& !data->map_data->ceiling_color)
		data->map_data->ceiling_color = set_colors(ft_split(str, ' '));
	else if (!ft_strncmp(arg, "F", ft_strlen(arg))
		&& !data->map_data->floor_color)
		data->map_data->floor_color = set_colors(ft_split(str, ' '));
	else
	{
		printf("error set_map_data\n");
		free(arg);
		exit(EXIT_FAILURE);
	}
	free(arg);
}

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

int	open_assets_file(char **path, t_data *data, char *arg)
{
	int		fd;

	if (!path[1])
	{
		printf("Error open_assets_file: %s\n", path[0]);
		exit(EXIT_FAILURE);
	}
	if (check_extension(path[1], EXTENSION_TEXTURE) == -1)
	{
		ft_freepp((void **) path);
		free(arg);
		error_and_free(data, ERR_ASSET_EXT, 1);
	}
	fd = open(path[1], O_RDONLY);
	if (fd < 0)
	{
		printf("error open_assets_file: %s\n", path[1]);
		ft_freepp((void**)path);
		exit(EXIT_FAILURE);
	}
	ft_freepp((void**)path);
	return (fd);
}
