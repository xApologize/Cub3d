/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:16:51 by jrossign          #+#    #+#             */
/*   Updated: 2022/12/21 14:16:55 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*get_colors(t_data *data, char **color, char *arg)
{
	int		*rgb;
	char	*tmp;
	char	**split_color;

	if (!color[1])
	{
		ft_freepp((void **) color);
		return (NULL);
	}
	tmp = ft_strdup(color[1]);
	split_color = ft_split(tmp, ',');
	free(tmp);
	ft_freepp((void **) color);
	check_colors(data, split_color, arg);
	rgb = malloc(sizeof(int) * 3);
	rgb[0] = ft_atoi(split_color[0]);
	rgb[1] = ft_atoi(split_color[1]);
	rgb[2] = ft_atoi(split_color[2]);
	ft_freepp((void **) split_color);
	return (rgb);
}

void	check_colors(t_data *data, char **color, char *arg)
{
	if (check_isdigit(color))
	{
		free(arg);
		ft_freepp((void **)color);
		error_and_free(data, ERR_NOT_DIGIT, 1);
	}
	if (check_isuchar(color))
	{
		free(arg);
		ft_freepp((void **)color);
		error_and_free(data, ERR_NOT_UCHAR, 1);
	}
}

int	check_isdigit(char **colors)
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
				return (1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	check_isuchar(char **colors)
{
	int	i;

	i = 0;
	while (colors[i])
	{
		if (ft_atoi(colors[i]) > UCHAR_MAX || ft_atoi(colors[i]) < 0)
			return (1);
		i++;
	}
	return (0);
}
