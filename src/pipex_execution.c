/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:54:30 by arobu             #+#    #+#             */
/*   Updated: 2023/01/16 21:56:58 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/pipex_execution.h"

static void	set_execution_parameters(t_pipex_execution *executor, \
								t_pipex_command command);

void	ft_pipex_executor(t_pipex_command *commands, char **envp, \
							t_pipex_data *pipex_data, int size)
{
	t_pipex_execution	pipex_executor;
	t_pipex_pipes		*pipes;
	int					i;
	int					input_fd;
	int					output_fd;

	pipex_executor.envp = envp;
	i = 0;
	pipes = create_pipes(pipex_data->command_number);
	pipe_the_pipes(&pipes, pipex_data->command_number);
	while (i < size)
	{
		set_execution_parameters(&pipex_executor, commands[i]);
		fork_command(pipex_executor, pipes, pipex_data, i);
		i++;
	}
}

static void	set_execution_parameters(t_pipex_execution *executor, \
								t_pipex_command command)
{
	executor->command_path = command.file->filepath;
	executor->args[0] = command.cmd;
	executor->args[1] = command.option;
	executor->args[2] = NULL;
}

void	fork_command(t_pipex_execution executor, t_pipex_pipes *pipes, \
					t_pipex_data *pipex_data, int child_number)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		ft_redirect_pipes(&pipes, pipex_data, child_number);
		close_pipe_fds(pipes, pipex_data->command_number);
		if (execve(executor.command_path, executor.args, executor.envp) == -1)
		{
			exit (-1);
		}
	}
}
