#include "cub3d.h"
#include <stdlib.h>

void	error_and_exit(char *err_msg)
{
	ft_putstr_fd(ERROR, 2);
	ft_putstr_fd(err_msg, 2);
	exit(EXIT_FAILURE);
}

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

void	error_code_arg(t_data *data, int err_code)
{
	if (err_code == CODE_PATH_ERR)
		error_and_free(data, ERR_ARG_PATH, 1);
	else if (err_code == CODE_EXT_ERR)
		error_and_free(data, ERR_ASSET_EXT, 1);
	else
		error_and_free(data, ERR_ARG_PATH, 1);
}
