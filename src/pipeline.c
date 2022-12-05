/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:48:40 by arobu             #+#    #+#             */
/*   Updated: 2022/12/05 15:26:29 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipeline.h"

void	add_files_to_pipeline(t_pipeline *const me, char *input, char *output);
void	create_pipes(t_pipeline **pipes, int command_count);
void	redirect_io(int input, int output);
void	pipeline_redirection(t_pipeline ***pipeline, int command_count);
void	run_cmds(t_pipeline **pipeline, t_cmd *cmd, \
				t_environment env, int command_count);

void	pipeline_ctor(t_pipeline *me, t_cmd *cmd, t_environment *env)
{
	int		command_count;

	command_count = env->argc - env->here_doc - 3;
	me->child = -1;
	if (env->here_doc == 0)
		me->input.file_name = ft_strdup(env->argv[1]);
	else
		me->input.file_name = ft_strdup("here_doc.tmp");
	me->file_fd_input = open_input_file(me->input, *env);
	me->output.file_name = ft_strdup(env->argv[env->argc - 1]);
	me->file_fd_output = open_output_file(me->output, *env);
	create_pipes(&me, command_count);
	while (me->child <= command_count)
		run_cmds(&me, cmd, *env, command_count);
}

void	run_cmds(t_pipeline **pipeline, t_cmd *cmd, \
				t_environment env, int command_count)
{
	(**pipeline).child++;
	if ((*pipeline)->child < command_count && \
		cmd[(*pipeline)->child].cmd_exists)
		(*pipeline)->pid = fork();
	if ((*pipeline)->pid == 0 && (**pipeline).child < command_count)
	{
		pipeline_redirection(&pipeline, command_count);
		close_pipe_fds(&pipeline, command_count);
		execve(cmd[(**pipeline).child].exec_options[0], \
		cmd[(**pipeline).child].exec_options, env.envp);
	}
}
