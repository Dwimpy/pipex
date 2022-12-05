/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:33:23 by arobu             #+#    #+#             */
/*   Updated: 2022/12/05 15:36:31 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipeline.h"

void	redirect_io(int input, int output)
{
	if (dup2(input, STDIN_FILENO) == -1)
	{
		exit(errno);
	}
	if (dup2(output, STDOUT_FILENO) == -1)
	{
		exit(errno);
	}
}

void	pipeline_redirection(t_pipeline ***pipeline, int command_count)
{
	if ((**pipeline)->child == 0)
		redirect_io((**pipeline)->file_fd_input, \
		(**pipeline)->pipe[(**pipeline)->child].fd[WRITE_PIPE]);
	else if ((**pipeline)->child == command_count - 1)
		redirect_io((**pipeline)->pipe[(**pipeline)->child - 1].fd[READ_PIPE], \
					(**pipeline)->file_fd_output);
	else
		redirect_io((**pipeline)->pipe[(**pipeline)->child - 1].fd[READ_PIPE], \
					(**pipeline)->pipe[(**pipeline)->child].fd[WRITE_PIPE]);
}

void	create_pipes(t_pipeline **pipes, int command_count)
{
	int	i;

	i = -1;
	(*pipes)->pipe = (t_pipe *)malloc(sizeof(t_pipe) * (command_count));
	if (!(*pipes)->pipe)
	{
		(*pipes)->pipe = NULL;
		perror("Pipe memory allocation");
		exit(errno);
		return ;
	}
	while (++i < command_count)
	{
		pipe((*pipes)->pipe[i].fd);
	}
}

void	close_pipe_fds(t_pipeline ***pipeline, int command_count)
{
	int	i;

	i = -1;
	close((**pipeline)->file_fd_input);
	close((**pipeline)->file_fd_output);
	while (++i < command_count)
	{
		close((**pipeline)->pipe[i].fd[READ_PIPE]);
		close((**pipeline)->pipe[i].fd[WRITE_PIPE]);
	}
}
