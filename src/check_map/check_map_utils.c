/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:17:19 by jrossign          #+#    #+#             */
/*   Updated: 2022/12/21 14:17:34 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
