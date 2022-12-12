
#include "../include/cub3d.h"

#define mapWidth 24
#define mapHeight 24

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

void	init_var(t_ray *data, int i)
{
	data->camera = 2 * i / (double) WIDTH - 1;
	data->rayX = data->dirX + data->planeX * data->camera;
	data->rayY = data->dirY + data->planeY * data->camera;
	data->mapX = (int) data->posX;
	data->mapY = (int) data->posY;	
	data->deltaX = fabs(1 / data->rayX);
	data->deltaY = fabs(1 / data->rayY);
}

void	init_dist(t_ray *data)
{
	if (data->rayX < 0)
	{
		data->stepX = -1;
		data->distX = (data->posX - data->mapX) * data->deltaX;
	}
	else
	{
		data->stepX = 1;
		data->distX = (data->posX - data->mapX + 1) * data->deltaX;
	}
	if (data->rayY < 0)
	{
		data->stepY = -1;
		data->distY = (data->posY - data->mapY) * data->deltaY;
	}
	else
	{
		data->stepY = 1;
		data->distY = (data->posY - data->mapY + 1) * data->deltaY;
	}
}

void	dda(t_ray *data)
{
	while (1)
	{
		if (data->distX < data->distY)
		{
			data->distX += data->deltaX;
			data->mapX += data->stepX;
			data->side = 0;
		}
		else
		{
			data->distY += data->deltaY;
			data->mapY += data->stepY;
			data->side = 1;
		}
		if (worldMap[data->mapY][data->mapX] != 0)
			break ;
	}
	if (data->side == 0)
		data->wallDist = data->distX - data->deltaX;
	else
		data->wallDist = data->distY - data->deltaY;
}

void	calc_line(t_ray *data)
{
	data->line = (int) HEIGHT / data->wallDist;
	data->start = -data->line / 2 + HEIGHT / 2;
	if (data->start < 0)
		data->start = 0;
	data->end = data->line / 2 + HEIGHT / 2;
	if (data->end >= HEIGHT)
		data->end = HEIGHT - 1;
}

void	clear_image(t_ray *data)
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
				mlx_put_pixel(data->img, i, j, 0x000000FF);
			else
				mlx_put_pixel(data->img, i, j, 0x00FF00FF);
		}
	}
}

void	draw_map(t_ray *data)
{
	int	i;
	int	j;
	int x;
	int	y;
	int hold;
	int hold2;

	i = -1;
	y = 0;
	clear_image(data);
	while (++i < mapHeight)
	{
		j = -1;
		x = 0;
		while (++j < mapWidth)
		{
			if (j == (int) data->posX && i == (int) data->posY)
			{
				hold = y + 20;
				while (y < hold)
				{
					hold2 = x + 20;
					while (x < hold2)
						mlx_put_pixel(data->img, x++, y, 0xFFFF00FF);
					y++;
					x -= 20;
				}
				y -= 20;
			}
			else if (worldMap[i][j] != 0)
			{
				hold = y + 20;
				while (y < hold)
				{
					hold2 = x + 20;
					while (x < hold2)
						mlx_put_pixel(data->img, x++, y, 0xFFFFFFFF);
					y++;
					x -= 20;
				}
				y -= 20;
			}
			x+= 20;
		}
		y += 20;
	}
}

void	raycaster(t_ray *data)
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
		while (data->start < data->end)
		{
			if (data->side == 0)
				mlx_put_pixel(data->img, i, data->start++, 0xa103fcFF);
			else
				mlx_put_pixel(data->img, i, data->start++, 0x0000FFFF);
		}
	}
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}

void	hook(mlx_key_data_t keydata, void *temp)
{
	t_ray *data;

	data = temp;
	double rotSpeed = 0.07;
	double moveSpeed = 0.5;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_A)
	{
		 //both camera direction and camera plane must be rotated
      	double oldDirX = data->dirX;
    	data->dirX =data->dirX * cos(rotSpeed) - data->dirY * sin(rotSpeed);
     	data->dirY = oldDirX * sin(rotSpeed) + data->dirY * cos(rotSpeed);
      	double oldPlaneX = data->planeX;
      	data->planeX = data->planeX * cos(rotSpeed) - data->planeY * sin(rotSpeed);
      	data->planeY = oldPlaneX * sin(rotSpeed) + data->planeY * cos(rotSpeed);
	}
	if (keydata.key == MLX_KEY_D)
	{
		 //both camera direction and camera plane must be rotated
      	double oldDirX = data->dirX;
    	data->dirX = data->dirX * cos(-rotSpeed) - data->dirY * sin(-rotSpeed);
     	data->dirY = oldDirX * sin(-rotSpeed) + data->dirY * cos(-rotSpeed);
      	double oldPlaneX = data->planeX;
      	data->planeX = data->planeX * cos(-rotSpeed) - data->planeY * sin(-rotSpeed);
      	data->planeY = oldPlaneX * sin(-rotSpeed) + data->planeY * cos(-rotSpeed);
	}
	if(keydata.key == MLX_KEY_W)
    {
      if(worldMap[(int)(data->posX + data->dirX * moveSpeed)][(int)(data->posY)] == false) data->posX += data->dirX * moveSpeed;
      if(worldMap[(int)(data->posX)][(int)(data->posY + data->dirY * moveSpeed)] == false) data->posY += data->dirY * moveSpeed;
    }
    //move backwards if no wall behind you
    if(keydata.key == MLX_KEY_S)
    {
      if(worldMap[(int)(data->posX - data->dirX * moveSpeed)][(int)(data->posY)] == false) data->posX -= data->dirX * moveSpeed;
      if(worldMap[(int)(data->posX)][(int)(data->posY - data->dirY * moveSpeed)] == false) data->posY -= data->dirY * moveSpeed;
    }
	if (keydata.key == MLX_KEY_M)
		draw_map(data);
	else
		raycaster(data);
}

int main()
{
	t_ray *data;

	data = calloc(1, sizeof(t_ray));
	data->posX = 17;
	data->posY = 12;
	data->dirX = -1;
	data->dirY = 1;
	data->planeX = 0;
	data->planeY = 0.6;
	data->mlx = mlx_init(WIDTH, HEIGHT, "test", false);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	raycaster(data);
	mlx_key_hook(data->mlx, &hook, (void *) data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}