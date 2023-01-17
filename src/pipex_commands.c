/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:49:37 by arobu             #+#    #+#             */
/*   Updated: 2023/01/17 13:04:27 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_commands.h"

static t_fsm_results	**get_fsm_results(t_pipex_scanner *scanner);
static t_pipex_file		*get_command_path(char *cmd, char **binaries);
static t_pipex_command	*create_commands(t_fsm_results **result, \
										t_pipex_data *data, int size);
static char				**get_command_option(t_fsm_results *result);

t_pipex_command	*get_pipex_commands(t_pipex_input *pipex_input, \
								t_pipex_data	*pipex_data)
{
	t_fsm_results		**fsm_results;
	t_pipex_scanner		*scanner;
	t_pipex_command		*commands;
	int					i;

	i = 0;
	scanner = scan_input(pipex_input, pipex_data);
	fsm_results = get_fsm_results(scanner);
	parse_nodes(fsm_results, scanner->size);
	//display_result_values(fsm_results[0]);
	commands = create_commands(fsm_results, pipex_data, scanner->size);
	ft_free_results(fsm_results, scanner->size);
	ft_free_scanner(scanner);
	return (commands);
}

t_fsm_results	**get_fsm_results(t_pipex_scanner *scanner)
{
	int				i;
	t_fsm_results	**fsm_results;

	i = 0;
	fsm_results = (t_fsm_results **)malloc(\
					sizeof(t_fsm_results *) * (scanner->size));
	if (!fsm_results)
		return (NULL);
	while (i < scanner->size)
	{
		fsm_results[i] = fsm_run(&scanner->results[i]);
		i++;
	}
	return (fsm_results);
}

static t_pipex_command	*create_commands(t_fsm_results **result, \
										t_pipex_data *data, int size)
{
	int				i;
	t_pipex_command	*commands;

	i = 0;
	commands = initialize_commands(size);
	while (i < size)
	{
		commands[i].cmd = ft_strdup(result[i]->front->word);
		commands[i].options = get_command_option(result[i]);
		commands[i].file = get_command_path(commands[i].cmd, data->binaries);
		i++;
	}
	i = 0;
	return (commands);
}

static char	**get_command_option(t_fsm_results *result)
{
	t_fsm_results_node	*word;
	char				**options;
	char				*trimmed_option;
	int					i;

	word = result->front;
	options = NULL;
	options = (char **)malloc(sizeof(char *) * (result->size + 1));
	i = 0;
	while (i < result->size)
	{
		trimmed_option = ft_strtrim(word->word, " \t\r\v\f\n");
		options[i] = ft_strdup(trimmed_option);
		word = word->next;
		i++;
		free(trimmed_option);
	}
	options[i] = 0;
	return (options);
}

static t_pipex_file	*get_command_path(char *cmd, char **binaries)
{
	char			*full_path;
	t_pipex_file	*file;
	int				size;
	int				i;

	size = 0;
	i = -1;
	while (binaries[size] != NULL)
		size++;
	while (++i < size)
	{
		if (ft_strncmp(cmd, "./", 2) == 0 && \
			ft_strncmp(ft_strrchr(cmd, '.'), ".sh", 3) == 0)
			full_path = ft_strdup(cmd);
		else
			full_path = ft_strjoin_three(binaries[i], "/", cmd);
		if (access(full_path, F_OK) == 0)
		{
			file = new_pipex_exe_file(cmd, full_path);
			free(full_path);
			return (file);
		}	
		free(full_path);
	}
	return (NULL);
}
