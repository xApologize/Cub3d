#include "cub3d.h"

void	check_arguments(t_data *data)
{
	create_map_data(data);
	get_arguments(data);
}

void	get_arguments(t_data *data)
{
	int		i;

	i = 0;
	while (i < 6)
	{
		if (ft_isalpha(data->map[i][1]))
			set_map_data(data, ft_substr(data->map[i], 0, 2), data->map[i]);
		else
			set_map_data(data, ft_substr(data->map[i], 0, 1), data->map[i]);
		i++;
	}
}

void	set_map_data(t_data *data, char *arg, char *str)
{
	int	fd;

	if (!ft_strcmp(arg, "NO") || !ft_strcmp(arg, "SO")
			|| !ft_strcmp(arg, "EA") || !ft_strcmp(arg, "WE"))
	{
		fd = open_assets_file(ft_split(str, ' '));
		set_texture(data, arg, fd);
	}
	else if (!ft_strcmp(arg, "C") || !ft_strcmp(arg, "F"))
		set_color(data, arg, str);
	else
	{
		printf("error set_map_data\n");
		free(arg);
		exit(EXIT_FAILURE);
	}
	free(arg);
}

int	open_assets_file(char **path)
{
	int		fd;

	if (!path[1])
	{
		ft_freepp((void **) path);
		return (CODE_PATH_ERR);
	}
	if (check_extension(path[1], EXTENSION_TEXTURE) == -1)
	{
		ft_freepp((void **) path);
		return (CODE_EXT_ERR);
	}
	fd = open(path[1], O_RDONLY);
	ft_freepp((void**)path);
	return (fd);
}
