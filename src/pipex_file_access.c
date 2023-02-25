/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_file_access.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:07:47 by arobu             #+#    #+#             */
/*   Updated: 2023/02/25 14:31:09 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_file.h"
#include "pipex_pipes.h"
#include "pipex.h"

int	check_input_file_access(t_pipex_data *data, \
							t_pipex_errors *err_handler)
{
	int	fd;
	int	is_success;

	is_success = 0;
	fd = open(data->input_file->filename, O_RDONLY);
	if (fd < 0)
	{
		is_success = -1;
		print_errno_message(err_handler, "input: ");
	}
	else
	{
		if (access(data->input_file->filename, R_OK) == -1)
		{
			print_errno_message(err_handler, "input: ");
			is_success = -1;
		}
		close(fd);
	}
	return (is_success);
}

int	check_output_file_access(t_pipex_data *data, t_pipex_errors *err_handler)
{
	int	is_success;
	int	fd;

	is_success = 0;
	if (data->here_doc == 1)
		fd = open(data->output_file->filename, \
				O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(data->output_file->filename, \
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		print_errno_message(err_handler, "output: ");
		is_success = -1;
	}
	else
	{
		if (access(data->output_file->filename, W_OK) == -1)
		{
			print_errno_message(err_handler, "access: ");
			is_success = -1;
		}
		close(fd);
	}
	return (is_success);
}

int	check_exe_file_exists(char	*filepath)
{
	if (access(filepath, F_OK) == 0)
		return (0);
	return (-1);
}

int	check_exe_file_access(char *filepath)
{
	if (access(filepath, X_OK) == 0)
		return (0);
	return (-1);
}
