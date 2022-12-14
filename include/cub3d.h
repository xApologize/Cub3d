#ifndef CUB3D_H
# define CUB3D_H

//valid char/extension
# define EXTENSION_MAP ".cub"
# define EXTENSION_TEXTURE ".xpm"
# define VALID_MAP_CHAR "01 NEWS"
# define VALID_STARTING_POINT "NEWS"

//error message
# define ERROR "Error: "
# define ERR_MALLOC "an error happened when allocating memory.\n"
# define ERR_MAIN_ARG "you must only give the program one argument.\n"
# define ERR_MAP_EXT "the map you pass to the program must have a\
 .cub extension.\n"
# define ERR_ASSET_EXT "the asset you pass in the map information must have a\
 .xpm extension.\n"
# define ERR_ARG_PATH "one of the path in the map information is not valid.\n"
# define ERR_COL_LINE "one of the line in the map information is not valid.\n"
# define ERR_NOT_DIGIT "the argument for the colors in the map needs to be\
 numeric characters only.\n"
# define ERR_NOT_UCHAR "the argument for the colors in the map needs to be\
 a number that fit within a unsigned char(0 to 255)\n"

//error code
# define CODE_PATH_ERR -2
# define CODE_EXT_ERR -3

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
	int	x;
	int	y;
	int	north_wall;
	int	south_wall;
	int	east_wall;
	int	west_wall;
	int	*ceiling_color;
	int	*floor_color;
}			t_map;

//check_arguments.c
void	check_arguments(t_data *data);
void	get_arguments(t_data *data);
void	set_map_data(t_data *data, char *arg, char *str);
int		open_assets_file(char **path);

//check_arguments_1.c
int		*get_colors(t_data *data, char **color, char *arg);
void	check_colors(t_data *data, char **color, char *arg);
int		check_isdigit(char **colors);
int		check_isuchar(char **colors);

//check_map.c
void	check_map(t_data *data);
void	check_map_char(t_data *data);

//check_map_utils.c
void	set_map_only(t_data *data);

//check_path.c
int		check_extension(char *path, char *extension);
int		check_map_exist(char *map);

//get_map.c
void	set_map(char *map, t_data *data);
void	get_map(int map_fd, t_data *data);

//set_map_struct.c
void	create_map_data(t_data *data);
void	set_texture(t_data *data, char *arg, int fd);
void	set_color(t_data *data, char *arg, char *str);

//error.c
void	error_and_free(t_data *data, char *err_msg, int flag);
void	error_code_arg(t_data *data, int err_code);

//free_data.c
void	free_full_data(t_data *data);
void	close_fds(t_data *data);

#endif
