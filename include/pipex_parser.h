/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:02:37 by arobu             #+#    #+#             */
/*   Updated: 2023/01/10 13:03:16 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_PARSER_H
# define PIPEX_PARSER_H

# include "pipex.h"

typedef struct s_parser_node	t_parser_node;

typedef enum e_parser_state
{
	WHITESPACE = 0,
	DOUBLE_QUOTE = 1,
	SINGLE_QUOTE = 2,
	ESCAPED_CHAR = 3,
}			t_parser_state;

typedef struct s_parser_node
{
	char			c;
	t_parser_node	*next;
}				t_parser_node;

typedef struct s_parser_input
{
	char		*str;
}				t_parser_input;

typedef struct s_pipex_parser
{
	t_parser_node	*front;
	t_parser_node	*rear;
	t_parser_state	state;
	int				size;
}				t_pipex_parser;

t_pipex_parser	*create_parser(void);
t_parser_node	*new_node(char c);
t_parser_input	*create_input(char	*str);

int				is_empty(t_pipex_parser *parser);
void			enqueue(t_pipex_parser *parser, char c);
void			dequeue(t_pipex_parser *parser);
void			display_node_values(t_pipex_parser *parser);
#endif
