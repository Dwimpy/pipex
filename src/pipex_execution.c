/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:54:30 by arobu             #+#    #+#             */
/*   Updated: 2023/01/17 20:14:29 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/pipex_execution.h"
#include <sys/wait.h>

static void	set_execution_parameters(t_pipex_execution *executor, \
						t_pipex_command command, char **envp);

void	ft_pipex_executor(t_pipex_command *commands, t_pipex_input *input, \
						t_pipex_data *pipex_data, t_pipex_errors *err_handler)
{
	t_pipex_execution	pipex_executor;
	t_pipex_pipeline	pipeline;
	pid_t				status;

	create_pipeline(&pipeline, pipex_data);
	while (pipeline.child < pipex_data->command_number)
	{
		set_execution_parameters(&pipex_executor, \
								commands[pipeline.child], input->envp);
		pipeline.pid = fork_command(&pipex_executor, err_handler, \
									&pipeline, pipex_data);
		pipeline.child++;
	}
	close_pipe_fds_parent(&pipeline, pipex_data->command_number);
	waitpid(pipeline.pid, &err_handler->pid_exit_code, 0);
	free(pipeline.pipe);
}

void	create_pipeline(t_pipex_pipeline *pipeline, t_pipex_data *data)
{
	(*pipeline).child = 0;
	(*pipeline).file_fd_input = open(data->input_file->filename, O_RDONLY);
	(*pipeline).file_fd_output = open(data->output_file->filename, \
									O_WRONLY | O_TRUNC);
	(*pipeline).pipe = create_pipes(data->command_number);
}

static void	set_execution_parameters(t_pipex_execution *executor, \
								t_pipex_command command, char **envp)
{
	executor->envp = envp;
	executor->command_path = command.file->filepath;
	executor->cmd_options = command.options;
}

pid_t	fork_command(t_pipex_execution *executor, t_pipex_errors *err_handler, \
					t_pipex_pipeline *pipeline, t_pipex_data *data)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		ft_redirect_pipes(&pipeline, data->command_number);
		close_pipe_fds(&pipeline, data->command_number);
		if (execve(executor->command_path, \
				executor->cmd_options, executor->envp) == -1)
		{
			exit (EXIT_FAILURE);
		}
	}
	return (pid);
}
