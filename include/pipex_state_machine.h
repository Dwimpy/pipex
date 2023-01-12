/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_state_machine.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:04:55 by arobu             #+#    #+#             */
/*   Updated: 2023/01/12 18:46:14 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_STATE_MACHINE_H
# define PIPEX_STATE_MACHINE_H

typedef enum e_fsm_state
{
	NOTHING = 0,
	IN_WORD = 1,
	IN_STRING = 2,
	ADD_TO_RESULT = 3
}			t_fsm_states;

typedef enum e_fsm_quote_type
{
	REGULAR	= 0,
	IN_SINGLE_QUOTE = 1,
	IN_DOUBLE_QUOTE = 2
}			t_fsm_quotes_type;

typedef struct s_fsm_results
{
	char		**result;
}				t_fsm_results;

typedef struct s_state_machine
{
	t_fsm_quotes_type	type;
	t_fsm_states		state;
}				t_state_machine;

void			init_state_machine(t_state_machine *fsm);
void			fsm_run(t_pipex_scanner_results *result);

#endif