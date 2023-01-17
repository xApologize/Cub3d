
#include "cub3d.h"

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
