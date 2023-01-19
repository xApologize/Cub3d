
#include "cub3d.h"

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
	pos = ((double) data->ray->start - (double) HEIGHT / 2 + (double) data->ray->line / 2) * dist;
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