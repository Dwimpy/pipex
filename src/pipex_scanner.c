/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_scanner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:28:04 by arobu             #+#    #+#             */
/*   Updated: 2023/02/25 14:31:09 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*str_fix_whitespaces(char *str, int new_len);
static int	count_parsed_characters(char *str);

t_pipex_scanner	*scan_input(t_pipex_input *input, t_pipex_data *data)
{
	t_pipex_scanner				*scanner;
	t_pipex_scanner_results		*results_ptr;
	int							start_arg;
	int							end_arg;

	scanner = init_scanner(data->here_doc, input->argc, &start_arg, &end_arg);
	if (!scanner || !scanner->results)
		return (NULL);
	results_ptr = scanner->results;
	while (start_arg < end_arg)
	{
		results_ptr->parsed_input = scan_string(input->argv[start_arg]);
		scanner->size++;
		results_ptr++;
		start_arg++;
	}
	results_ptr = NULL;
	return (scanner);
}

char	*scan_string(char *str)
{
	int		new_len;
	char	*parsed_input;
	char	*trimmed_str;

	new_len = count_parsed_characters(str);
	trimmed_str = ft_strtrim(str, " \r\t\v\f\n");
	parsed_input = str_fix_whitespaces(trimmed_str, new_len);
	free(trimmed_str);
	return (parsed_input);
}

void	add_bytes(char **str, char c)
{
	char	bytes[2];
	char	*str_ptr;

	bytes[0] = c;
	bytes[1] = 0;
	str_ptr = *str;
	*str_ptr = bytes[0];
	*(str_ptr + 1) = bytes[1];
}

static char	*str_fix_whitespaces(char *str, int new_len)
{
	char	*parsed_str;
	int		has_whitespace;
	char	*begin;

	has_whitespace = 0;
	parsed_str = (char *)malloc(sizeof(char) * (new_len + 1));
	begin = parsed_str;
	if (!parsed_str)
		return (NULL);
	fix_whitespace_helper(&has_whitespace, &str, &begin);
	return (parsed_str);
}

static int	count_parsed_characters(char *str)
{
	int	new_len;
	int	has_whitespace;

	new_len = 0;
	has_whitespace = 0;
	while (*str)
	{
		if (ft_isspace3(*str) && has_whitespace == 1)
		{
			str++;
			continue ;
		}
		if (ft_isspace3(*str) && has_whitespace == 0)
		{
			new_len++;
			has_whitespace = 1;
			str++;
			continue ;
		}
		if (!ft_isspace3(*str))
			has_whitespace = 0;
		new_len++;
		str++;
	}
	return (new_len);
}
