#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/include/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <math.h>
# include <string.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_ray{
	mlx_t		*mlx;
	mlx_image_t	*img;
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
	int			mapX;
	int			mapY;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int			line;
	int			end;
	int			start;
}	t_ray;

#endif
