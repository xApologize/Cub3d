
#include "../include/cub3d.h"

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	draw_player(t_data *data, int x, int y)
{
	int hold;
	int hold2;

	hold = y + 9;
	while (y < hold)
	{
		hold2 = x + 9;
		while (x < hold2)
			mlx_put_pixel(data->ray->img, x++, y, 0x8a15bdFF);
		y++;
		x -= 9;
	}
	y -= 9;	
}

void	draw_wall(t_data *data, int x, int y)
{
	int hold;
	int hold2;

	hold = y + 9;
	while (y < hold)
	{
		hold2 = x + 9;
		while (x < hold2)
			mlx_put_pixel(data->ray->img, x++, y, 0xFFFFFFFF);
		y++;
		x -= 9;
	}
	y -= 9;
}

void	draw_space(t_data *data, int x, int y)
{
	int hold;
	int hold2;

	hold = y + 9;
	while (y < hold)
	{
		hold2 = x + 9;
		while (x < hold2)
			mlx_put_pixel(data->ray->img, x++, y, 0x000000FF);
		y++;
		x -= 9;
	}
	y -= 9;
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;
	int x;
	int	y;

	i = -1;
	y = 0;
	while (++i < mapHeight)
	{
		j = -1;
		x = 0;
		while (++j < mapWidth)
		{
			if (j == (int) data->ray->posX && i == (int) data->ray->posY)
				draw_player(data, x, y);
			else if (worldMap[i][j] != 0)
				draw_wall(data, x, y);
			else
				draw_space(data, x, y);
			x+= 10;
		}
		y += 10;
	}
}

void	init_var(t_data *data, int i)
{
	data->ray->camera = 2 * i / (double) WIDTH + 1;
	data->ray->rayX = data->ray->dirX + data->ray->planeX * data->ray->camera;
	data->ray->rayY = data->ray->dirY + data->ray->planeY * data->ray->camera;
	data->ray->mapX = (int) data->ray->posX;
	data->ray->mapY = (int) data->ray->posY;	
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
		data->ray->distX = (data->ray->posX - data->ray->mapX + 1) * data->ray->deltaX;
	}
	if (data->ray->rayY < 0)
	{
		data->ray->stepY = -1;
		data->ray->distY = (data->ray->posY - data->ray->mapY) * data->ray->deltaY;
	}
	else
	{
		data->ray->stepY = 1;
		data->ray->distY = (data->ray->posY - data->ray->mapY + 1) * data->ray->deltaY;
	}
}

void	dda(t_data *data)
{
	while (1)
	{
		if (data->ray->distX < data->ray->distY)
		{
			data->ray->distX += data->ray->deltaX;
			data->ray->mapX += data->ray->stepX;
			data->ray->side = 0;
		}
		else
		{
			data->ray->distY += data->ray->deltaY;
			data->ray->mapY += data->ray->stepY;
			data->ray->side = 1;
		}
		if (worldMap[data->ray->mapY][data->ray->mapX] != 0)
			break ;
	}
	if (data->ray->side == 0)
		data->ray->wallDist = data->ray->distX - data->ray->deltaX;
	else
		data->ray->wallDist = data->ray->distY - data->ray->deltaY;
}

void	calc_line(t_data *data)
{
	data->ray->line = (int) HEIGHT / data->ray->wallDist;
	data->ray->start = -data->ray->line / 2 + HEIGHT / 2;
	if (data->ray->start < 0)
		data->ray->start = 0;
	data->ray->end = data->ray->line / 2 + HEIGHT / 2;
	if (data->ray->end >= HEIGHT)
		data->ray->end = HEIGHT - 1;
}

void	clear_image(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
		{
			if (j <= HEIGHT / 2)
				mlx_put_pixel(data->ray->img, i, j, data->ray->ceiling);
			else
				mlx_put_pixel(data->ray->img, i, j, data->ray->floor);
		}
	}
}

void	raycaster(t_data *data)
{
	int		i;

	i = -1;
	clear_image(data);
	while (++i < WIDTH)
	{
		init_var(data, i);
		init_dist(data);
		dda(data);
		calc_line(data);
		while (data->ray->start < data->ray->end)
		{
			if (data->ray->side == 0)
				mlx_put_pixel(data->ray->img, i, data->ray->start++, 0xa103fcFF);
			else
				mlx_put_pixel(data->ray->img, i, data->ray->start++, 0x0000FFFF);
		}
	}
	draw_map(data);
	mlx_image_to_window(data->ray->mlx, data->ray->img, 0, 0);
}

void	hook(mlx_key_data_t keydata, void *temp)
{
	t_data *data;

	data = temp;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(data->ray->mlx);
	if (keydata.key == MLX_KEY_D)
	{
      	double oldDirX = data->ray->dirX;
    	data->ray->dirX =data->ray->dirX * cos(data->ray->rSpeed) - data->ray->dirY * sin(data->ray->rSpeed);
     	data->ray->dirY = oldDirX * sin(data->ray->rSpeed) + data->ray->dirY * cos(data->ray->rSpeed);
      	double oldPlaneX = data->ray->planeX;
      	data->ray->planeX = data->ray->planeX * cos(data->ray->rSpeed) - data->ray->planeY * sin(data->ray->rSpeed);
      	data->ray->planeY = oldPlaneX * sin(data->ray->rSpeed) + data->ray->planeY * cos(data->ray->rSpeed);
	}
	if (keydata.key == MLX_KEY_A)
	{
      	double oldDirX = data->ray->dirX;
    	data->ray->dirX = data->ray->dirX * cos(-data->ray->rSpeed) - data->ray->dirY * sin(-data->ray->rSpeed);
     	data->ray->dirY = oldDirX * sin(-data->ray->rSpeed) + data->ray->dirY * cos(-data->ray->rSpeed);
      	double oldPlaneX = data->ray->planeX;
      	data->ray->planeX = data->ray->planeX * cos(-data->ray->rSpeed) - data->ray->planeY * sin(-data->ray->rSpeed);
      	data->ray->planeY = oldPlaneX * sin(-data->ray->rSpeed) + data->ray->planeY * cos(-data->ray->rSpeed);
	}
	if(keydata.key == MLX_KEY_W)
    {
    	if(worldMap[(int)(data->ray->posX + data->ray->dirX * data->ray->mSpeed)][(int)(data->ray->posY)] == false) 
			data->ray->posX += data->ray->dirX * data->ray->mSpeed;
    	if(worldMap[(int)(data->ray->posX)][(int)(data->ray->posY + data->ray->dirY * data->ray->mSpeed)] == false)
			data->ray->posY += data->ray->dirY * data->ray->mSpeed;
    }

    if(keydata.key == MLX_KEY_S)
    {
		if(worldMap[(int)(data->ray->posX - data->ray->dirX * data->ray->mSpeed)][(int)(data->ray->posY)] == false) 
	  		data->ray->posX -= data->ray->dirX * data->ray->mSpeed;
		if(worldMap[(int)(data->ray->posX)][(int)(data->ray->posY - data->ray->dirY * data->ray->mSpeed)] == false)
	  		data->ray->posY -= data->ray->dirY * data->ray->mSpeed;
    }
	raycaster(data);
}

int create_colour(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	init_mlx(t_data *data)
{
	data->ray = ft_calloc(1, sizeof(t_ray));
	data->ray->mlx = mlx_init(WIDTH, HEIGHT, "test", false);
	data->ray->img = mlx_new_image(data->ray->mlx, WIDTH, HEIGHT);
	data->ray->posX = 17;
	data->ray->posY = 12;
	data->ray->dirX = 1;
	data->ray->dirY = 0;
	data->ray->planeX = 0;
	data->ray->planeY = 0.66;
	data->ray->mSpeed = 0.1;
	data->ray->rSpeed = 0.07;
	data->ray->ceiling = create_colour(data->map_data->ceiling_color[0], data->map_data->ceiling_color[1], data->map_data->ceiling_color[2], 255);
	data->ray->floor = create_colour(data->map_data->floor_color[0], data->map_data->floor_color[1], data->map_data->floor_color[2], 255);
	raycaster(data);
	mlx_key_hook(data->ray->mlx, &hook, (void *) data);
	mlx_loop(data->ray->mlx);
	mlx_terminate(data->ray->mlx);
}