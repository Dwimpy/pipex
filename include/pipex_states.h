/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_states.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:15:27 by arobu             #+#    #+#             */
/*   Updated: 2023/01/19 03:16:21 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_STATES_H
# define PIPEX_STATES_H

# include <stdlib.h>

typedef struct s_snode	t_snode;

typedef struct s_snode
{
	char		c;
	t_snode		*next;
}				t_snode;

typedef struct s_fsm_stack
{
	int			size;
	t_snode		*top;
}				t_fsm_stack;

t_fsm_stack		*create_state_stack(void);

int				is_empty_state(t_fsm_stack *stack);
int				peek_state(t_fsm_stack *stack);

void			push_state(t_fsm_stack *stack, char c);
void			pop_state(t_fsm_stack *stack);

#endif