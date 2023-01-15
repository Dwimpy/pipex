/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:32:53 by arobu             #+#    #+#             */
/*   Updated: 2023/01/15 17:57:50 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../include/pipex_commands.h"

void	ft_free_pipex_memory(t_pipex_data *data, t_pipex_input *input);

void	pipex(int argc, char **argv, char **envp)
{
	t_pipex_input		*pipex_input;
	t_pipex_data		*pipex_data;
	t_pipex_command		*commands;

	pipex_input = pipex_new_input(argc, argv, envp);
	pipex_input_validator(pipex_input);
	pipex_data = create_new_data(pipex_input);
	commands = get_pipex_commands(pipex_input, pipex_data);

	ft_free_commands(commands, pipex_input->argc - pipex_data->here_doc - 3);
	ft_free_pipex_memory(pipex_data, pipex_input);
}

void	ft_free_pipex_memory(t_pipex_data *data, t_pipex_input *input)
{
	ft_free_allocated_memory(data);
	free(input);
}