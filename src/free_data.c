#include "cub3d.h"

void	free_full_data(t_data *data)
{
	if (data->map_data->ceiling_color)
		free(data->map_data->ceiling_color);
	if (data->map_data->floor_color)
		free(data->map_data->floor_color);
	close_fds(data);
	if (data->map)
		ft_freepp((void **) data->map);
	if (data->copy)
		ft_freepp((void **) data->copy);
	if (data->map_data)
		free(data->map_data);
}

void	close_fds(t_data *data)
{
	if (data->map_data->north_wall != 0)
		close(data->map_data->north_wall);
	if (data->map_data->south_wall != 0)
		close(data->map_data->south_wall);
	if (data->map_data->east_wall != 0)
		close(data->map_data->east_wall);
	if (data->map_data->west_wall != 0)
		close(data->map_data->west_wall);
}
