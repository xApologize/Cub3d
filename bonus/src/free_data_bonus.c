/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:15:46 by jrossign          #+#    #+#             */
/*   Updated: 2023/02/01 08:03:42 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	if (data->map_data->north_wall)
		free(data->map_data->north_wall);
	if (data->map_data->south_wall)
		free(data->map_data->south_wall);
	if (data->map_data->east_wall)
		free(data->map_data->east_wall);
	if (data->map_data->west_wall)
		free(data->map_data->west_wall);
}
