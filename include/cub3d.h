#ifndef CUB3D_H
# define CUB3D_H

# define EXTENSION ".cub"

# include "../lib/libft/include/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_data
{
	char	**map;
} 			t_data;

//check_map.c
void	check_map(char *map, t_data *data);
void	check_extension(char *map);
void	get_map(int map_fd, t_data *data);
int		check_map_exist(char *map);

#endif
