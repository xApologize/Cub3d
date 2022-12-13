#include "cub3d.h"

void	error_and_free(t_data *data, char *err_msg, int flag)
{
	ft_putstr_fd(ERROR, 2);
	ft_putstr_fd(err_msg, 2);
	if (flag == 0)
		exit(EXIT_FAILURE);
	else
		free_full_data(data);
	exit(EXIT_FAILURE);
}
