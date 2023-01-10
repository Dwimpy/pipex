/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_scanner.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:25:15 by arobu             #+#    #+#             */
/*   Updated: 2023/01/10 15:18:39 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_SCANNER_H
# define PIPEX_SCANNER_H

typedef	struct s_pipex_scanner
{
	int			word_count;
	char		*parsed_input;
}				t_pipex_scanner;

typedef struct s_scanner_results
{
	t_pipex_scanner	*results;
}				t_scanner_results;

t_scanner_results	*scan_input(int argc, char **argv);
char				*scan_string(char *str);

int	count_words(char *str);

#endif