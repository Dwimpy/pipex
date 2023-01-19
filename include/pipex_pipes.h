/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:37:57 by arobu             #+#    #+#             */
/*   Updated: 2023/01/19 03:15:59 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_PIPES_H
# define PIPEX_PIPES_H
# define READ_END 0
# define WRITE_END 1

# include <stdio.h>
# include <unistd.h>
# include "pipex.h"

typedef struct s_pipex_pipes
{
	int			fd[2];
}				t_pipex_pipes;

typedef struct s_pipex_pipeline
{
	pid_t			pid;
	int				child;
	t_pipex_pipes	*pipe;
	int				file_fd_input;
	int				file_fd_output;
}				t_pipex_pipeline;

t_pipex_pipes	*create_pipes(int pipes_number);

int				ft_redirect_pipes(t_pipex_pipeline **pipeline, \
									t_pipex_data *data, \
									t_pipex_errors *err_handler, \
									int command_number);
int				ft_redirect_io(int input, int output);
void			close_pipe_fds_parent(t_pipex_pipeline *pipeline, \
										int pipe_number);
void			close_pipe_fds(t_pipex_pipeline **pipeline, int pipe_number);
#endif