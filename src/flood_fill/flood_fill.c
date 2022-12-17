#include "cub3d.h"
#include <stdio.h>
#include <unistd.h>

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

void	flood_fill(t_data *data)
{
	char	**map_copy;

	map_copy = copy_map(data);
	// flood_fill_algo_border(0, 0, map_copy);
	flood_fill_algo_in(data->start_pos[0], data->start_pos[1], map_copy);
	print_map(map_copy);
	// check_map_x(map_copy);
}

void	flood_fill_algo_in(int x, int y, char **map_copy)
{
	if (map_copy[x - 1][y] == '0')
	{
		map_copy[x - 1][y] = 'f';
		flood_fill_algo_in(x - 1, y, map_copy);
	}
	if (map_copy[x][y + 1] == '0')
	{
		map_copy[x][y + 1] = 'f';
		flood_fill_algo_in(x, y + 1, map_copy);
	}
	if (map_copy[x + 1][y] == '0')
	{
		map_copy[x + 1][y] = 'f';
		flood_fill_algo_in(x + 1, y, map_copy);
	}
	if (map_copy[x][y - 1] == '0')
	{
		map_copy[x][y - 1] = 'f';
		flood_fill_algo_in(x, y - 1, map_copy);
	}
	return ;
}

void flood_fill_algo_border(int x, int y, char **map_copy)
{
	int	i;

	i = 0;
	while (map_copy[i++]);
	if ((x - 1 >= 0) && map_copy[x - 1][y] == '1')
	{
		map_copy[x - 1][y] = 'w';
		flood_fill_algo_border(x - 1, y, map_copy);
	}
	if (((size_t)y + 1 < ft_strlen(map_copy[x])) && map_copy[x][y + 1] == '1')
	{
		map_copy[x][y + 1] = 'w';
		flood_fill_algo_border(x, y + 1, map_copy);
	}
	if ((x + 1 < i - 1) && map_copy[x + 1][y] == '1')
	{
		map_copy[x + 1][y] = 'w';
		flood_fill_algo_border(x + 1, y, map_copy);
	}
	if ((y - 1 >= 0) && map_copy[x][y - 1] == '1')
	{
		map_copy[x][y - 1] = 'w';
		flood_fill_algo_border(x, y - 1, map_copy);
	}
	return ;
}

void	check_map_x(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if ((map[y][x] == 'x')
				&& (map[y + 1][x] == ' ' || map[y - 1][x] == ' '
				|| map[y][x + 1] == ' ' || map[y][x - 1] == ' '))
				printf("Error : check_map_x\n");
			x++;
		}
		x = 0;
		y++;
	}
}
