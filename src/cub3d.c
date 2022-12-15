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
		error_and_free(&data, ERR_MAIN_ARG, 0);
	set_map(argv[1], &data);
	check_arguments(&data);
	check_map(&data);
	print_data(&data);
	free_full_data(&data);
	return (EXIT_SUCCESS);
}
