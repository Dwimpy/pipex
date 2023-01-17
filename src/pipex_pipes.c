/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:40:37 by arobu             #+#    #+#             */
/*   Updated: 2023/01/17 02:31:15 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_pipes.h"
#include "../include/pipex.h"
#include "../include/get_next_line.h"

int	ft_redirect_io(int input, int output)
{
	if (dup2(input, STDIN_FILENO) == -1)
		return (-1);
	if (dup2(output, STDOUT_FILENO) == -1)
		return (-1);
	return (0);
}

int	ft_redirect_pipes(t_pipex_pipeline **pipeline, int command_number)
{
	int	is_success;
	int	fd;
	int	child;
	t_pipex_pipes *pipes;

	child = (**pipeline).child;
	pipes = (*pipeline)->pipe;
	is_success = 0;
	if (child == 0)
		is_success = ft_redirect_io((**pipeline).file_fd_input, pipes[child].fd[WRITE_END]);
	else if (child == command_number - 1)
		is_success = ft_redirect_io(pipes[child - 1].fd[READ_END], (**pipeline).file_fd_output);
	else
		is_success = ft_redirect_io(pipes[child - 1].fd[READ_END], pipes[child].fd[WRITE_END]);
	return (is_success);
}

t_pipex_pipes	*create_pipes(int pipes_number)
{
	t_pipex_pipes	*pipes;
	int				i;

	i = 0;
	pipes = (t_pipex_pipes *)malloc(sizeof(t_pipex_pipes) * pipes_number);
	if (!pipes)
		return (NULL);
	while (i < pipes_number)
	{
		pipe((pipes)[i].fd);
		i++;
	}
	return (pipes);
}


void	close_pipe_fds(t_pipex_pipeline **pipeline, int pipe_number)
{
	int	i;

	i = -1;
	while (++i < pipe_number)
	{
		close((*pipeline)->pipe[i].fd[READ_END]);
		close((*pipeline)->pipe[i].fd[WRITE_END]);
	}
}