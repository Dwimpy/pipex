/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pipex_pipes_handling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:19:36 by arobu             #+#    #+#             */
/*   Updated: 2023/02/25 14:31:09 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_pipes.h"
#include "pipex.h"

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

void	close_pipe_fds_parent(t_pipex_pipeline *pipeline, int pipe_number)
{
	int	i;

	i = -1;
	while (++i < pipe_number)
	{
		close((pipeline)->pipe[i].fd[READ_END]);
		close((pipeline)->pipe[i].fd[WRITE_END]);
	}
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
