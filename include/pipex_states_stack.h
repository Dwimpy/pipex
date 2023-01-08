/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_states_stack.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:11:41 by arobu             #+#    #+#             */
/*   Updated: 2023/01/08 17:33:40 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_STATES_STACK_H
# define PIPEX_STATES_STACK_H

# include "../libft/include/ft_printf.h"

typedef struct s_node	t_node;
typedef struct s_stack	t_stack;

typedef struct s_node
{
	char		c;
	t_node		*next;
}				t_node;

typedef struct s_stack
{
	t_node		*top;
	int			size;
}				t_stack;

t_stack	*create_stack(void);

int		isempty(t_stack *stack);
int		size(t_stack *stack);
int		peek(t_stack *stack);
void	pop(t_stack *stack);
void	push(t_stack *stack, char c);
void	free_stack(t_stack *stack);
t_node	*new_stack_element(char	c);

#endif