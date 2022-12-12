#include "cub3d.h"

void	check_extension(char *path, char *extension)
{
	int		length;
	char	*path_extension;

	length = ft_strlen(path);
	path_extension = ft_substr(path, length - ft_strlen(extension), length);
	if (ft_strncmp(extension, path_extension, ft_strlen(extension)) != 0)
	{
		printf("Error extension: %s\n", extension);
		free(path_extension);
		exit(EXIT_FAILURE);
	}
	free(path_extension);
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
