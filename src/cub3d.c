#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		printf("Error\n");
		return (EXIT_FAILURE);
	}
	check_map(argv[1], &data);
	check_aguments(&data);
	ft_freepp(data.map_data->floor_color);
	ft_freepp(data.map_data->ceiling_color);
	free(data.map_data);
	ft_freepp(data.map);
}
