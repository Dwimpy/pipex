/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:40:37 by arobu             #+#    #+#             */
/*   Updated: 2023/01/16 22:00:01 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_pipes.h"
#include "../include/pipex.h"

int	ft_redirect_io(int input, int output)
{
	if (dup2(input, STDIN_FILENO) == -1)
		return (-1);
	if (dup2(output, STDOUT_FILENO) == -1)
		return (-1);
	return (0);
}

int	ft_redirect_pipes(t_pipex_pipes **pipes, t_pipex_data *data, \
						int child_number)
{
	int	is_success;
	int	fd;

	is_success = 0;
	if (child_number == 0)
	{
		fd = open(data->input_file->filename, O_RDONLY);
		is_success = ft_redirect_io(fd, (*pipes)[child_number].fd[WRITE_END]);
	}
	else if (child_number == data->command_number - 1)
	{
		fd = open(data->output_file->filename, O_WRONLY);
		is_success = ft_redirect_io((*pipes)[child_number].fd[READ_END], fd);
	}
	else
	{
		is_success = ft_redirect_io((*pipes)[child_number - 1].fd[READ_END], \
									(*pipes)[child_number].fd[WRITE_END]);
	}
	return (is_success);
}

t_pipex_pipes	*create_pipes(int pipes_number)
{
	t_pipex_pipes	*pipes;
	int				i;

	i = 0;
	pipes = (t_pipex_pipes *)malloc(sizeof(t_pipex_pipes));
	if (!pipes)
		return (NULL);
	return (pipes);
}

void	pipe_the_pipes(t_pipex_pipes **pipes, int pipes_number)
{
	int	i;

	i = 0;
	while (i < pipes_number)
	{
		pipe((*pipes)->fd);
		i++;
	}
}

void	close_pipe_fds(t_pipex_pipes *pipes, int pipes_number)
{
	int	i;

	i = -1;
	while (++i < pipes_number)
	{
		close(pipes[i].fd[READ_END]);
		close(pipes[i].fd[WRITE_END]);
	}
}