
#include "cub3d.h"

void	init_var(t_data *data, double i)
{
	data->ray->camera = 2 * i /  (double) WIDTH - 1;
	data->ray->rayX = data->ray->dirX + data->ray->planeX * data->ray->camera;
	data->ray->rayY = data->ray->dirY + data->ray->planeY * data->ray->camera;
	data->ray->mapX = data->ray->posX;
	data->ray->mapY = data->ray->posY;	
	data->ray->deltaX = fabs(1 / data->ray->rayX);
	data->ray->deltaY = fabs(1 / data->ray->rayY);
}

void	init_dist(t_data *data)
{
	if (data->ray->rayX < 0)
	{
		data->ray->stepX = -1;
		data->ray->distX = (data->ray->posX - data->ray->mapX) * data->ray->deltaX;
	}
	else
	{
		data->ray->stepX = 1;
		data->ray->distX = (data->ray->mapX - data->ray->posX + 1) * data->ray->deltaX;
	}
	if (data->ray->rayY < 0)
	{
		data->ray->stepY = -1;
		data->ray->distY = (data->ray->posY - data->ray->mapY) * data->ray->deltaY;
	}
	else
	{
		data->ray->stepY = 1;
		data->ray->distY = (data->ray->mapY - data->ray->posY  + 1) * data->ray->deltaY;
	}
}

void	start_var(t_data *data)
{
	data->ray->mlx = mlx_init(WIDTH, HEIGHT, "test", false);
	data->ray->img = mlx_new_image(data->ray->mlx, WIDTH, HEIGHT);
	data->ray->posX = data->start_pos[1];
	data->ray->posY = data->start_pos[0];
	data->ray->dirX = 0; //pour 1 planeY 0.66 pour -1 planeY -0.66
	data->ray->dirY = -1;// pour 1 planeX -0.66 pour -1 planeX 0.66
	data->ray->planeX = 0.66;
	data->ray->planeY = 0;
	data->ray->mSpeed = 0.1;
	data->ray->sSpeed = 0.15;
	data->ray->rays = false;
	data->ray->ceiling = create_colour(data->map_data->ceiling_color[0], data->map_data->ceiling_color[1], data->map_data->ceiling_color[2], 255);
	data->ray->floor = create_colour(data->map_data->floor_color[0], data->map_data->floor_color[1], data->map_data->floor_color[2], 255);
}