/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_commands_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:52:17 by arobu             #+#    #+#             */
/*   Updated: 2023/01/19 03:17:11 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_commands.h"

void	parse_nodes(t_fsm_results **result, int size)
{
	int					i;
	int					j;
	t_fsm_results_node	*word;

	i = 0;
	while (i < size)
	{
		word = result[i]->front;
		while (word != NULL)
		{
			parse_escape(&word->word);
			word = word->next;
		}
		i++;
	}
}

t_pipex_command	*initialize_commands(int size)
{
	int				i;
	t_pipex_command	*commands;

	commands = (t_pipex_command *)malloc(sizeof(t_pipex_command) * size);
	i = 0;
	if (!commands)
		return (NULL);
	while (i < size)
	{
		commands[i].cmd = NULL;
		commands[i].options = NULL;
		commands[i].file = NULL;
		i++;
	}
	return (commands);
}

void	parse_escape(char **str)
{
	int		i;
	int		j;
	char	*str_cpy;

	i = 0;
	j = 0;
	str_cpy = ft_strdup(*str);
	while (j < ft_strlen(*str))
	{
		if ((str_cpy[j]) == '\\')
			j++;
		(*str)[i] = str_cpy[j];
		i++;
		j++;
	}
	(*str)[i] = '\0';
	free(str_cpy);
}

void	ft_free_commands(t_pipex_command *commands, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(commands[i].cmd);
		if (commands[i].options != NULL)
			ft_free_command_options(commands[i].options);
		if (commands[i].file)
			ft_free_file(commands[i].file);
		i++;
	}
	free(commands);
}

void	ft_free_command_options(char **options)
{
	int	i;

	i = 0;
	if (options)
	{
		while (options[i] != NULL)
		{
			free(options[i]);
			i++;
		}
		free(options);
	}
}
