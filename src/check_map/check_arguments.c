#include "cub3d.h"
#include <stdio.h>

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
	printf("data.map_data.north_wall: %i\n", data->map_data->north_wall);
	printf("data.map_data.south_wall: %i\n", data->map_data->south_wall);
	printf("data.map_data.east_wall: %i\n", data->map_data->east_wall);
	printf("data.map_data.west_wall: %i\n", data->map_data->west_wall);
	printf("data.map_data.ceiling_color[0]: %d\n", data->map_data->ceiling_color[0]);
	printf("data.map_data.ceiling_color[1]: %d\n", data->map_data->ceiling_color[1]);
	printf("data.map_data.ceiling_color[2]: %d\n", data->map_data->ceiling_color[2]);
	printf("data.map_data.floor_color[0]: %d\n", data->map_data->floor_color[0]);
	printf("data.map_data.floor_color[1]: %d\n", data->map_data->floor_color[1]);
	printf("data.map_data.floor_color[2]: %d\n", data->map_data->floor_color[2]);
	printf("data.map:\n");
	while (data->map[i])
	{
		printf("%s\n", data->map[i]);
		i++;
	}
}

void	set_map_data(t_data *data, char *arg, char *str)
{
	if (!ft_strncmp(arg, "NO", ft_strlen(arg))
		&& !data->map_data->north_wall)
		data->map_data->north_wall = open_assets_file(ft_split(str, ' '));
	else if (!ft_strncmp(arg, "SO", ft_strlen(arg))
		&& !data->map_data->south_wall)
		data->map_data->south_wall = open_assets_file(ft_split(str, ' '));
	else if (!ft_strncmp(arg, "EA", ft_strlen(arg))
		&& !data->map_data->east_wall)
		data->map_data->east_wall = open_assets_file(ft_split(str, ' '));
	else if (!ft_strncmp(arg, "WE", ft_strlen(arg))
		&& !data->map_data->west_wall)
		data->map_data->west_wall = open_assets_file(ft_split(str, ' '));
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
		exit(EXIT_FAILURE); //need a real return with exit
	map->north_wall = 0;
	map->south_wall = 0;
	map->east_wall = 0;
	map->west_wall = 0;
	map->ceiling_color = NULL;
	map->floor_color = NULL;
	data->map_data = map;
}

int	open_assets_file(char **path)
{
	int		fd;

	check_extension(path[1], EXTENSION_TEXTURE);
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
