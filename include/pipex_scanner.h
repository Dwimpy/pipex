/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_scanner.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:25:15 by arobu             #+#    #+#             */
/*   Updated: 2023/01/19 03:16:36 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_SCANNER_H
# define PIPEX_SCANNER_H

# include <stdlib.h>
# include "../libft/include/ft_printf.h"

typedef struct s_pipex_scanner_results
{
	char		*parsed_input;
}				t_pipex_scanner_results;

typedef struct s_pipex_scanner
{
	int						size;
	t_pipex_scanner_results	*results;
}				t_pipex_scanner;

t_pipex_scanner		*init_scanner(int here_doc, int argc, \
							int *start_arg, int *end_arg);

char				*scan_string(char *str);

void				display_scanner_results(t_pipex_scanner *scanner);
void				fix_whitespace_helper(int *has_whitespace, \
							char **str, char **begin);
void				add_bytes(char **str, char c);
void				ft_free_scanner(t_pipex_scanner *scanner);
#endif
