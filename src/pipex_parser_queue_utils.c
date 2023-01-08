/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parser_queue_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:26:55 by arobu             #+#    #+#             */
/*   Updated: 2023/01/08 22:59:12 by arobu            ###   ########.fr       */
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

void	set_parser_state(t_pipex_parser *parser, t_stack *state)
{
	if (peek(state) == '\'')
		parser->state = SINGLE_QUOTE;
	else if (peek(state) == '\"')
		parser->state = DOUBLE_QUOTE;
	else if (isempty(state))
		parser->state = WHITESPACE;
}

void	consume_chars(t_pipex_parser *parser, t_stack *state, char c)
{		
	if (parser->state == WHITESPACE)
		enqueue(parser, c);
	else if (parser->state == SINGLE_QUOTE && peek(state) == '\'')
		enqueue(parser, c);
	else if (parser->state == DOUBLE_QUOTE && peek(state) == '\"')
		enqueue(parser, c);
}

void	update_parser_state(t_stack **state, char **input_str_ptr)
{
	if (**input_str_ptr == '\'')
	{
		if (peek(*state) == '\'')
			pop(*state);
		else
			push(*state, '\'');
		(*input_str_ptr)++;
	}
	else if (**input_str_ptr == '\"')
	{
		if (peek(*state) == '\"')
			pop(*state);
		else
			push(*state, '\"');
		(*input_str_ptr)++;
	}gi
}

void	run_parser(t_pipex_parser *parser, t_stack *state, t_parser_input *input)
{
	char	*input_str_ptr;

	input_str_ptr = input->str;
	while (*input_str_ptr)
	{	
		update_parser_state(&state, &input_str_ptr);
		set_parser_state(parser, state);
		if (*input_str_ptr == '\\')
			input_str_ptr++;
		consume_chars(parser, state, *input_str_ptr);
		if (*input_str_ptr)
			input_str_ptr++;
	}
}