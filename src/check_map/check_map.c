#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>

void	check_map(char *map, t_data *data)
{
	check_extension(map);
	data->map = ft_calloc(1, 1);
	get_map(check_map_exist(map), data);
}

void	check_extension(char *map)
{
	int		length;
	char	*extension;

	length = ft_strlen(map);
	extension = ft_substr(map, length - ft_strlen(EXTENSION), length);
	if (ft_strncmp(extension, EXTENSION, ft_strlen(EXTENSION)) != 0)
	{
		printf("Error extension\n");
		exit(EXIT_FAILURE);
	}
}

void	get_map(int map_fd, t_data *data)
{
	char	*gnl_ret;
	char	*map;

	gnl_ret = get_next_line(map_fd);
	map = ft_strjoinfree(map, gnl_ret);
	while (1)
	{
		gnl_ret = get_next_line(map_fd);
		if (gnl_ret == NULL)
			break ;
		map = ft_strjoinfree(map, gnl_ret);
	}
	ft_freepp(data->map);
	data->map = ft_split(map, '\n');
	free(map);
}

int check_map_exist(char *map)
{
	int	fd;

	fd = open(map, O_DIRECTORY);
	if (fd > 0)
	{
		printf("The map you passed is a directory\n");
		close(fd);
		exit(EXIT_FAILURE);
	}
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		printf("The map you passed does not exist\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
