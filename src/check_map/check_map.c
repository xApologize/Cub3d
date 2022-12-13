#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>

void	check_map(t_data *data)
{
	set_map_only(data);
	check_map_char(data);
}

void	check_map_char(t_data *data)
{
	int	i;
	int	j;
	int	starting_point;

	i = 0;
	j = 0;
	starting_point = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (!ft_strchr(VALID_MAP_CHAR, data->map[i][j]))
			{
				printf("Error check_map_char invalid char: %c\n", data->map[i][j]);
				exit(EXIT_FAILURE);
			}
			if (ft_strchr(VALID_STARTING_POINT, data->map[i][j]))
				starting_point++;
			j++;
		}
		j = 0;
		i++;
	}
	if (starting_point != 1)
	{
		printf("Error check_map_char more than 1 starting point.\n");
		exit(EXIT_FAILURE);
	}
}
