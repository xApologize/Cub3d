/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:13:10 by jrossign          #+#    #+#             */
/*   Updated: 2023/02/02 11:29:51 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_colour(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	clear_image(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
		{
			if (j <= HEIGHT / 2)
				mlx_put_pixel(data->ray->img, i, j, data->ray->ceiling);
			else
				mlx_put_pixel(data->ray->img, i, j, data->ray->floor);
		}
	}
}

int	**fill_texture(xpm_t *tex)
{
	int	**arr;
	int	i;
	int	j;

	arr = ft_calloc(sizeof(int *), tex->texture.height + 1);
	i = 3;
	while (++i < (int) tex->texture.height + 4)
	{
		j = 3;
		arr[i - 4] = ft_calloc(sizeof(int), tex->texture.width);
		while (++j < (int) tex->texture.width + 4)
			arr[i - 4][j - 4] = create_colour(
					tex->texture.pixels[(tex->texture.width * 4 * (i - 4))
					+ (4 * (j - 4)) + 0],
					tex->texture.pixels[(tex->texture.width
						* 4 * (i - 4)) + (4 * (j - 4)) + 1],
					tex->texture.pixels[(tex->texture.width * 4 * (i - 4))
					+ (4 * (j - 4)) + 2],
					tex->texture.pixels[(tex->texture.width
						* 4 * (i - 4)) + (4 * (j - 4)) + 3]);
	}
	return (arr);
}

void	create_texture(t_data *data)
{
	data->tex = ft_calloc(1, sizeof(t_tex));
	if (!data->tex)
		exit(1);
	data->tex->east_tex = mlx_load_xpm42(data->map_data->east_wall);
	if (!data->tex->east_tex)
		exit(1);
	data->tex->west_tex = mlx_load_xpm42(data->map_data->west_wall);
	if (!data->tex->west_tex)
		exit(1);
	data->tex->north_tex = mlx_load_xpm42(data->map_data->north_wall);
	if (!data->tex->north_tex)
		exit(1);
	data->tex->south_tex = mlx_load_xpm42(data->map_data->south_wall);
	if (!data->tex->south_tex)
		exit(1);
	data->tex->east = fill_texture(data->tex->east_tex);
	data->tex->west = fill_texture(data->tex->west_tex);
	data->tex->north = fill_texture(data->tex->north_tex);
	data->tex->south = fill_texture(data->tex->south_tex);
}
