/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parser_queue_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:26:55 by arobu             #+#    #+#             */
/*   Updated: 2023/01/07 22:55:33 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_parser.h"

void	display_node_values(t_pipex_parser *parser)
{
	t_parser_node	*node;

	node = parser->front;
	while (node != NULL)
	{
		ft_printf("%c", node->c);
		node = node->next;
	}
}

void	set_parser_state(t_pipex_parser *parser, t_parser_input *input)
{
	if (input->str[0] == '\'')
		parser->state = SINGLE_QUOTE;
	else if (input->str[0] == '\"')
		parser->state = DOUBLE_QUOTE;
	else if (input->str[0] == '\\')
		parser->state = ESCAPED_CHAR;
	else
		parser->state = WHITESPACE;
}



void	parse_state_whitespace(t_pipex_parser *parser, char	**remainder)
{
	while (**remainder)
	{
		enqueue(parser, **remainder);
		(*remainder)++;
	}
	while ((**remainder))
		(*remainder)++;
}

void	run_parser(t_pipex_parser *parser, t_parser_input *input)
{
	char	*input_str_ptr;

	input_str_ptr = input->str;
	while (*input_str_ptr)
	{
		set_parser_state(parser, input);
		if (parser->state == WHITESPACE)
			parse_state_whitespace(parser, &input_str_ptr);
		input_str_ptr++;
	}
}