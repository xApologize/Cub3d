#include "cub3d.h"

void	flood_fill(t_data *data)
{
	char	**map_copy;

	map_copy = copy_map(data);
	int i = 0;
	while (map_copy[i])
	{
		printf("copy: %s\n", map_copy[i]);
		i++;
	}
}
