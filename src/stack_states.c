/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:23:08 by arobu             #+#    #+#             */
/*   Updated: 2022/12/01 04:02:43 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_stack.h"

int	isfull(t_stack *stack)
{
	return (stack -> top == stack -> max_size - 1);
}

int	isempty(t_stack *stack)
{
	return (stack -> top == -1);
}

void	free_stack(t_stack *stack)
{
	free(stack -> items);
	free(stack);
}
