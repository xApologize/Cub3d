#include "cub3d.h"

void	error_and_free(t_data *data, char *err_msg)
{
	ft_putstr_fd(err_msg, 2);
	free_full_data(data);
	exit(EXIT_FAILURE);
}
