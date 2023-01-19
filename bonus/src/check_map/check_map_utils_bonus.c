/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:17:19 by jrossign          #+#    #+#             */
/*   Updated: 2023/01/19 08:27:59 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	get_longest_row(t_data *data)
{
	int	i;
	int	longest;

	i = 0;
	longest = 0;
	while (data->map[i])
	{
		if ((int)ft_strlen(data->map[i]) > longest)
			longest = (int)ft_strlen(data->map[i]);
		i++;
	}
	return (longest);
}

char	*get_new_string(char *str, int longest)
{
	char	*new_string;

	new_string = ft_calloc(sizeof(char), longest + 1);
	ft_strlcpy(new_string, str, ft_strlen(str));
	free(str);
	return (new_string);
}

void	set_map_only(t_data *data)
{
	int		i;
	char	**tmp;

	i = 0;
	while (data->map[i + 6])
		i++;
	tmp = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while (data->map[i + 6])
	{
		tmp[i] = ft_strdup(data->map[i + 6]);
		i++;
	}
	ft_freepp((void **)data->map);
	data->map = tmp;
}

void	set_map_square(t_data *data)
{
	int		i;
	int		longest;

	i = 0;
	longest = get_longest_row(data);
	while (data->map[i])
	{
		if ((int)ft_strlen(data->map[i]) != longest)
			data->map[i] = get_new_string(data->map[i], longest);
		set_space(data->map[i], longest);
		i++;
	}
	data->map[data->start_pos[0]][data->start_pos[1]] = '0';
}

void	set_space(char *new_string, int longest)
{
	int	i;

	i = 0;
	while (i < longest)
	{
		if (new_string[i] != '1' && new_string[i] != '0'
			&& !ft_strchr(VALID_STARTING_POINT, new_string[i]))
			new_string[i] = '1';
		i++;
	}
}
