#include "cub3d.h"

void	check_aguments(t_data *data)
{
	create_map_data(data);
	get_arguments(data);
}

void	get_arguments(t_data *data)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < 6)
	{
		if (ft_isalpha(data->map[i][1]))
			set_map_data(data, ft_substr(data->map[i], 0, 2), data->map[i]);
		else
			set_map_data(data, ft_substr(data->map[i], 0, 1), data->map[i]);
		i++;
	}
	tmp = ft_strtrim_str(data->map_data->ceiling_color[0], "C ");
	free(data->map_data->ceiling_color[0]);
	data->map_data->ceiling_color[0] = tmp;
	tmp = ft_strtrim_str(data->map_data->floor_color[0], "F ");
	free(data->map_data->floor_color[0]);
	data->map_data->floor_color[0] = tmp;
}

void	set_map_data(t_data *data, char *arg, char *str)
{
	if (!ft_strncmp(arg, "NO", ft_strlen(arg))
		&& !data->map_data->north_wall)
		data->map_data->north_wall = open_assets_file(str);
	else if (!ft_strncmp(arg, "SO", ft_strlen(arg))
		&& !data->map_data->south_wall)
		data->map_data->south_wall = open_assets_file(str);
	else if (!ft_strncmp(arg, "EA", ft_strlen(arg))
		&& !data->map_data->east_wall)
		data->map_data->east_wall = open_assets_file(str);
	else if (!ft_strncmp(arg, "WE", ft_strlen(arg))
		&& !data->map_data->west_wall)
		data->map_data->west_wall = open_assets_file(str);
	else if (!ft_strncmp(arg, "C", ft_strlen(arg))
		&& !data->map_data->ceiling_color)
		data->map_data->ceiling_color = ft_split(str, ',');
	else if (!ft_strncmp(arg, "F", ft_strlen(arg))
		&& !data->map_data->floor_color)
		data->map_data->floor_color = ft_split(str, ',');
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

int	open_assets_file(char *path)
{
	int		fd;
	int		i;
	char	*new_string;

	i = 2;
	while (path[i] == ' ')
		i++;
	new_string = ft_substr(path, i, ft_strlen(path));
	fd = open(new_string, O_RDONLY);
	if (fd < 0)
	{
		printf("error open_assets_file: %s\n", new_string);
		free(new_string);
		exit(EXIT_FAILURE);
	}
	free(new_string);
	return (fd);
}
