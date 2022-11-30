#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (EXIT_FAILURE);
	check_map(argv[1], &data);
}
