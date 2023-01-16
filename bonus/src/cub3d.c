#include "cub3d.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
	{
		printf("Error\n");
		return (EXIT_FAILURE);
	}
	data = ft_calloc(1, sizeof(t_data));
	check_map(argv[1], data);
	check_arguments(data);
	init_mlx(data);
	free(data->map_data->ceiling_color);
	free(data->map_data->floor_color);
	ft_freepp((void **)data->map);
	close(data->map_data->north_wall);
	close(data->map_data->south_wall);
	close(data->map_data->east_wall);
	close(data->map_data->west_wall);
	free(data->map_data);
}
