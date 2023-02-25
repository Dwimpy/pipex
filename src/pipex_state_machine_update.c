/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_state_machine_update.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:12:25 by arobu             #+#    #+#             */
/*   Updated: 2023/02/25 14:31:09 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_parser.h"

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

void	fsm_update_state_script(t_state_machine *fsm, \
								t_word_tracker *word)
{
	if (ft_strncmp(word->ptr, "./", 2) == 0)
	{
		fsm->e_state = IN_SCRIPT_STATE;
		push_state(fsm->states, 'S');
		word->word_start = word->ptr;
	}
}

void	fsm_do_script_state(t_fsm_results *result, t_state_machine *fsm, \
							t_word_tracker *word)
{
	if (ft_isspace3(*word->ptr) && *(word->ptr - 1) == '\\')
		word->ptr++;
	else if (ft_isspace3(*word->ptr) && \
	ft_strnstr(word->ptr, ".sh", ft_strlen(word->ptr)))
	{
		enqueue(result, ft_substr(word->word_start, \
					0, word->ptr - word->word_start));
		pop_state(fsm->states);
		fsm->e_state = NOTHING;
	}
	else if (ft_isspace3(*word->ptr))
	{
		if ((ft_isspace3(*word->ptr) && \
			ft_strncmp((word->ptr - 3), ".sh", 3) == 0))
		{
			enqueue(result, ft_substr(word->word_start, \
						0, word->ptr - word->word_start));
			pop_state(fsm->states);
			fsm->e_state = NOTHING;
		}
	}
}
