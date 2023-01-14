/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_file_access.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:07:47 by arobu             #+#    #+#             */
/*   Updated: 2023/01/14 18:18:45 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_file.h"
#include "../include/pipex.h"

void	check_input_file_access(t_pipex_data *data, char *filename)
{
	int	fd;

	if (access(filename, F_OK) == -1)
	{
		ft_putstr_fd(ERR_ENOENT, 2);
		ft_free_allocated_memory(data);
		exit(EXIT_FAILURE);
	}
	else if (access(filename, R_OK) == -1)
	{
		ft_putstr_fd(ERR_EACCESS, 2);
		ft_free_allocated_memory(data);
		exit(EXIT_FAILURE);
	}
}

void	check_output_file_access(t_pipex_data *data, char *filename)
{
	int	fd;

	if (access(filename, F_OK) == 0)
	{
		if (access(filename, W_OK) == -1)
		{
			ft_putstr_fd(ERR_EACCESS, 2);
			ft_free_allocated_memory(data);
			exit(EXIT_FAILURE);
		}
	}
	else if (access(filename, F_OK) == -1)
	{
		fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (fd < 0)
		{
			ft_putstr_fd(ERR_EBADF, 2);
			ft_free_allocated_memory(data);
			exit(EXIT_FAILURE);
		}
		close(fd);
	}
}

int	check_exe_file_access(char *filepath)
{
	if (access(filepath, X_OK) == -1)
		return (-1);
	return (0);
}
