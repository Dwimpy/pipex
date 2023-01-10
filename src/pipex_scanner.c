/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_scanner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:28:04 by arobu             #+#    #+#             */
/*   Updated: 2023/01/10 22:39:23 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_scanner.h"
#include "../libft/include/ft_printf.h"

static char	*str_fix_whitespaces(char *str, int new_len);
static int	count_parsed_characters(char *str);

t_scanner_results	*scan_input(int argc, char **argv)
{
	t_scanner_results *results;
	
	results = (t_scanner_results *)malloc(sizeof(t_scanner_results));
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

static void	add_bytes(char **str, char c)
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
	while (*str)
	{
		if (ft_isspace3(*str) && has_whitespace == 1)
		{
			str++;
			continue ;
		}
		if (ft_isspace3(*str) && has_whitespace == 0)
		{
			has_whitespace = 1;
			add_bytes(&begin, *str);
			begin++;
			continue ;
		}
		if (!ft_isspace3(*str))
		{
			has_whitespace = 0;
			add_bytes(&begin, *str);
			begin++;
			str++;
		}
	}
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

int	count_words(char *str)
{
	
}