#ifndef CUB3D_H
# define CUB3D_H

# define EXTENSION_MAP ".cub"
# define EXTENSION_TEXTURE ".xpm"

# include "../lib/libft/include/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_data
{
	char			**map;
	struct s_map	*map_data;
} 					t_data;

typedef struct s_map
{
	int		north_wall;
	int		south_wall;
	int		east_wall;
	int		west_wall;
	char	**ceiling_color;
	char	**floor_color;
}			t_map;

//check_arguments.c
void	check_arguments(t_data *data);
void	get_arguments(t_data *data);
void	set_map_data(t_data *data, char *arg, char *str);
void	create_map_data(t_data *data);
int		open_assets_file(char **path);

//check_arguments_1.c
void	set_colors(t_data *data);
void	check_colors(t_data *data);
void	check_isdigit(char **colors);
void	check_isuchar(char **colors);

//check_map.c
void	check_map(char *map, t_data *data);
void	get_map(int map_fd, t_data *data);

//check_path.c
void	check_extension(char *path, char *extension);
int		check_map_exist(char *map);

#endif
