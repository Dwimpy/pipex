/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:26:41 by arobu             #+#    #+#             */
/*   Updated: 2023/01/13 17:11:19 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_states.h"
#include "../libft/include/ft_printf.h"

static t_snode	*new_state(char	c)
{
	t_snode	*node;

	node = (t_snode *)malloc(sizeof(t_snode));
	if (!node)
		return (NULL);
	node->c = c;
	node->next = NULL;
	return (node);
}

t_fsm_stack	*create_state_stack(void)
{
	t_fsm_stack	*stack;

	stack = (t_fsm_stack *)malloc(sizeof(t_fsm_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	push_state(t_fsm_stack *stack, char c)
{
	t_snode	*state;

	state = new_state(c);
	if (is_empty_state(stack))
		stack->top = state;
	else
	{
		state->next = stack->top;
		stack->top = state;
	}
	stack->size++;
}

int	peek_state(t_fsm_stack *stack)
{
	if (is_empty_state(stack))
		return (-1);
	return ((unsigned char)stack->top->c);
}

void pop_state(t_fsm_stack *stack)
{
	t_snode	*node;

	if (is_empty_state(stack))
		return ;
	if (stack->size == 1)
	{
		node = stack->top;
		free(node);
		node = NULL;
	}
	else
	{
		node = stack->top;
		stack->top = stack->top->next;
		free(node);
		node = NULL;
	}
	stack->size--;
}