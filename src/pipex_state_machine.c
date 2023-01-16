/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_state_machine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:09:31 by arobu             #+#    #+#             */
/*   Updated: 2023/01/16 21:12:48 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_parser.h"

static void fsm_do_nothing(t_word_tracker *tracker, t_state_machine *fsm);
static void fsm_do_quote_state(t_fsm_results *result, t_state_machine *fsm, \
								t_word_tracker *word, char c);
static void fsm_do_regular_state(t_fsm_results *result, t_state_machine *fsm, \
								t_word_tracker *word, size_t *is_end);

t_fsm_results	*fsm_run(t_pipex_scanner_results *result)
{
	t_state_machine	fsm;
	t_word_tracker	word;
	t_fsm_results	*fsm_result;
	size_t			str_end;

	word.ptr = result->parsed_input;
	init_state_machine(&fsm);
	fsm_result = create_result();
	str_end = 0;
	while (*(word.ptr) != '\0')
	{
		if (fsm.e_state == NOTHING)
			fsm_do_nothing(&word, &fsm);
		else if (fsm.e_state == REGULAR)
			fsm_do_regular_state(fsm_result, &fsm, &word, &str_end);
		else if (fsm.e_state == IN_SINGLE_QUOTE)
			fsm_do_quote_state(fsm_result, &fsm, &word, '\'');
		else if (fsm.e_state == IN_DOUBLE_QUOTE)
			fsm_do_quote_state(fsm_result, &fsm, &word, '\"');
		(word.ptr)++;
	}
	if (fsm.e_state != NOTHING)
	{
		enqueue(fsm_result, ft_substr(word.word_start, \
				0, word.ptr - word.word_start));
	}
	free(fsm.states);
	return (fsm_result);
}

static void	fsm_do_nothing(t_word_tracker *tracker, t_state_machine *fsm)
{
	if (*(tracker->ptr) == '\'')
		fsm_quotes_update_state(tracker, IN_SINGLE_QUOTE, '\'', fsm);
	else if (*(tracker->ptr) == '\"')
		fsm_quotes_update_state(tracker, IN_DOUBLE_QUOTE, '\"', fsm);
	else
		fsm_regular_update_state(tracker, REGULAR, fsm);	
}

static void fsm_do_quote_state(t_fsm_results *result, t_state_machine *fsm, \
								t_word_tracker *word, char c)
{
	if (*(word->ptr) == c)
	{
		enqueue(result, ft_substr(word->word_start, \
							1, word->ptr - word->word_start - 1));
		pop_state(fsm->states);
		fsm->e_state = NOTHING;
	}
}

static void fsm_do_regular_state(t_fsm_results *result, t_state_machine *fsm, \
								t_word_tracker *word, size_t *is_end)
{
	if (ft_isspace3(*word->ptr) || *(word->ptr + 1) == '\0')
	{
		if (*(word->ptr + 1) == '\0')
			*is_end = 1;
		enqueue(result, ft_substr(word->word_start, \
						0, word->ptr - word->word_start + *is_end));
		fsm->e_state = NOTHING;
	}
}