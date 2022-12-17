
#include "cub3d.h"

char	**copy_map(t_data *data)
{
	int		len;
	char	**copy;

	len = 0;
	while (data->map[len])
		len++;
	copy = malloc(sizeof(char *) * len + 1);
	len = 0;
	while (data->map[len])
	{
		copy[len] = ft_strdup(data->map[len]);
		len++;
	}
	copy[len] = "\0";
	return (copy);
}
