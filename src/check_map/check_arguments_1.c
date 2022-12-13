#include "cub3d.h"

int	*set_colors(char **color)
{
	int		*rgb;
	char	*tmp;
	char	**split_color;

	if (!color[1])
	{
		printf("Error set_colors: %s\n", color[0]);
		exit(EXIT_FAILURE);
	}
	tmp = ft_strdup(color[1]);
	split_color = ft_split(tmp, ',');
	free(tmp);
	ft_freepp((void **) color);
	check_colors(split_color);
	rgb = malloc(sizeof(int) * 3);
	rgb[0] = ft_atoi(split_color[0]);
	rgb[1] = ft_atoi(split_color[1]);
	rgb[2] = ft_atoi(split_color[2]);
	ft_freepp((void **) split_color);
	return (rgb);

}

void	check_colors(char **color)
{
	check_isdigit(color);
	check_isuchar(color);
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
