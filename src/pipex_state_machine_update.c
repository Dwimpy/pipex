/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_state_machine_update.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:12:25 by arobu             #+#    #+#             */
/*   Updated: 2023/01/18 17:50:12 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_parser.h"

void	fsm_quotes_update_state(t_word_tracker *tracker, \
					t_fsm_states state, char c, t_state_machine *fsm)
{
	if (ft_strchr(tracker->ptr + 1, c))
	{
		fsm->e_state = state;
		push_state(fsm->states, c);
		tracker->word_start = tracker->ptr;
	}
	else if (!ft_strchr(tracker->ptr + 1, c) && *(tracker->ptr + 1) == '\0')
		tracker->ptr++;
	else
		return ;
}

void	fsm_regular_update_state(t_word_tracker *tracker, \
					t_fsm_states state, t_state_machine *fsm)
{
	fsm->e_state = state;
	tracker->word_start = tracker->ptr;
}