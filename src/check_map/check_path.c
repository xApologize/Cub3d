#include "cub3d.h"
#include <stdlib.h>

void	check_extension(char *map)
{
	int		length;
	char	*extension;

	length = ft_strlen(map);
	extension = ft_substr(map, length - ft_strlen(EXTENSION), length);
	if (ft_strncmp(extension, EXTENSION, ft_strlen(EXTENSION)) != 0)
	{
		printf("Error extension\n");
		free(extension);
		exit(EXIT_FAILURE);
	}
	free(extension);
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
