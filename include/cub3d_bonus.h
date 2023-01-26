/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:15:18 by jrossign          #+#    #+#             */
/*   Updated: 2023/01/26 09:03:19 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

//valid char/extension
# define EXTENSION_MAP ".cub"
# define EXTENSION_TEXTURE ".xpm42"
# define VALID_MAP_CHAR "01 NEWS"
# define VALID_STARTING_POINT "NEWS"

//error message
# define ERROR "Error: "
# define ERR_MALLOC "an error happened when allocating memory.\n"
# define ERR_MAIN_ARG "you must only give the program one argument.\n"
# define ERR_MAP_EMPTY "the map file is empty.\n"
# define ERR_MAP_EXT "the map you pass to the program must have a\
 .cub extension.\n"
# define ERR_ASSET_EXT "the assets you pass in the map information must have a\
 .xpm42 extension.\n"
# define ERR_ARG_PATH "one of the path in the map information is not valid.\n"
# define ERR_COL_LINE "one of the line in the map information is not valid.\n"
# define ERR_COL_NOT_3 "the color you passed in the map information is not a\
 valid RGB value.\n"
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
# define ERR_MAP_OPEN "the map you passed in the file is not surrounded\
 by walls or the map contains space inside the walls.\n"

//error code
# define CODE_PATH_ERR -2
# define CODE_EXT_ERR -3

//mlx stuff
# define WIDTH 1920
# define HEIGHT 1080
# define RSPEED 0.1
# define PI 3.141593
# define MAP_WIDTH 36 // va etre a mettre dans la struct
# define MAP_HEIGHT 42

# include "../lib/libft/include/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdbool.h>

typedef struct s_tex{
	int			**north;
	int			**south;
	int			**east;
	int			**west;
	xpm_t		*north_tex;
	xpm_t		*south_tex;
	xpm_t		*east_tex;
	xpm_t		*west_tex;
	mlx_image_t	*player;
}	t_tex;

typedef struct s_ray{
	int			tex_x;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line;
	int			end;
	int			start;
	int			floor;
	int			ceiling;
	bool		rays;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera;
	double		ray_y;
	double		ray_x;
	double		dist_y;
	double		dist_x;
	double		delta_x;
	double		delta_y;
	double		wall_dist;
	double		ray_length;
	double		m_speed;
	double		s_speed;
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_ray;

typedef struct s_data
{
	int				start_pos[2];
	char			orientation;
	int				map_width;
	int				map_height;
	char			**map;
	char			**copy;
	mlx_image_t		*minimap;
	struct s_ray	*ray;
	struct s_map	*map_data;
	struct s_tex	*tex;
	struct s_anim	*anim;
}					t_data;

typedef struct s_map
{
	int		x;
	int		y;
	int		*ceiling_color;
	int		*floor_color;
	char	*north_wall;
	char	*south_wall;
	char	*east_wall;
	char	*west_wall;
}			t_map;

typedef struct s_anim
{
	int			frame;
	mlx_image_t	*spell_anim[12];
	bool		spell;
}				t_anim;

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
int		get_longest_row(t_data *data);
char	*get_new_string(char *str, int longest);
void	set_map_only(t_data *data);
void	set_map_square(t_data *data);
void	set_space(char *new_string, int longest);

//check_path.c
int		check_extension(char *path, char *extension);
int		check_map_exist(char *map);

//get_map.c
void	set_map(char *map, t_data *data);
void	get_map(int map_fd, t_data *data);
void	set_height_width(t_data *data);

//set_map_struct.c
void	create_map_data(t_data *data);
void	set_texture(t_data *data, char *arg, char **path);
void	set_color(t_data *data, char *arg, char *str);

//flood_fill.c
void	flood_fill(t_data *data);
void	flood_fill_algo(int x, int y, t_data *data);

//flood_fill_utils.c
char	**copy_map(t_data *data);

//animation_spell_bonus.c
void	animation_spell(t_data *data);
void	set_spell_asset(t_data *data);

//data.c
void	init_var(t_data *data, double i);
void	init_dist(t_data *data);
void	start_var(t_data *data);

//draw_minimap_utils.c
void	draw_player_two(t_data *data);
void	draw_map_two(t_data *data);

//draw_minimap.c
void	draw_player(t_data *data);
void	draw_wall(t_data *data, int x, int y);
void	draw_space(t_data *data, int x, int y);
void	draw_map(t_data *data);
void	map(t_data *data);

//error.c
void	error_and_exit(char *err_msg);
void	error_and_free(t_data *data, char *err_msg, int flag);
void	error_code_arg(t_data *data, int err_code);

//free_data.c
void	free_full_data(t_data *data);
void	close_fds(t_data *data);

//moves_1.c
void	turn_right(t_data *data);
void	turn_left(t_data *data);
void	hook_two(mlx_key_data_t keydata, t_data *data);
void	hook(mlx_key_data_t keydata, void *temp);

//moves_2.c
void	forward(t_data *data);
void	backward(t_data *data);
void	right(t_data *data);
void	left(t_data *data);

//raycaster.c
void	init_mlx(t_data *data);
void	raycaster(t_data *data);
void	hook(mlx_key_data_t keydata, void *temp);

//raycasting_utils.c
void	dda(t_data *data);
void	dda_calc(t_data *data);
void	calc_line(t_data *data);
void	find_hit(t_data *data, xpm_t *texture);
void	draw_line(t_data *data, xpm_t *texture, int **arr, int i);

//utils.c
int		create_colour(int r, int g, int b, int a);
void	clear_image(t_data *data);
int		**fill_texture(xpm_t *tex);
void	create_texture(t_data *data);

#endif
