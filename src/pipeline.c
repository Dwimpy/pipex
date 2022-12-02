/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:48:40 by arobu             #+#    #+#             */
/*   Updated: 2022/12/02 18:57:58 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipeline.h"
#include <stdio.h>

void	add_files_to_pipeline(t_pipeline *const me, char *input, char *output);
void	create_pipes(t_pipe **pipe, int command_count);
void	redirect_io(int input, int output);
void	pipeline_redirection(t_pipeline ***pipeline, int command_count);
void	run_cmds(t_pipeline **pipeline, t_cmd *cmd, int command_count);

void	pipeline_ctor(t_pipeline *me, t_cmd *cmd, int argc, char **argv)
{
	int		command_count;
	int		i;
	
	command_count = argc - 3;
	me->child = -1;
	i = -1;
	me->input.file_name = ft_strdup(argv[1]);
	me->output.file_name = ft_strdup(argv[argc - 1]);
	me->file_fd_input = open_input_file(me->input);
	me->file_fd_output = open_output_file(me->output);

	create_pipes(&me->pipe, command_count);
	while(me->child < command_count)
	{
		run_cmds(&me, cmd, command_count);
		i++;
	}

}

void	redirect_io(int input, int output)
{
	if (dup2(input, STDIN_FILENO) == -1)
	{
		ft_printf("Input: Program exited with error code %d: %s", errno, strerror(errno));
		exit(-1);
	}
	
	if (dup2(output, STDOUT_FILENO) == -1)
	{
		ft_printf("Output: Program exited with error code %d: %s", errno, strerror(errno));
		exit(-1);
	}
}

void	pipeline_redirection(t_pipeline ***pipeline, int command_count)
{
	if ((**pipeline)->child == 0)
		redirect_io((**pipeline)->file_fd_input, (**pipeline)->pipe[(**pipeline)->child].fd[WRITE_PIPE]);
	 else if((**pipeline) -> child == command_count - 1)
	 	redirect_io((**pipeline)->pipe[(**pipeline)->child - 1].fd[READ_PIPE], (**pipeline)->file_fd_output);
	 else
	 	redirect_io((**pipeline)->pipe[(**pipeline)->child - 1].fd[READ_PIPE], (**pipeline)->pipe[(**pipeline)->child].fd[WRITE_PIPE]);
}

void	create_pipes(t_pipe **pipes, int command_count)
{
	int i;
	
	i = -1;
	*pipes = (t_pipe *)malloc(sizeof(t_pipe) * command_count);
	if (!(*pipes))
	{
		(*pipes) = NULL;
		perror("Pipe malloc allocaiton failed");
		exit(1);
		return ;
	}

	while (++i < command_count)
	{
		pipe((*pipes)[i].fd);
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

void	run_cmds(t_pipeline **pipeline, t_cmd *cmd, int command_count)
{
	(**pipeline).child++;
	(*pipeline)->pipe[(*pipeline)->child].pid = fork();
	if ((*pipeline)->pipe[(*pipeline)->child].pid == 0 && (**pipeline).child < command_count)
	{
		pipeline_redirection(&pipeline, command_count);
		close_pipe_fds(&pipeline, command_count);
		execve(cmd[(**pipeline).child].exec_options[0], cmd[(**pipeline).child].exec_options, NULL);
	}
}