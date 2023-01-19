/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_scanner_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:08:44 by arobu             #+#    #+#             */
/*   Updated: 2023/01/19 03:23:34 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_scanner.h"

t_pipex_scanner	*init_scanner(int here_doc, int argc, \
							int *start_arg, int *end_arg)
{
	t_pipex_scanner	*scanner;

	if (here_doc == 0)
		*start_arg = 2;
	else
		*start_arg = 3;
	*end_arg = argc - 1;
	scanner = (t_pipex_scanner *)malloc(sizeof(t_pipex_scanner));
	scanner->results = (t_pipex_scanner_results *) \
		malloc(sizeof(t_pipex_scanner_results) * (*end_arg - *start_arg + 1));
	scanner->size = 0;
	return (scanner);
}

void	display_scanner_results(t_pipex_scanner *scanner)
{
	int	i;

	i = 0;
	while (i < scanner->size)
	{
		ft_printf("%s\n", scanner->results[i].parsed_input);
		i++;
	}
}

void	fix_whitespace_helper(int *has_whitespace, \
							char **str, char **begin)
{
	while (**str)
	{
		if (ft_isspace3(**str) && *has_whitespace == 1)
		{
			(*str)++;
			continue ;
		}
		if (ft_isspace3(**str) && *has_whitespace == 0)
		{
			*has_whitespace = 1;
			add_bytes(begin, **str);
			(*begin)++;
			continue ;
		}
		if (!ft_isspace3(**str))
		{
			*has_whitespace = 0;
			add_bytes(begin, **str);
			(*begin)++;
			(*str)++;
		}
	}
}

void	ft_free_scanner(t_pipex_scanner *scanner)
{
	int	i;

	i = 0;
	while (i < scanner->size)
	{
		free(scanner->results[i].parsed_input);
		i++;
	}
	free(scanner->results);
	free(scanner);
}
