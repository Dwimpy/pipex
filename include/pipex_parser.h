/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:04:55 by arobu             #+#    #+#             */
/*   Updated: 2023/01/19 11:53:48 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_PARSER_H
# define PIPEX_PARSER_H

# include "../libft/include/ft_printf.h"
# include "../include/pipex_scanner.h"
# include "../include/pipex_states.h"

typedef struct s_fsm_results_node	t_fsm_results_node;

typedef enum e_fsm_state
{
	NOTHING = 0,
	REGULAR = 1,
	IN_SINGLE_QUOTE = 2,
	IN_DOUBLE_QUOTE = 3,
	IN_SCRIPT_STATE = 4
}			t_fsm_states;

typedef struct s_fsm_results_node
{
	char				*word;
	t_fsm_results_node	*next;
}				t_fsm_results_node;

typedef struct s_word_tracker
{
	char		*ptr;
	char		*word_start;
}				t_word_tracker;

typedef struct s_fsm_results
{
	t_fsm_results_node	*front;
	t_fsm_results_node	*rear;
	int					size;
}				t_fsm_results;

typedef struct s_state_machine
{
	t_fsm_states		e_state;
	t_fsm_stack			*states;
}				t_state_machine;

t_fsm_results_node		*new_result_node(char *word);
t_fsm_results			*fsm_run(t_pipex_scanner_results *result);
t_fsm_results			*create_result(void);

int						is_empty(t_fsm_results *results);

void					display_result_values(t_fsm_results *results);
void					init_state_machine(t_state_machine *fsm);
void					enqueue(t_fsm_results *results, char *str);
void					dequeue(t_fsm_results *results);
void					ft_free_results(t_fsm_results **result, int size);
void					fsm_regular_update_state(t_word_tracker *tracker, \
						t_fsm_states state, t_state_machine *fsm);
void					fsm_quotes_update_state(t_word_tracker *tracker, \
						t_fsm_states state, char c, t_state_machine *fsm);
void					fsm_update_state_script(t_state_machine *fsm, \
						t_word_tracker *word);
void					fsm_do_script_state(t_fsm_results *result, \
						t_state_machine *fsm, t_word_tracker *word);
void					initialize_state_machine(t_word_tracker *word, \
						t_fsm_results **result, t_state_machine *fsm, \
						char *parsed_input);
#endif