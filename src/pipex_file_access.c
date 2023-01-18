/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_file_access.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:07:47 by arobu             #+#    #+#             */
/*   Updated: 2023/01/18 13:46:07 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_file.h"
#include "../include/pipex.h"

int	check_input_file_access(t_pipex_data *data, t_pipex_errors *err_handler)
{
	int	fd;

	fd = open(data->input_file->filename, O_RDONLY);
	if (fd < 0)
		print_errno_message(err_handler);
	else
		if (access(data->input_file->filename, R_OK) == -1)
	{
			print_errno_message(err_handler);
			return (-1);
	}
	return (fd);
}

int	check_output_file_access(t_pipex_data *data, t_pipex_errors *err_handler)
{
	int	fd;


	fd = open(data->output_file->filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		print_errno_message(err_handler);
	else
		if(access(data->output_file->filename, W_OK) == -1)
	{
			print_errno_message(err_handler);
			return (-1);
	}
	return (fd);
}

int	check_exe_file_access(char *filepath)
{
	if (access(filepath, X_OK) == -1)
		return (-1);
	return (0);
}
