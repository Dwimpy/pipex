/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:49:37 by arobu             #+#    #+#             */
/*   Updated: 2023/01/18 22:30:36 by arobu            ###   ########.fr       */
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
	// display_result_values(fsm_results[0]);
	// display_result_values(fsm_results[1]);
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
		if (ft_strnstr(result[i]->front->word, ".sh", \
			ft_strlen(result[i]->front->word)))
		{
			commands[i].cmd = ft_strdup(result[i]->front->word);
			if (!ft_strncmp(commands[i].cmd, "./", 2))
				commands[i].file = new_pipex_exe_file(commands[i].cmd, commands[i].cmd);
			else if (ft_strrchr(commands[i].cmd, '/'))
			{
				if (ft_strnstr(ft_strrchr(commands[i].cmd, '/'), ".sh", \
				ft_strlen(ft_strrchr(commands[i].cmd, '/'))))
					commands[i].file = new_pipex_exe_file(commands[i].cmd, commands[i].cmd);
			}
			else
				commands[i].file = new_pipex_exe_file(NULL, NULL);
		}
		else if (access(result[i]->front->word, F_OK) == 0)
		{
			commands[i].cmd = ft_strdup(ft_strrchr(result[i]->front->word, '/') + 1);
			commands[i].options = get_command_option(result[i]);
			commands[i].file = new_pipex_exe_file(ft_strrchr(result[i]->front->word, '/') + 1, result[i]->front->word);
		}
		else
		{
			commands[i].cmd = ft_strdup(result[i]->front->word);
			commands[i].options = get_command_option(result[i]);
			commands[i].file = get_command_path(commands[i].cmd, data->binaries);
		}
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
	if (!options)
		return (NULL);
	trimmed_option = NULL;
	i = 0;
	if (access(word->word, F_OK) == 0)
	{
		trimmed_option = ft_strtrim(ft_strrchr(word->word, '/') + 1, " \t\r\v\f\n");
		options[i] = ft_strdup(trimmed_option);
		word = word->next;
		i++;
	}
	while (i < result->size)
	{
		trimmed_option = ft_strtrim(word->word, " \t\r\v\f\n");
		options[i] = ft_strdup(trimmed_option);
		word = word->next;
		free(trimmed_option);
		trimmed_option = NULL;
		i++;
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
	while (binaries && binaries[size] != NULL)
		size++;
	while (++i < size)
	{
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
