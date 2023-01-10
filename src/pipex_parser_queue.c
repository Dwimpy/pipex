/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parser_queue.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:09:05 by arobu             #+#    #+#             */
/*   Updated: 2023/01/10 13:03:26 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_parser.h"

t_pipex_parser	*create_parser(void)
{
	t_pipex_parser	*parser;

	parser = (t_pipex_parser *)malloc(sizeof(t_pipex_parser));
	if (!parser)
		return (NULL);
	parser->front = NULL;
	parser->rear = NULL;
	parser->size = 0;
	parser->state = WHITESPACE;
	return (parser);
}

t_parser_node	*new_node(char c)
{
	t_parser_node	*node;

	node = (t_parser_node *)malloc(sizeof(t_parser_node));
	if (!node)
		return (NULL);
	node->c = c;
	node->next = NULL;
	return (node);
}

int	is_empty(t_pipex_parser *parser)
{
	return (parser->size == 0);
}

void	enqueue(t_pipex_parser *parser, char c)
{
	t_parser_node	*node;

	node = new_node(c);
	if (is_empty(parser))
	{
		parser->front = node;
		parser->rear = node;
	}
	else
	{
		parser->rear->next = node;
		parser->rear = parser->rear->next;
	}
	parser->size++;
}

void	dequeue(t_pipex_parser *parser)
{
	t_parser_node	*node;

	node = parser->front;
	if (is_empty(parser))
		return ;
	else if (parser->front == parser->rear)
	{
		node = parser->front;
		parser->front = NULL;
		parser->rear = NULL;
	}
	else
	{
		node = parser->front;
		parser->front = parser->front->next;
	}
	parser->size--;
	free(node);
}