#include "cub3d.h"

void	check_aguments(t_data *data)
{
	create_map_data(data);
	get_arguments(data);

}

void	get_arguments(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (ft_isalpha(data->map[i][1]))
			set_map_data(data, ft_substr(data->map[i], 0, 2), data->map[i]);
		else
		 set_map_data(data, ft_substr(data->map[i], 0, 1), data->map[i]);
		i++;
	}
	printf("map.north_wall: %s\n", data->map_data->north_wall);
	printf("map.south_wall: %s\n", data->map_data->south_wall);
	printf("map.east_wall: %s\n", data->map_data->east_wall);
	printf("map.west_wall: %s\n", data->map_data->west_wall);
	printf("map.ceiling_color: %s\n", data->map_data->ceiling_color);
	printf("map.floor_color: %s\n", data->map_data->floor_color);
}

void	set_map_data(t_data *data, char *arg, char *str)
{
	if (!ft_strncmp(arg, "NO", ft_strlen(arg)) && !data->map_data->north_wall)
		data->map_data->north_wall = str;
	else if (!ft_strncmp(arg, "SO", ft_strlen(arg)) && !data->map_data->south_wall)
		data->map_data->south_wall = str;
	else if (!ft_strncmp(arg, "EA", ft_strlen(arg)) && !data->map_data->east_wall)
		data->map_data->east_wall = str;
	else if (!ft_strncmp(arg, "WE", ft_strlen(arg)) && !data->map_data->west_wall)
		data->map_data->west_wall = str;
	else if (!ft_strncmp(arg, "C", ft_strlen(arg)) && !data->map_data->ceiling_color)
		data->map_data->ceiling_color = str;
	else if (!ft_strncmp(arg, "F", ft_strlen(arg)) && !data->map_data->floor_color)
		data->map_data->floor_color = str;
	else
	{
		printf("error\n");
		exit(EXIT_FAILURE);
	}
}

void	create_map_data(t_data *data)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		exit(EXIT_FAILURE); //need a real return with exit
	map->north_wall = NULL;
	map->south_wall = NULL;
	map->east_wall = NULL;
	map->west_wall = NULL;
	map->ceiling_color = NULL;
	map->floor_color = NULL;
	data->map_data = map;
}
