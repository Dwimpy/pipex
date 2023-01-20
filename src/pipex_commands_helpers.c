/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_commands_helpers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 03:31:55 by arobu             #+#    #+#             */
/*   Updated: 2023/01/19 12:32:26 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_commands.h"

void	create_script_command(t_fsm_results **result, \
								t_pipex_command *commands, \
								t_pipex_data *data, int i)
{
	commands[i].cmd = ft_strdup(result[i]->front->word);
	if (!ft_strncmp(commands[i].cmd, "./", 2))
	{
		commands[i].file = new_pipex_exe_file(commands[i].cmd, commands[i].cmd);
		commands[i].options = get_command_option(result[i]);
	}
	else if (ft_strrchr(commands[i].cmd, '/'))
	{
		if (ft_strnstr(ft_strrchr(commands[i].cmd, '/'), ".sh", \
		ft_strlen(ft_strrchr(commands[i].cmd, '/'))))
		{
			commands[i].file = \
			new_pipex_exe_file(commands[i].cmd, commands[i].cmd);
			commands[i].options = get_command_option(result[i]);
		}
	}
	else
		commands[i].file = new_pipex_exe_file(NULL, NULL);
}

void	create_access_command(t_fsm_results **result, \
								t_pipex_command *commands, \
								t_pipex_data *data, int i)
{
	if (ft_strrchr(result[i]->front->word, '/'))
	{
		commands[i].cmd = ft_strdup(ft_strrchr(\
							result[i]->front->word, '/') + 1);
		commands[i].file = new_pipex_exe_file(ft_strrchr(\
							result[i]->front->word, '/') + 1, \
							result[i]->front->word);
	}
	else
	{
		commands[i].cmd = ft_strdup(result[i]->front->word);
		commands[i].file = get_command_path(commands[i].cmd, data->binaries);
	}
	commands[i].options = get_command_option(result[i]);
}

void	create_regular_command(t_fsm_results **result, \
								t_pipex_command *commands, \
								t_pipex_data *data, int i)
{
	commands[i].cmd = ft_strdup(result[i]->front->word);
	commands[i].options = get_command_option(result[i]);
	commands[i].file = get_command_path(\
						commands[i].cmd, data->binaries);
}
