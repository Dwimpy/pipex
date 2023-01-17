/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:54:30 by arobu             #+#    #+#             */
/*   Updated: 2023/01/17 03:33:51 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/pipex_execution.h"
#include <sys/wait.h>

static void	set_execution_parameters(t_pipex_execution *executor, \
								t_pipex_command command, char **envp);

void	ft_pipex_executor(t_pipex_command *commands, char **envp, \
							t_pipex_data *pipex_data, int size)
{
	t_pipex_execution	pipex_executor;
	t_pipex_pipeline	pipeline;

	create_pipeline(&pipeline, pipex_data);
	while (pipeline.child < size)
	{
		set_execution_parameters(&pipex_executor, commands[pipeline.child], envp);
		fork_command(pipex_executor, &pipeline, pipex_data->command_number);
		pipeline.child++;
	}

}

void	create_pipeline(t_pipex_pipeline *pipeline, t_pipex_data *data)
{
	(*pipeline).child = 0;
	(*pipeline).file_fd_input = open(data->input_file->filename, O_RDONLY);
	(*pipeline).file_fd_output = open(data->output_file->filename, O_WRONLY | O_TRUNC);
	(*pipeline).pipe = create_pipes(data->command_number);
}

static void	set_execution_parameters(t_pipex_execution *executor, \
								t_pipex_command command, char **envp)
{
	executor->envp = envp;
	executor->command_path = command.file->filepath;
	executor->args[0] = command.cmd;
	executor->args[1] = command.option;
	executor->args[2] = NULL;
}

void	fork_command(t_pipex_execution executor, t_pipex_pipeline *pipeline, int size)
{
	pid_t	pid;
	int		status;
	
	pid = fork();
	status = 0;
	if (pid == 0)
	{
		ft_printf("ForK: [%s]\n", executor.args[0]);
		ft_printf("Fork: [%s]\n", executor.args[1]);
		ft_redirect_pipes(&pipeline, size);
		close_pipe_fds(&pipeline, size);
		if (execve(executor.command_path, executor.args, executor.envp) == -1)
		{
			exit (-1);
		}
	}
}
