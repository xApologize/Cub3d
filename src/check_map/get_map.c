#include "cub3d.h"

void	set_map(char *map, t_data *data)
{
	data->map = NULL;
	check_extension(map, EXTENSION_MAP);
	get_map(check_map_exist(map), data);
}

void	get_map(int map_fd, t_data *data)
{
	char	*gnl_ret;
	char	*map;

	map = NULL;
	gnl_ret = NULL;
	gnl_ret = get_next_line(map_fd);
	map = ft_strjoinfree(map, gnl_ret);
	while (1)
	{
		gnl_ret = get_next_line(map_fd);
		if (gnl_ret == NULL)
			break ;
		map = ft_strjoinfree(map, gnl_ret);
	}
	data->map = ft_split(map, '\n');
	free(map);
	close(map_fd);
}
