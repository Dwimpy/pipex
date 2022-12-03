/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:15:02 by arobu             #+#    #+#             */
/*   Updated: 2022/12/03 16:46:41 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPELINE_H
# define PIPELINE_H
# define READ_PIPE 0
# define WRITE_PIPE 1

# include <unistd.h>
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

void	pipeline_ctor(t_pipeline *me, t_cmd *cmd, int argc, char **argv);
void	add_output_file(t_pipeline *const me, char *input, char *output);
void	create_pipes(t_pipeline **pipes, int command_count);

#endif