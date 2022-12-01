/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:21:22 by arobu             #+#    #+#             */
/*   Updated: 2022/12/01 04:03:56 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_stack.h"

t_stack	*create_stack(unsigned int capacity)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack -> top = -1;
	stack -> max_size = capacity;
	stack -> items = (int *)malloc(sizeof(int) * (stack -> max_size));
	return (stack);
}

int	size(t_stack *stack)
{
	return (stack -> top + 1);
}

void	push(t_stack *stack, int data)
{
	if (isfull(stack))
	{
		ft_printf("Stack is full!");
		return ;
	}
	stack -> top += 1;
	stack -> items[stack -> top] = data;
}

int	peek(t_stack *stack)
{
	if (!isempty(stack))
		return (stack -> items[stack -> top]);
	else
	{
		ft_printf("Stack is empty!");
		return (-1);
	}
}

int	pop(t_stack *stack)
{
	if (isempty(stack))
	{
		ft_printf("Stack is empty!");
		return (-1);
	}
	else
		return (stack -> items[stack -> top--]);
}
