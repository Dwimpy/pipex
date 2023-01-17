/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execution.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:26:47 by arobu             #+#    #+#             */
/*   Updated: 2023/01/17 02:31:56 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_EXECUTION_H
# define PIPEX_EXECUTION_H
# include "../include/pipex_pipes.h"
# include "../include/pipex_commands.h"
# include <errno.h>
# include <string.h>

typedef struct s_pipex_exectuion
{
	char		*command_path;
	char		*args[2];
	char		**envp;
}				t_pipex_execution;

void	ft_pipex_executor(t_pipex_command *commands, char **envp, \
						t_pipex_data *pipex_data, int size);
void	fork_command(t_pipex_execution executor, t_pipex_pipeline *pipeline, int size);
void	create_pipeline(t_pipex_pipeline *pipeline, t_pipex_data *data);

#endif