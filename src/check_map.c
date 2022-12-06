#include "cub3d.h"
#include <stdio.h>
#include <unistd.h>

void	check_map(char *map, t_data *data)
{
	int		map_fd;
	char	*map_read;

	(void) data;
	(void) map_fd;
	(void) map_read;
	map_read = ft_calloc(sizeof(char), 10000);
	check_extension(map);
	check_map_exist(map);
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
