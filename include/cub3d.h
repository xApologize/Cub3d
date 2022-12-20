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
# define ERR_ASSET_EXT "the assets you pass in the map information must have a\
 .xpm extension.\n"
# define ERR_ARG_PATH "one of the path in the map information is not valid.\n"
# define ERR_COL_LINE "one of the line in the map information is not valid.\n"
# define ERR_NOT_DIGIT "the argument for the colours in the map needs to be\
 digit characters only.\n"
# define ERR_NOT_UCHAR "the argument for the colours in the map needs to be\
 a number that fit within a unsigned char(0 to 255).\n"
# define ERR_ARG_NAME "one of the argument you passed in the map was not a\
 valid argument.\n"
# define ERR_WRONG_CHAR_MAP "one of the character in the map is not a valid\
 one. The valid ones are : N, S, E, W, 0 and 1.\n"
# define ERR_START_POINT "the map need to have no more and no less than one\
 starting point.\n"
# define ERR_MAP_NOT_EXIST "the map you passed in the program argument did\
 not exist.\n"
# define ERR_MAP_DIR "the map you passed in the program argument was a\
 directory.\n"

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
	int				start_pos[2];
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

//check_map
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
void	set_start_pos(t_data *data);

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

//flood_fill
//flood_fill.c
void	flood_fill(t_data *data);
void	flood_fill_algo_in(int x, int y, char **map_copy);
void	check_map_x(char **map);

//flood_fill_utils.c
char	**copy_map(t_data *data);

//error.c
void	error_and_exit(char *err_msg);
void	error_and_free(t_data *data, char *err_msg, int flag);
void	error_code_arg(t_data *data, int err_code);

//free_data.c
void	free_full_data(t_data *data);
void	close_fds(t_data *data);

#endif
