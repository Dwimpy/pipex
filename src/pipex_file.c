/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:24:49 by arobu             #+#    #+#             */
/*   Updated: 2023/01/07 22:04:39 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../include/pipex_file.h"
#include "../include/pipex.h"

static void	check_input_file_access(t_pipex_data *data, char *filename);
static void	check_output_file_access(t_pipex_data *data, char *filename);

t_pipex_file	*new_pipex_input_file(t_pipex_data *data, char *filename)
{
	t_pipex_file	*file;

	check_input_file_access(data, filename);
	file = (t_pipex_file *)malloc(sizeof(t_pipex_file));
	file->filename = ft_strdup(filename);
	file->filepath = NULL;
	file->file_type = IO_FILE;
	return (file);
}

t_pipex_file	*new_pipex_output_file(t_pipex_data *data, char *filename)
{
	t_pipex_file	*file;

	check_output_file_access(data, filename);
	file = (t_pipex_file *)malloc(sizeof(t_pipex_file));
	file->filename = ft_strdup(filename);
	file->filepath = NULL;
	file->file_type = IO_FILE;
	return (file);
}

t_pipex_file	*new_pipex_exe_file(char *filename, char *filepath)
{
	t_pipex_file	*file;

	file = (t_pipex_file *)malloc(sizeof(t_pipex_file));
	file->filename = ft_strdup(filename);
	file->filepath = filepath;
	file->file_type = EXE_FILE;
	return (file);
}

static void	check_input_file_access(t_pipex_data *data, char *filename)
{
	if (access(filename, F_OK) == -1)
	{
		ft_putstr_fd(ERR_ENOENT, 2);
		ft_free_allocated_memory(data);
		exit(ENOENT);
	}
	else if (access(filename, R_OK) == -1)
	{
		ft_putstr_fd(ERR_EACCESS, 2);
		ft_free_allocated_memory(data);
		exit(EACCES);
	}
}

static void	check_output_file_access(t_pipex_data *data, char *filename)
{
	int	fd;

	fd = 0;
	if (access(filename, F_OK) == 0)
	{
		if (access(filename, W_OK) == -1)
		{
			ft_putstr_fd(ERR_EACCESS, 2);
			ft_free_allocated_memory(data);
			exit(EACCES);
		}
	}
	else if (access(filename, F_OK) == -1)
	{
		fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (fd < 0)
		{
			ft_putstr_fd(ERR_EBADF, 2);
			ft_free_allocated_memory(data);
			exit(EBADF);
		}
		close(fd);
	}
}
