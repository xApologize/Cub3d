
#include "../include/cub3d.h"

int worldMap[mapHeight][mapWidth]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
/* {
  {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
  {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
  {4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
  {4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
  {4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
  {4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
  {6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
  {6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
  {4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,00,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
}; */

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
	while (hold-- >= 0 && y > 0 && x > 0 && x < mapWidth * 10 && y < mapHeight * 10)
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
	while (++i < mapWidth * 10)
	{
		j = -1;
		while (++j < mapHeight * 10)
			mlx_put_pixel(data->ray->img, i, j, 0x4d4d4dFF);
	}
	i = -1;
	while (++i < mapHeight)
	{
		j = -1;
		x = 0;
		while (++j < mapWidth)
		{
			if (worldMap[i][j] != 0)
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
		if (worldMap[data->ray->mapY][data->ray->mapX] != 0)
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
		y = (double) (data->ray->posY) * 10;
		x = (double) (data->ray->posX) * 10;
		hold = data->ray->wallDist * 10;
		while (hold-- >= 0 && y > 0 && x > 0 && x < mapWidth * 10 && y < mapHeight * 10)
		{
			mlx_put_pixel(data->ray->img, x, y, 0xFF0000FF);
			y += (double) data->ray->rayY;
			x += (double) data->ray->rayX;
		}
		i += 0.5;
	}
}

void	find_hit(t_data *data, xpm_t *texture)
{
	double	hit;

	hit = 0;
	if (data->ray->side == 0 || data->ray->side == 1)
		hit = data->ray->posY + data->ray->wallDist * data->ray->rayY;
	else
		hit = data->ray->posX + data->ray->wallDist * data->ray->rayX;
	hit -= (int) hit;
	data->ray->texX = (int) (hit * (double) texture->texture.width);
	if((data->ray->side == 0 || data->ray->side == 1) && data->ray->rayX > 0) 
		data->ray->texX = texture->texture.width - data->ray->texX - 1;
    if((data->ray->side == 2 || data->ray->side == 3) && data->ray->rayY < 0) 
		data->ray->texX = texture->texture.width - data->ray->texX - 1;
}

void	draw_line(t_data *data, xpm_t *texture, int **arr, int i)
{
	double	dist;
	double	pos;
	int		texY;
	int		j;


	dist = 1.0 * texture->texture.height / data->ray->line;
	pos = (data->ray->start - HEIGHT / 2 + data->ray->line / 2) * dist;
	if (pos < 0)
		pos = 0;
	j = data->ray->start - 1;
	while (++j < data->ray->end)
	{
		texY = (int) pos;
		if (pos > texture->texture.height - 1)
			pos = texture->texture.height - 1;
		pos += dist;
		mlx_put_pixel(data->ray->img, i, j, arr[texY][data->ray->texX]);
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
		if (data->ray->side == 0)
		{
			find_hit(data, data->tex->east_tex);
			draw_line(data, data->tex->east_tex, data->tex->east, i);
		}
		else if (data->ray->side == 1)
		{
			find_hit(data, data->tex->west_tex);
			draw_line(data, data->tex->west_tex, data->tex->west, i);
		}
		else if (data->ray->side == 2)
		{
			find_hit(data, data->tex->south_tex);
			draw_line(data, data->tex->south_tex, data->tex->south, i);
		}
		else
		{
			find_hit(data, data->tex->north_tex);
			draw_line(data, data->tex->north_tex, data->tex->north, i);
		}
		if (i == WIDTH / 2)
			data->ray->rayLenght = data->ray->wallDist;
	}
	if (data->ray->rays == true)
		map(data);
	else 
		draw_map(data);
}

int create_colour(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

int	**fill_texture(xpm_t *tex)
{
	int	**arr;
	int	i;
	int	j;

	arr = ft_calloc(sizeof(int *), tex->texture.height + 1);
	i = 3;
	while (++i < (int) tex->texture.height + 4)
	{
		j = 3;
		arr[i - 4] = ft_calloc(sizeof(int), tex->texture.width);
		while (++j < (int) tex->texture.width + 4)
			arr[i - 4][j - 4] = create_colour(
				tex->texture.pixels[(tex->texture.width * 4 * (i - 4)) + (4 * (j - 4)) + 0], 
				tex->texture.pixels[(tex->texture.width * 4 * (i - 4)) + (4 * (j - 4)) + 1],
				tex->texture.pixels[(tex->texture.width * 4 * (i - 4)) + (4 * (j - 4)) + 2], 
				tex->texture.pixels[(tex->texture.width * 4 * (i - 4)) + (4 * (j - 4)) + 3]);
	}
	return (arr);
}

void	create_texture(t_data *data)
{
	data->tex = ft_calloc(1, sizeof(t_tex));
	if (!data->tex)
		exit(1);
	data->tex->east_tex = mlx_load_xpm42("./asset/Basic_stone.xpm42");
	if(!data->tex->east_tex)
		exit(1);
	data->tex->west_tex = mlx_load_xpm42("./asset/Basic_wood.xpm42");
	if(!data->tex->west_tex)
		exit(1);
	data->tex->north_tex = mlx_load_xpm42("./asset/Dark_stone.xpm42");
	if(!data->tex->north_tex)
		exit(1);
	data->tex->south_tex = mlx_load_xpm42("./asset/Fancy_stone.xpm42");
	if(!data->tex->south_tex)
		exit(1);
	data->tex->east = fill_texture(data->tex->east_tex);
	data->tex->west = fill_texture(data->tex->west_tex);
	data->tex->north = fill_texture(data->tex->north_tex);
	data->tex->south = fill_texture(data->tex->south_tex);
}

void	turn_right(t_data *data)
{
      	double oldDirX = data->ray->dirX;
    	data->ray->dirX =data->ray->dirX * cos(RSPEED) - data->ray->dirY * sin(RSPEED);
     	data->ray->dirY = oldDirX * sin(RSPEED) + data->ray->dirY * cos(RSPEED);
      	double oldPlaneX = data->ray->planeX;
      	data->ray->planeX = data->ray->planeX * cos(RSPEED) - data->ray->planeY * sin(RSPEED);
      	data->ray->planeY = oldPlaneX * sin(RSPEED) + data->ray->planeY * cos(RSPEED);
}

void	turn_left(t_data *data)
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
	if(worldMap[(int)(data->ray->posY)][(int)(data->ray->posX + data->ray->dirX * data->ray->mSpeed)] == false) 
		data->ray->posX += data->ray->dirX * data->ray->mSpeed;
    if(worldMap[(int)(data->ray->posY + data->ray->dirY * data->ray->mSpeed)][(int)(data->ray->posX)] == false)
		data->ray->posY += data->ray->dirY * data->ray->mSpeed;
}

void	backward(t_data *data)
{
	if(worldMap[(int)(data->ray->posY)][(int)(data->ray->posX - data->ray->dirX * data->ray->mSpeed)] == false) 
		data->ray->posX -= data->ray->dirX * data->ray->mSpeed;
	if(worldMap[(int)(data->ray->posY - data->ray->dirY * data->ray->mSpeed)][(int)(data->ray->posX)] == false)
		data->ray->posY -= data->ray->dirY * data->ray->mSpeed;
}

void	left(t_data *data)	// peut cliper quand on est dans un coin 
{
	if(worldMap[(int)(data->ray->posY - data->ray->planeY * data->ray->sSpeed)][(int)(data->ray->posX)] == false)
		data->ray->posY -= data->ray->planeY * data->ray->sSpeed;
	if(worldMap[(int)(data->ray->posY)][(int)(data->ray->posX - data->ray->planeX * data->ray->sSpeed)] == false) 
		data->ray->posX -= data->ray->planeX * data->ray->sSpeed;
}

void	right(t_data *data) // peut cliper quand on est dans un coin 
{
    if(worldMap[(int)(data->ray->posY + data->ray->planeY * data->ray->sSpeed)][(int)(data->ray->posX)] == false)
		data->ray->posY += data->ray->planeY * data->ray->sSpeed;
	if(worldMap[(int)(data->ray->posY)][(int)(data->ray->posX + data->ray->posX * data->ray->sSpeed)] == false) 
		data->ray->posX += data->ray->planeX * data->ray->sSpeed;
}

void	hook(mlx_key_data_t keydata, void *temp)
{
	t_data *data;

	data = temp;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(data->ray->mlx);
		return ;
	}
	if (keydata.key == MLX_KEY_RIGHT)
		turn_right(data);
	if (keydata.key == MLX_KEY_LEFT)
		turn_left(data);
	if (keydata.key == MLX_KEY_W)
		forward(data);
    if (keydata.key == MLX_KEY_S)
		backward(data);
	if (keydata.key == MLX_KEY_A)
		left(data);
	if (keydata.key == MLX_KEY_D)
		right(data);
	if (keydata.key == MLX_KEY_UP)
		if (data->ray->mSpeed < 0.95)
			data->ray->mSpeed += 0.05;
	if (keydata.key == MLX_KEY_DOWN)
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

void	start_var(t_data *data)
{
	data->ray->mlx = mlx_init(WIDTH, HEIGHT, "test", false);
	data->ray->img = mlx_new_image(data->ray->mlx, WIDTH, HEIGHT);
	data->ray->posX = 17;
	data->ray->posY = 12;
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

void	init_mlx(t_data *data)
{
	xpm_t *ags;
	mlx_image_t *img;

	data->ray = ft_calloc(1, sizeof(t_ray));
	start_var(data);
	ags = mlx_load_xpm42("./asset/ags1.xpm42");
	img = mlx_texture_to_image(data->ray->mlx, &ags->texture);
	create_texture(data);
	raycaster(data); 
	mlx_image_to_window(data->ray->mlx, data->ray->img, 0, 0);
	mlx_image_to_window(data->ray->mlx, img, 860, 300);
	mlx_key_hook(data->ray->mlx, &hook, (void *) data);
	mlx_loop(data->ray->mlx);
	mlx_delete_xpm42(ags);
	mlx_delete_xpm42(data->tex->east_tex);
	mlx_delete_xpm42(data->tex->west_tex);
	mlx_delete_xpm42(data->tex->north_tex);
	mlx_delete_xpm42(data->tex->south_tex);
	mlx_delete_image(data->ray->mlx, data->ray->img);
	mlx_delete_image(data->ray->mlx, img);
	mlx_terminate(data->ray->mlx);
}