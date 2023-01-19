/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:21:15 by jrossign          #+#    #+#             */
/*   Updated: 2022/12/21 14:21:17 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**copy_map(t_data *data)
{
	int		len;
	char	**copy;

	len = 0;
	while (data->map[len])
		len++;
	copy = ft_calloc(sizeof(char *), len + 1);
	len = 0;
	while (data->map[len])
	{
		copy[len] = ft_strdup(data->map[len]);
		len++;
	}
	return (copy);
}
