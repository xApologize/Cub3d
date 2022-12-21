#include "cub3d.h"

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
	data->copy = copy_map(data);
	flood_fill_algo(data->start_pos[0], data->start_pos[1], data);
}

void	flood_fill_algo(int x, int y, t_data *data)
{
	int	i;
	
	i = 0;
	while (data->copy[i++]);
	if (((x - 1 < 0 || y - 1 < 0 || x + 1 >= i - 1
		|| (size_t)y + 1 >= ft_strlen(data->copy[x]))
		&& ft_strchr("0 ", data->copy[x][y])) || data->copy[x][y] == ' ')
		error_and_free(data, ERR_MAP_OPEN, 1);
	if (data->copy[x][y] == '0'
		|| ft_strchr(VALID_STARTING_POINT, data->copy[x][y]))
		data->copy[x][y] = '.';
	else
		return ;
	flood_fill_algo(x - 1, y, data);
	flood_fill_algo(x, y + 1, data);
	flood_fill_algo(x + 1, y, data);
	flood_fill_algo(x, y - 1, data);
	flood_fill_algo(x + 1, y + 1, data);
	flood_fill_algo(x - 1, y + 1, data);
	flood_fill_algo(x + 1, y - 1, data);
	flood_fill_algo(x - 1, y - 1, data);
}

// void	flood_fill_algo_in(int x, int y, char **map_copy)
// {
	// int	i;
	//
	// usleep(90000);
	// print_map(map_copy);
	// i = 0;
	// while (map_copy[i++]);
	// if (x - 1 >= 0 && map_copy[x - 1][y] == '0')
	// {
	// 	map_copy[x - 1][y] = '.';
	// 	flood_fill_algo_in(x - 1, y, map_copy);
	// }
	// if ((size_t)y + 1 < ft_strlen(map_copy[x]) && map_copy[x][y + 1] == '0')
	// {
	// 	map_copy[x][y + 1] = '.';
	// 	flood_fill_algo_in(x, y + 1, map_copy);
	// }
	// if (x + 1 < i - 1 && map_copy[x + 1][y] == '0')
	// {
	// 	map_copy[x + 1][y] = '.';
	// 	flood_fill_algo_in(x + 1, y, map_copy);
	// }
	// if (y - 1 >= 0 && map_copy[x][y - 1] == '0')
	// {
	// 	map_copy[x][y - 1] = '.';
	// 	flood_fill_algo_in(x, y - 1, map_copy);
	// }
	// return ;
// }

//not useful yet
// void flood_fill_algo_border(int x, int y, char **map_copy)
// {
// 	int	i;
//
// 	usleep(90000);
// 	print_map(map_copy);
// 	i = 0;
// 	while (map_copy[i++]);
// 	if ((x - 1 >= 0) && map_copy[x - 1][y] == '1')
// 	{
// 		map_copy[x - 1][y] = 'w';
// 		flood_fill_algo_border(x - 1, y, map_copy);
// 	}
// 	if (((size_t)y + 1 < ft_strlen(map_copy[x])) && map_copy[x][y + 1] == '1')
// 	{
// 		map_copy[x][y + 1] = 'w';
// 		flood_fill_algo_border(x, y + 1, map_copy);
// 	}
// 	if ((x + 1 < i - 1) && map_copy[x + 1][y] == '1')
// 	{
// 		map_copy[x + 1][y] = 'w';
// 		flood_fill_algo_border(x + 1, y, map_copy);
// 	}
// 	if ((y - 1 >= 0) && map_copy[x][y - 1] == '1')
// 	{
// 		map_copy[x][y - 1] = 'w';
// 		flood_fill_algo_border(x, y - 1, map_copy);
// 	}
// 	return ;
// }

//not working
// void	check_map_x(char **map)
// {
// 	int	x;
// 	int	y;
// 	int	len;
//
// 	x = 0;
// 	y = 0;
// 	len = 0;
// 	while (map[len++]);
// 	while (map[y])
// 	{
// 		while (map[y][x])
// 		{
// 			if (map[y][x] == 'x')
// 			{
// 				if ((x == 0) || (x == (int)ft_strlen(map[y])))
// 				{
// 					printf("error\n");
// 					exit(EXIT_FAILURE);
// 				}
// 				if ((y == 0) || (y == len))
// 				{
// 					printf("error\n");
// 					exit(EXIT_FAILURE);
// 				}
// 			}
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// }
