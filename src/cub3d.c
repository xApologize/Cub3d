#include "cub3d.h"

void	print_data(t_data *data)
{
	int	i;

	i = 0;
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

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		printf("Error\n");
		return (EXIT_FAILURE);
	}
	set_map(argv[1], &data);
	check_arguments(&data);
	check_map(&data);
	print_data(&data);
	free(data.map_data->ceiling_color);
	free(data.map_data->floor_color);
	ft_freepp((void **)data.map);
	close(data.map_data->north_wall);
	close(data.map_data->south_wall);
	close(data.map_data->east_wall);
	close(data.map_data->west_wall);
	free(data.map_data);
}
