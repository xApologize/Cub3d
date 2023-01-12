
#include "cub3d.h"

// int worldMap[data->map_height][data->map_width]=
// {
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// };
// {
//   {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
//   {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
//   {4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
//   {4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
//   {4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
//   {4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
//   {4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
//   {4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
//   {4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
//   {4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
//   {4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
//   {4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
//   {6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
//   {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
//   {6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
//   {4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
//   {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
//   {4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
//   {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
//   {4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
//   {4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
//   {4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
//   {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
//   {4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
// };

void	draw_player(t_data *data)
{
	int hold;
	int hold2;
	double x;
	double y;

	y = (double) (data->ray->posY) * 10 - 4.5;
	x = (double) (data->ray->posX) * 10 - 4.5;
	hold = y + 9;
	while (y < hold)
	{
		hold2 = x + 9;
		while (x < hold2)
			mlx_put_pixel(data->ray->img, x++, y, 0x8a15bdFF);
		y++;
		x -= 9;
	}
	y = (double) (data->ray->posY) * 10;
	x = (double) (data->ray->posX) * 10;
	hold = data->ray->rayLenght * 10;
	while (hold-- >= 0 && y > 0 && x > 0 && x < data->map_width * 10 && y < data->map_height * 10)
	{
		mlx_put_pixel(data->ray->img, x, y, 0xFF0000FF );
		y += data->ray->dirY;
		x += data->ray->dirX;
	}
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
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;
	int x;
	int	y;

	i = -1;
	y = 0;
	while (++i < data->map_width * 10)
	{
		j = -1;
		while (++j < data->map_height * 10)
			mlx_put_pixel(data->ray->img, i, j, 0x4d4d4dFF);
	}
	i = -1;
	while (++i < data->map_height)
	{
		j = -1;
		x = 0;
		while (++j < data->map_width)
		{
			if (data->map[i][j] != '0')
				draw_wall(data, x, y);
			else
				draw_space(data, x, y);
			x+= 10;
		}
		y += 10;
	}
	draw_player(data);
}

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

void	dda(t_data *data)
{
	while (1)
	{
		if (data->ray->distX < data->ray->distY)
		{
			data->ray->distX += data->ray->deltaX;
			data->ray->mapX += data->ray->stepX;
			if (data->ray->rayX > 0)
				data->ray->side = 0;
			else
				data->ray->side = 1;
		}
		else
		{
			data->ray->distY += data->ray->deltaY;
			data->ray->mapY += data->ray->stepY;
			if (data->ray->rayY > 0)
				data->ray->side = 2;
			else
				data->ray->side = 3;
			
		}
		if (data->map[data->ray->mapY][data->ray->mapX] != '0')
			break ;
	}
	if (data->ray->side < 2)
		data->ray->wallDist = data->ray->distX - data->ray->deltaX;
	else
		data->ray->wallDist = data->ray->distY - data->ray->deltaY;
}

void	calc_line(t_data *data)
{
	data->ray->line = HEIGHT / data->ray->wallDist;
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

void	map(t_data *data)
{
	double	i;
	double	y;
	double	x;
	double	hold;

	i = -1;
	draw_map(data);
	while (i < WIDTH)
	{
		init_var(data, i);
		init_dist(data);
		dda(data);
		y = (double) (data->ray->posY) * 10; //+ 4.5;
		x = (double) (data->ray->posX) * 10; //+ 4.5;
		hold = data->ray->wallDist * 10; //+ 4.5;
		while (hold-- >= 0 && y > 0 && x > 0 && x < data->map_width * 10 && y < data->map_height * 10)
		{
			mlx_put_pixel(data->ray->img, x, y, 0xFF0000FF);
			y += (double) data->ray->rayY;
			x += (double) data->ray->rayX;
		}
		i += 0.5;
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
		if (i == WIDTH / 2)
			data->ray->rayLenght = data->ray->wallDist;
		while (data->ray->start < data->ray->end)
		{
			if (data->ray->side == 0)
				mlx_put_pixel(data->ray->img, i, data->ray->start++, 0xa103fcFF); // east
			else if (data->ray->side == 1)
				mlx_put_pixel(data->ray->img, i, data->ray->start++, 0x4287f5FF); // west
			else if (data->ray->side == 2)
				mlx_put_pixel(data->ray->img, i, data->ray->start++, 0xf0224eFF); // south
			else
				mlx_put_pixel(data->ray->img, i, data->ray->start++, 0x0000FFFF); // north
		}
	}
	if (data->ray->rays == true)
		map(data);
	else 
		draw_map(data);
}

void	right(t_data *data)
{
      	double oldDirX = data->ray->dirX;
    	data->ray->dirX =data->ray->dirX * cos(RSPEED) - data->ray->dirY * sin(RSPEED);
     	data->ray->dirY = oldDirX * sin(RSPEED) + data->ray->dirY * cos(RSPEED);
      	double oldPlaneX = data->ray->planeX;
      	data->ray->planeX = data->ray->planeX * cos(RSPEED) - data->ray->planeY * sin(RSPEED);
      	data->ray->planeY = oldPlaneX * sin(RSPEED) + data->ray->planeY * cos(RSPEED);
}

void	left(t_data *data)
{
      	double oldDirX = data->ray->dirX;
    	data->ray->dirX = data->ray->dirX * cos(-RSPEED) - data->ray->dirY * sin(-RSPEED);
     	data->ray->dirY = oldDirX * sin(-RSPEED) + data->ray->dirY * cos(-RSPEED);
      	double oldPlaneX = data->ray->planeX;
      	data->ray->planeX = data->ray->planeX * cos(-RSPEED) - data->ray->planeY * sin(-RSPEED);
      	data->ray->planeY = oldPlaneX * sin(-RSPEED) + data->ray->planeY * cos(-RSPEED);
}

void	forward(t_data *data)
{
	if(data->map[(int)(data->ray->posY)][(int)(data->ray->posX + data->ray->dirX * data->ray->mSpeed)] == '0')
		data->ray->posX += data->ray->dirX * data->ray->mSpeed;
    if(data->map[(int)(data->ray->posY + data->ray->dirY * data->ray->mSpeed)][(int)(data->ray->posX)] == '0')
		data->ray->posY += data->ray->dirY * data->ray->mSpeed;
}

void	backward(t_data *data)
{
	if(data->map[(int)(data->ray->posY)][(int)(data->ray->posX - data->ray->dirX * data->ray->mSpeed)] == '0')
		data->ray->posX -= data->ray->dirX * data->ray->mSpeed;
	if(data->map[(int)(data->ray->posY - data->ray->dirY * data->ray->mSpeed)][(int)(data->ray->posX)] == '0')
		data->ray->posY -= data->ray->dirY * data->ray->mSpeed;
}

void	hook(mlx_key_data_t keydata, void *temp)
{
	t_data *data;

	data = temp;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(data->ray->mlx);
	if (keydata.key == MLX_KEY_RIGHT)
		right(data);
	if (keydata.key == MLX_KEY_LEFT)
		left(data);
	if (keydata.key == MLX_KEY_W)
		forward(data);
    if (keydata.key == MLX_KEY_S)
		backward(data);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
	{
		if (data->ray->mSpeed < 0.95)
			data->ray->mSpeed += 0.05;
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
		if (data->ray->mSpeed > 0.1)
			data->ray->mSpeed -= 0.05;
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_RELEASE)
	{
		if (data->ray->rays == true)
			data->ray->rays = false;
		else
			data->ray->rays = true;
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
	data->ray->mlx = mlx_init(WIDTH, HEIGHT, "test", true);
	data->ray->img = mlx_new_image(data->ray->mlx, WIDTH, HEIGHT);
	data->ray->posX = data->start_pos[1] + 0.5;
	data->ray->posY = data->start_pos[0] + 0.5;
	data->ray->dirX = 1; //pour 1 planeY 0.66 pour -1 planeY -0.66
	data->ray->dirY = 0;// pour 1 planeX -0.66 pour 1 planeX 0.66
	data->ray->planeX = 0;
	data->ray->planeY = 0.66;
	data->ray->mSpeed = 0.1;
	data->ray->rays = false;
	data->ray->ceiling = create_colour(data->map_data->ceiling_color[0], data->map_data->ceiling_color[1], data->map_data->ceiling_color[2], 255);
	data->ray->floor = create_colour(data->map_data->floor_color[0], data->map_data->floor_color[1], data->map_data->floor_color[2], 255);
	raycaster(data);
	mlx_image_to_window(data->ray->mlx, data->ray->img, 0, 0);
	mlx_key_hook(data->ray->mlx, &hook, (void *) data);
	mlx_loop(data->ray->mlx);
	mlx_delete_image(data->ray->mlx, data->ray->img);
	mlx_terminate(data->ray->mlx);
}
