/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_file_access.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:07:47 by arobu             #+#    #+#             */
/*   Updated: 2023/01/17 20:03:04 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_file.h"
#include "../include/pipex.h"

void	check_input_file_access(t_pipex_data *data, char *filename, \
								t_pipex_errors *err_handler)
{
	int	fd;

	if (access(filename, F_OK) == -1)
		print_errno_message(err_handler);
	else if (access(filename, R_OK) == -1)
		print_errno_message(err_handler);
}

int	check_output_file_access(t_pipex_data *data, char *filename, \
								t_pipex_errors *err_handler)
{
	int	fd;

	if (access(filename, F_OK) == 0)
	{
		if (access(filename, W_OK) == -1)
		{
			print_errno_message(err_handler);
			return (-1);
		}
	}
	else if (access(filename, F_OK) == -1)
	{
		fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (fd < 0)
		{
			print_errno_message(err_handler);
			return (-1);
		}
		close(fd);
		return (-1);
	}
	return (0);
}

int	check_exe_file_access(char *filepath)
{
	if (access(filepath, X_OK) == -1)
		return (-1);
	return (0);
}
