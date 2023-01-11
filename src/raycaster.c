
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
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
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

int create_colour(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

/* void	draw_line(t_data *data, xpm_t *texture, int i)
{
	double	dist;
	double	pos;
	int		texY;
	int		j;

	dist = 1.0 * texture->texture.height / data->ray->line;
	pos = (data->ray->start - HEIGHT / 2 + data->ray->line) * dist;
	j = data->ray->start;
	while (j < data->ray->end)
	{
		texY = (int) pos & (texture->texture.height);
		pos += dist;
		j++;
	}
} */

void	fill_texture(int **arr, xpm_t *tex)
{
	int	i;
	int	j;

	printf("ok %u\n", tex->texture.height);
	for (int k = 0;k < 1000; k++)
		printf("%x", tex->texture.pixels[k]);
	arr = ft_calloc(sizeof(int *), tex->texture.height);
	i = -1;
	while (++i < (int) tex->texture.height)
	{
			printf("ok2 %u\n", tex->texture.width);
		arr[i] = ft_calloc(sizeof(int), tex->texture.width);
		j = -1;
		while (++j < (int) tex->texture.width)
		{
			printf("ok3\n");
			arr[i][j] = create_colour(tex->texture.pixels[(tex->texture.width * 4 * i - 4) + (j * 4 - 4) + 0], tex->texture.pixels[(tex->texture.width * 4 * i - 4) + (j * 4 - 4) + 1],
				tex->texture.pixels[(tex->texture.width * 4 * i - 4) + (j * 4 - 4) + 2], tex->texture.pixels[(tex->texture.width * 4 * i - 4) + (j * 4 - 4) + 3]);
		}
	}
	
}

void	create_texture(t_data *data)
{
	data->ray->tex = ft_calloc(1, sizeof(t_tex *));
	data->ray->tex->east_tex = mlx_load_xpm42("./asset/Blue_partyhat_1.xpm42");
	if (!data->ray->tex->east_tex)
		exit(1);
	data->ray->tex->west_tex = mlx_load_xpm42("./asset/Green_partyhat_1.xpm42");
	data->ray->tex->north_tex = mlx_load_xpm42("./asset/Purple_partyhat_1.xpm42");
	data->ray->tex->south_tex = mlx_load_xpm42("./asset/White_partyhat.xpm42");
	fill_texture(data->ray->tex->east, data->ray->tex->east_tex);
	fill_texture(data->ray->tex->west, data->ray->tex->west_tex);
	fill_texture(data->ray->tex->north, data->ray->tex->north_tex);
	fill_texture(data->ray->tex->south, data->ray->tex->south_tex);
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
		//find_hit(data, lol);
		//draw_line(data, lol, i);
		/* while (data->ray->start < data->ray->end)
		{
			if (data->ray->side == 0)
				mlx_put_pixel(data->ray->img, i, data->ray->start++, 0xa103fcFF); // east
			else if (data->ray->side == 1)
				mlx_put_pixel(data->ray->img, i, data->ray->start++, 0x4287f5FF); // west
			else if (data->ray->side == 2)
				mlx_put_pixel(data->ray->img, i, data->ray->start++, 0xf0224eFF); // south
			else
				mlx_put_pixel(data->ray->img, i, data->ray->start++, 0x0000FFFF); // north
		} */
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

void	init_mlx(t_data *data)
{
	data->ray = ft_calloc(1, sizeof(t_ray));
	data->ray->mlx = mlx_init(WIDTH, HEIGHT, "test", true);
	data->ray->img = mlx_new_image(data->ray->mlx, WIDTH, HEIGHT);
	data->ray->posX = 17;
	data->ray->posY = 12;
	data->ray->dirX = 1; //pour 1 planeY 0.66 pour -1 planeY -0.66
	data->ray->dirY = 0;// pour 1 planeX -0.66 pour 1 planeX 0.66
	data->ray->planeX = 0;
	data->ray->planeY = 0.66;
	data->ray->mSpeed = 0.1;
	data->ray->rays = false;
	data->ray->ceiling = create_colour(data->map_data->ceiling_color[0], data->map_data->ceiling_color[1], data->map_data->ceiling_color[2], 255);
	data->ray->floor = create_colour(data->map_data->floor_color[0], data->map_data->floor_color[1], data->map_data->floor_color[2], 255);
	create_texture(data);
	for(unsigned int i = 0; i < data->ray->tex->east_tex->texture.height; i++)
		for (unsigned int j = 0; j < data->ray->tex->east_tex->texture.width; j++)
			printf("%x\n", data->ray->tex->east[i][j]);
	raycaster(data);
	mlx_image_to_window(data->ray->mlx, data->ray->img, 0, 0);
	mlx_key_hook(data->ray->mlx, &hook, (void *) data);
	mlx_loop(data->ray->mlx);
	mlx_delete_image(data->ray->mlx, data->ray->img);
	mlx_terminate(data->ray->mlx);
}