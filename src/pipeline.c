/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:48:40 by arobu             #+#    #+#             */
/*   Updated: 2022/11/27 20:58:25 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipeline.h"
#include <stdio.h>

void	add_files_to_pipeline(t_pipeline *const me, char *input, char *output);
void	create_pipes(t_pipe **pipe, int command_count);
void	run_cmds(t_pipeline *const me, t_cmd *cmd);

void	pipeline_ctor(t_pipeline *const me, t_cmd *cmd, int argc, char **argv)
{
	int	command_count;
	char buffer[1024];
	int n;
	command_count = argc - 3;
	me->input.file_name = ft_strdup(argv[1]);
	me->output.file_name = ft_strdup(argv[argc - 1]);
	me->file_fd = open_input_file(me->input);
	create_pipes(&me->pipe, command_count);
	run_cmds(me, cmd);

	close(me->file_fd);
}

void	pipeline_loop(t_pipeline *const me)
{
	
}

void	create_pipes(t_pipe **pipe, int command_count)
{
	*pipe = malloc(sizeof(t_pipe) * command_count);
	if (!(*pipe))
	{
		(*pipe) = NULL;
		perror("Malloc allocaiton failed");
		exit(1);
		return ;
	}
}

void	run_cmds(t_pipeline *const me, t_cmd *cmd)
{

}