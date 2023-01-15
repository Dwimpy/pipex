/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:40:37 by arobu             #+#    #+#             */
/*   Updated: 2023/01/15 17:17:08 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_pipes.h"

int	ft_redirect_io(int input, int output)
{
	if (dup2(input, STDIN_FILENO) == -1)
		return (-1);
	if (dup2(output, STDOUT_FILENO) == -1)
		return (-1);
	return (0);
}

void	close_pipe_fd(t_pipex_pipes *pipes)
{
	close(pipes->pipe_one[READ_END]);
	close(pipes->pipe_one[WRITE_END]);
	close(pipes->pipe_two[READ_END]);
	close(pipes->pipe_two[WRITE_END]);
}