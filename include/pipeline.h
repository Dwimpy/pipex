/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:15:02 by arobu             #+#    #+#             */
/*   Updated: 2022/12/05 14:49:59 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPELINE_H
# define PIPELINE_H
# define READ_PIPE 0
# define WRITE_PIPE 1

# include <unistd.h>
# include <stdio.h>
# include "../include/environment.h"
# include "file.h"

typedef struct s_pipe
{
	int		fd[2];
}				t_pipe;

typedef struct s_pipeline
{
	pid_t	pid;
	t_pipe	*pipe;
	t_file	input;
	t_file	output;
	int		child;
	int		file_fd_input;
	int		file_fd_output;
}				t_pipeline;

void	pipeline_ctor(t_pipeline *me, t_cmd *cmd, t_environment *env);
void	add_output_file(t_pipeline *const me, char *input, char *output);
void	create_pipes(t_pipeline **pipes, int command_count);
void	redirect_io(int input, int output);
void	close_pipe_fds(t_pipeline ***pipeline, int command_count);

#endif