/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:48:40 by arobu             #+#    #+#             */
/*   Updated: 2022/12/03 18:50:16 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipeline.h"
#include <stdio.h>

void	add_files_to_pipeline(t_pipeline *const me, char *input, char *output);
void	create_pipes(t_pipeline **pipes, int command_count);
void	redirect_io(int input, int output);
void	pipeline_redirection(t_pipeline ***pipeline, int command_count);
void	run_cmds(t_pipeline **pipeline, t_cmd *cmd, \
				t_environment env, int command_count);

void	pipeline_ctor(t_pipeline *me, t_cmd *cmd, t_environment *env)
{
	int		command_count;

	command_count = env->argc - 3;
	me->child = -1;
	me->input.file_name = ft_strdup(env->argv[1]);
	me->output.file_name = ft_strdup(env->argv[env->argc - 1]);
	me->file_fd_input = open_input_file(me->input);
	me->file_fd_output = open_output_file(me->output);
	create_pipes(&me, command_count);
	while (me->child <= command_count)
		run_cmds(&me, cmd, *env, command_count);
}

void	redirect_io(int input, int output)
{
	if (dup2(input, STDIN_FILENO) == -1)
	{
		ft_printf("%s", strerror(errno));
		exit(errno);
	}
	if (dup2(output, STDOUT_FILENO) == -1)
	{
		ft_printf("%s", strerror(errno));
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
		perror("Pipe malloc allocaiton failed");
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

void	run_cmds(t_pipeline **pipeline, t_cmd *cmd, \
				t_environment env, int command_count)
{
	 (**pipeline).child++;
	(*pipeline)->pid = fork();
	if ((*pipeline)->pid == 0 && (**pipeline).child < command_count)
	{
		pipeline_redirection(&pipeline, command_count);
		close_pipe_fds(&pipeline, command_count);
		execve(cmd[(**pipeline).child].exec_options[0], \
		cmd[(**pipeline).child].exec_options, env.envp);
	}
}