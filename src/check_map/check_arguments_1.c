#include "cub3d.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void	set_colors(t_data *data)
{
	char	*tmp;

	tmp = ft_strdup(data->map_data->ceiling_color[1]);
	if (ft_strcmp(data->map_data->ceiling_color[0], "C") == 0)
	{
		ft_freepp((void **) data->map_data->ceiling_color);
		data->map_data->ceiling_color = ft_split(tmp, ',');
	}
	free(tmp);
	tmp = ft_strdup(data->map_data->floor_color[1]);
	if (ft_strcmp(data->map_data->floor_color[0], "F") == 0)
	{
		ft_freepp((void **) data->map_data->floor_color);
		data->map_data->floor_color = ft_split(tmp, ',');
	}
	free(tmp);
	check_colors(data);
}

void	check_colors(t_data *data)
{
	check_isdigit(data->map_data->ceiling_color);
	check_isdigit(data->map_data->floor_color);
	check_isuchar(data->map_data->ceiling_color);
	check_isuchar(data->map_data->floor_color);
}

void	check_isdigit(char **colors)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (colors[i])
	{
		while (colors[i][j])
		{
			if (!ft_isdigit(colors[i][j]))
			{
				printf("Error isdigit: %c\n", colors[i][j]);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	check_isuchar(char **colors)
{
	int	i;

	i = 0;
	while (colors[i])
	{
		if (ft_atoi(colors[i]) > UCHAR_MAX || ft_atoi(colors[i]) < 0)
		{
			printf("Error colors is not rgb: %s\n", colors[i]);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
