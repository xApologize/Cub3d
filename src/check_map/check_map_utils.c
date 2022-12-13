#include "cub3d.h"

void	set_map_only(t_data *data)
{
	int		i;
	char	**tmp;

	i = 0;
	while (data->map[i + 6])
		i++;
	tmp = ft_calloc(sizeof(char *),  i + 1);
	i = 0;
	while (data->map[i + 6])
	{
		tmp[i] = ft_strdup(data->map[i + 6]);
		i++;
	}
	ft_freepp((void **) data->map);
	data->map = tmp;
}
