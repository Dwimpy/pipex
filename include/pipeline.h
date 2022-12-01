/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:15:02 by arobu             #+#    #+#             */
/*   Updated: 2022/12/01 03:59:45 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPELINE_H
# define PIPELINE_H

# include <unistd.h>
# include "../include/environment.h"
# include "file.h"

typedef struct s_pipe
{
	pid_t	pid;
	int		fd[2];
}				t_pipe;

typedef struct s_pipeline
{
	t_pipe	*pipe;
	t_file	input;
	t_file	output;
	int		file_fd;
}				t_pipeline;

void	pipeline_ctor(t_pipeline *const me, t_cmd *cmd, int argc, char **argv);
void	add_output_file(t_pipeline *const me, char *input, char *output);
void	create_pipes(t_pipe **pipe, int command_count);

#endif