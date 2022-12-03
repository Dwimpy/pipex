/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_stack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:15:03 by arobu             #+#    #+#             */
/*   Updated: 2022/12/03 16:15:46 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_STACK_H

# define PIPEX_STACK_H

# include <stdlib.h>
# include "../libft/include/ft_printf.h"

typedef struct s_stack
{
	int			top;
	int			max_size;
	int			*items;
}				t_stack;

t_stack	*create_stack(int capacity);

int		isfull(t_stack *stack);
int		isempty(t_stack *stack);
int		size(t_stack *stack);
int		pop(t_stack *stack);
int		peek(t_stack *stack);
void	push(t_stack *stack, int data);
void	free_stack(t_stack *stack);

#endif