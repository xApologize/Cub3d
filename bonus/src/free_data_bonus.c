/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:15:46 by jrossign          #+#    #+#             */
/*   Updated: 2023/02/02 11:08:09 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	free_full_data(t_data *data)
{
	destroy_image(data);
	free_map_data(data);
	free_tex(data);
	free_ray(data);
}

void	free_map_data(t_data *data)
{
	if (data->map_data->ceiling_color)
		free(data->map_data->ceiling_color);
	if (data->map_data->floor_color)
		free(data->map_data->floor_color);
	if (data->map_data->north_wall)
		free(data->map_data->north_wall);
	if (data->map_data->south_wall)
		free(data->map_data->south_wall);
	if (data->map_data->west_wall)
		free(data->map_data->west_wall);
	if (data->map_data->east_wall)
		free(data->map_data->east_wall);
	if (data->map)
		ft_freepp((void **) data->map);
	if (data->copy)
		ft_freepp((void **) data->copy);
	if (data->map_data)
		free(data->map_data);
}

void	free_tex(t_data *data)
{
	if (data->tex->north)
		ft_freepp((void **)data->tex->north);
	if (data->tex->south)
		ft_freepp((void **)data->tex->south);
	if (data->tex->east)
		ft_freepp((void **)data->tex->east);
	if (data->tex->west)
		ft_freepp((void **)data->tex->west);
	if (data->tex)
		free(data->tex);
}

void	free_ray(t_data *data)
{
	if (data->ray)
		free(data->ray);
}

void	destroy_image(t_data *data)
{
	mlx_delete_xpm42(data->tex->east_tex);
	mlx_delete_xpm42(data->tex->west_tex);
	mlx_delete_xpm42(data->tex->north_tex);
	mlx_delete_xpm42(data->tex->south_tex);
	mlx_delete_xpm42(data->tex->overlay);
}
