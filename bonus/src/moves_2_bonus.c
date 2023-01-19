#include "cub3d_bonus.h"

void	forward(t_data *data) // faut fix que quand tes tout droits tu clip un peu a travers le mur
{
	double	i;

	i = 0;
	while (data->ray->mSpeed - i >= 0.15)
	{
		if(data->map[(int)(data->ray->posY)][(int)(data->ray->posX + data->ray->dirX * (data->ray->mSpeed - i))] == '0')
		{
			data->ray->posX += data->ray->dirX * data->ray->mSpeed - i;
			break ;
		}
		i += 0.05;
	}
	i = 0;
	while (data->ray->mSpeed - i >= 0.15)
	{
		if(data->map[(int)(data->ray->posY + data->ray->dirY * (data->ray->mSpeed - i))][(int)(data->ray->posX)] == '0')
		{
			
			data->ray->posY += data->ray->dirY * data->ray->mSpeed - i;
			break ;
		}
		i += 0.05;
	}
}

void	backward(t_data *data)
{
	double	i;

	i = 0;
	while (data->ray->mSpeed - i >= 0.15)
	{
		if(data->map[(int)(data->ray->posY)][(int)(data->ray->posX - data->ray->dirX * (data->ray->mSpeed - i))] == '0')
		{
			data->ray->posX -= data->ray->dirX * data->ray->mSpeed - i;
			break ;
		}
		i += 0.05;
	}
	i = 0;
	while (data->ray->mSpeed - i >= 0.15)
	{
		if(data->map[(int)(data->ray->posY - data->ray->dirY * (data->ray->mSpeed - i))][(int)(data->ray->posX)] == '0')
		{
			data->ray->posY -= data->ray->dirY * data->ray->mSpeed - i;
			break ;
		}
		i += 0.05;
	}
}

void	right(t_data *data)
{
	if(data->map[(int)(data->ray->posY)][(int)(data->ray->posX + data->ray->planeX * data->ray->sSpeed)] == '0') 
		data->ray->posX += data->ray->planeX * data->ray->sSpeed;
	if(data->map[(int)(data->ray->posY + data->ray->planeY * data->ray->sSpeed)][(int)(data->ray->posX)] == '0')
		data->ray->posY += data->ray->planeY * data->ray->sSpeed;
}

void	left(t_data *data)
{
	if(data->map[(int)(data->ray->posY)][(int)(data->ray->posX - data->ray->planeX * data->ray->sSpeed)] == '0') 
		data->ray->posX -= data->ray->planeX * data->ray->sSpeed;
	if(data->map[(int)(data->ray->posY - data->ray->planeY * data->ray->sSpeed)][(int)(data->ray->posX)] == '0')
		data->ray->posY -= data->ray->planeY * data->ray->sSpeed;
}
