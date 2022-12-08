#ifndef CUB3D_H
# define CUB3D_H

# define EXTENSION ".cub"

# include "../lib/libft/include/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_data
{
	char			**map;
	struct s_map	*map_data;
} 					t_data;

typedef struct s_map
{
	char	*north_wall;
	char	*south_wall;
	char	*east_wall;
	char	*west_wall;
	char	*ceiling_color;
	char	*floor_color;
}			t_map;

//check_map/check_arguments.c
void	check_aguments(t_data *data);
void	get_arguments(t_data *data);
void	set_map_data(t_data *data, char *arg, char *str);
void	create_map_data(t_data *data);
void	open_assets_file(t_data *data);

//check_map/check_map.c
void	check_map(char *map, t_data *data);
void	get_map(int map_fd, t_data *data);

//check_map/check_path.c
void	check_extension(char *map);
int		check_map_exist(char *map);

#endif
