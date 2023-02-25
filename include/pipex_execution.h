/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execution.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:26:47 by arobu             #+#    #+#             */
/*   Updated: 2023/02/25 14:00:09 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_EXECUTION_H
# define PIPEX_EXECUTION_H
# include "pipex_pipes.h"
# include "pipex_commands.h"
# include <errno.h>
# include <string.h>

typedef struct s_pipex_exectuion
{
	char		*command_path;
	char		**cmd_options;
	char		**envp;
}				t_pipex_execution;

void	ft_pipex_executor(t_pipex_command *commands, t_pipex_input *input, \
						t_pipex_data *pipex_data, t_pipex_errors *err_handler);
pid_t	fork_command(t_pipex_execution *executor, t_pipex_errors *err_handler, \
					t_pipex_pipeline *pipeline, t_pipex_data *data);
void	run_child_fd_checker(t_pipex_data *data, \
							t_pipex_errors *err_handler, \
							t_pipex_pipeline *pipeline);
void	create_pipeline(t_pipex_pipeline *pipeline, t_pipex_data *data);

#endif
