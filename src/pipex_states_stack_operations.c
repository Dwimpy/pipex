/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_states_stack_operations.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:13:46 by arobu             #+#    #+#             */
/*   Updated: 2023/01/08 14:11:33 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_states_stack.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

int	size(t_stack *stack)
{
	return (stack->size);
}

void	push(t_stack *stack, char c)
{
	t_node	*elem;

	elem = new_stack_element(c);
	elem->next = stack->top;
	stack->top = elem;
	stack->size++;
}

int	peek(t_stack *stack)
{
	if (isempty(stack))
		return (0);
	return ((char)stack->top->c);
}

void	pop(t_stack *stack)
{
	t_node	*curr_top;

	if (isempty(stack))
		return ;
	if (stack->size == 1)
	{
		free(stack->top);
		stack->top = NULL;
	}
	else
	{
		curr_top = stack->top;
		stack->top = stack->top->next;
		free(curr_top);
		curr_top = NULL;
	}
	stack->size--;
}