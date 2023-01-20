/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:13:57 by jrossign          #+#    #+#             */
/*   Updated: 2023/01/20 11:22:34 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	print_data(t_data *data)
{
	int	i;

	i = 0;
	printf("data.map:\n");
	while (data->map[i])
	{
		printf("%s\n", data->map[i]);
		i++;
	}
	printf("data.map.start_pos[0]: %i\n", data->start_pos[0]);
	printf("data.map.start_pos[1]: %i\n", data->start_pos[1]);
	printf("data.map_data.north_wall: %s\n", data->map_data->north_wall);
	printf("data.map_data.south_wall: %s\n", data->map_data->south_wall);
	printf("data.map_data.east_wall: %s\n", data->map_data->east_wall);
	printf("data.map_data.west_wall: %s\n", data->map_data->west_wall);
	printf("data.map_data.ceiling_color[0]: %d\n",
		data->map_data->ceiling_color[0]);
	printf("data.map_data.ceiling_color[1]: %d\n",
		data->map_data->ceiling_color[1]);
	printf("data.map_data.ceiling_color[2]: %d\n",
		data->map_data->ceiling_color[2]);
	printf("data.map_data.floor_color[0]: %d\n", data->map_data->floor_color[0]);
	printf("data.map_data.floor_color[1]: %d\n", data->map_data->floor_color[1]);
	printf("data.map_data.floor_color[2]: %d\n", data->map_data->floor_color[2]);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		error_and_free(&data, ERR_MAIN_ARG, 0);
	set_map(argv[1], &data);
	check_arguments(&data);
	check_map(&data);
	set_height_width(&data);
	// system("afplay ./sound/SeaShanty2.mp3&");
	init_mlx(&data);
	free_full_data(&data);
	// system("killall afplay");
	return (EXIT_SUCCESS);
}
