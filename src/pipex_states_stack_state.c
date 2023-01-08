/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_states_stack_state.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:13:21 by arobu             #+#    #+#             */
/*   Updated: 2023/01/08 14:40:48 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_states_stack.h"

t_node	*new_stack_element(char	c)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->c = c;
	node->next = NULL;
	return (node);
}

int	isempty(t_stack *stack)
{
	return (stack -> size == 0);
}

void	free_stack(t_stack *stack)
{
	t_node	*node;

	if (isempty(stack))
	{
		free(stack);
		return ;
	}
	else
	{
		while (stack->top != NULL)
		{
			node = stack->top;
			stack->top = stack->top->next;
			free(node);
		}
		free(stack);
	}
}