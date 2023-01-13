/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_state_machine.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:04:55 by arobu             #+#    #+#             */
/*   Updated: 2023/01/13 19:02:16 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_STATE_MACHINE_H
# define PIPEX_STATE_MACHINE_H

#include "pipex_states.h"
#include "../libft/include/ft_printf.h"

typedef struct s_fsm_results_node	t_fsm_results_node;

typedef enum e_fsm_state
{
	NOTHING = 0,
	REGULAR = 1,
	IN_SINGLE_QUOTE = 2,
	IN_DOUBLE_QUOTE = 3,
	ADD_TO_RESULT = 4
}			t_fsm_states;

typedef struct s_fsm_results_node
{
	char				*word;
	t_fsm_results_node	*next;
}				t_fsm_results_node;

typedef struct s_fsm_results
{
	t_fsm_results_node	*front;
	t_fsm_results_node	*rear;
	int					size;
}				t_fsm_results;

typedef struct s_state_machine
{
	t_fsm_states		e_state;
	t_fsm_stack			*s_state;
}				t_state_machine;

t_fsm_results_node		*new_result_node(char *word);
t_fsm_results			*create_result(void);

int						is_empty(t_fsm_results *results);

void					display_result_values(t_fsm_results *results);
void					init_state_machine(t_state_machine *fsm);
void					enqueue(t_fsm_results *results, char *str);
void					dequeue(t_fsm_results *results);

#endif