/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parser_queue_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:26:55 by arobu             #+#    #+#             */
/*   Updated: 2023/01/08 01:30:42 by arobu            ###   ########.fr       */
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

void	set_parser_state(t_pipex_parser *parser, char **input_str)
{
	if ((**input_str) == 39)
		parser->state = SINGLE_QUOTE;
	else if ((**input_str) == 34)
		parser->state = DOUBLE_QUOTE;
	else if ((**input_str) == 92)
		parser->state = ESCAPED_CHAR;
	else
		parser->state = WHITESPACE;
}



void	parse_state_whitespace(t_pipex_parser *parser, char	**remainder)
{
	while ((**remainder) && !ft_isspace3(**remainder))
	{
		enqueue(parser, **remainder);
		(*remainder)++;
	}
	while (ft_isspace3(*(*remainder + 1)))
	{
		(*remainder)++;
	}

}

void	run_parser(t_pipex_parser *parser, t_parser_input *input)
{
	char	*input_str_ptr;

	input_str_ptr = input->str;
	set_parser_state(parser, &input_str_ptr);
	while (*input_str_ptr)
	{
		set_parser_state(parser, &input_str_ptr);
		if (parser->state == WHITESPACE)
			parse_state_whitespace(parser, &input_str_ptr);
		else if (parser->state == SINGLE_QUOTE)
			ft_printf("SINGLE QUOTE\n");
		ft_printf("State: %d\n", parser->state);
		input_str_ptr++;
	}
}