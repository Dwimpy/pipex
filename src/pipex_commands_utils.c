/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_commands_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:52:17 by arobu             #+#    #+#             */
/*   Updated: 2023/01/15 15:19:54 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_commands.h"

void	parse_nodes(t_fsm_results **result, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		parse_escape(&result[i]->front->word);
		if (result[i]->rear != NULL)
			parse_escape(&result[i]->front->word);
		i++;
	}
}

void	parse_escape(char **str)
{
	int		i;
	int		escaped_chars;
	char	*parsed_str;
	int		j;

	i = 0;
	escaped_chars = 0;
	if (!str)
		return ;
	while (i < ft_strlen(*str))
	{
		if ((*str)[i] == '\\')
			escaped_chars++;
		(*str)[i] = (*str)[i + escaped_chars];
		i++;
	}
}

void	ft_free_commands(t_pipex_command *commands, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(commands[i].cmd);
		if (commands[i].option)
			free(commands[i].option);
		if (commands[i].file)
			ft_free_file(commands[i].file);
		i++;
	}
	free(commands);
}