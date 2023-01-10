/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parser_queue_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:26:55 by arobu             #+#    #+#             */
/*   Updated: 2023/01/10 13:03:21 by arobu            ###   ########.fr       */
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
