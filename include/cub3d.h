#ifndef CUB3D_H
# define CUB3D_H

# define EXTENSION_MAP ".cub"
# define EXTENSION_TEXTURE ".xpm"

# include "../lib/libft/include/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>

# define WIDTH 1920
# define HEIGHT 1080
# define RSPEED 0.1

# define mapWidth 36 // va etre a mettre dans la struct
# define mapHeight 42
# define PI 3.141593

typedef struct s_tex{
	int		**north;
	int		**south;
	int		**east;
	int		**west;
	xpm_t	*north_tex;
	xpm_t	*south_tex;
	xpm_t	*east_tex;
	xpm_t	*west_tex;
}	t_tex;

typedef struct s_ray{
	int			texX;
	int			mapX;
	int			mapY;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int			line;
	int			end;
	int			start;
	int			floor;
	int			ceiling;
	bool		rays;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double	 	camera;
	double	 	rayY;
	double	 	rayX;
	double		distY;
	double		distX;
	double		deltaX;
	double		deltaY;
	double		wallDist;
	double		rayLenght;
	double		mSpeed;
	double		sSpeed;
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_ray;

typedef struct s_map
{
	int		north_wall;
	int		south_wall;
	int		east_wall;
	int		west_wall;
	int		*ceiling_color;
	int		*floor_color;
}	t_map;

typedef struct s_data
{
	char	**map;
	t_map	*map_data;
	t_tex	*tex;
	t_ray	*ray;
} 	t_data;

//check_arguments.c
void	check_arguments(t_data *data);
void	get_arguments(t_data *data);
void	set_map_data(t_data *data, char *arg, char *str);
void	create_map_data(t_data *data);
int		open_assets_file(char **path);

//check_arguments_1.c
int		*set_colors(char **color);
void	check_colors(char **color);
void	check_isdigit(char **colors);
void	check_isuchar(char **colors);

//check_map.c
void	check_map(char *map, t_data *data);
void	get_map(int map_fd, t_data *data);

//check_path.c
void	check_extension(char *path, char *extension);
int		check_map_exist(char *map);

//raycaster.c
void	init_mlx(t_data *data);
void	raycaster(t_data *data);
void	hook(mlx_key_data_t keydata, void *temp);

//draw.c
void	draw_player(t_data *data);
void	draw_wall(t_data *data, int x, int y);
void	draw_space(t_data *data, int x, int y);
void	draw_map(t_data *data);


#endif
