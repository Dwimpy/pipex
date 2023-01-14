/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_state_machine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:09:31 by arobu             #+#    #+#             */
/*   Updated: 2023/01/14 21:04:50 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_parser.h"

static void	do_nothing_state(t_state_machine *fsm, char **word_start, \
								char *ptr);
static void do_command_state(t_state_machine *fsm, char **word_start, \
								t_fsm_results **result, char *ptr);
static void do_option_state(t_state_machine *fsm, char *word_start, \
								t_fsm_results **result, char *ptr);

t_fsm_results	*fsm_run(t_pipex_scanner_results *result)
{
	t_state_machine	fsm;
	char			*ptr;
	char			*word_start;
	t_fsm_results	*fsm_result;

	ptr = result->parsed_input;
	init_state_machine(&fsm);
	fsm_result = create_result();
	while (*ptr)
	{
		if (fsm.e_state == NOTHING && !ft_strchr(ptr, ' ') && \
			!ft_strchr(ptr, '\t'))
		{
			enqueue(fsm_result, ft_strdup(ptr));
			break ;
		}
		else if (fsm.e_state == NOTHING)
			do_nothing_state(&fsm, &word_start, ptr);
		else if (fsm.e_state == IN_COMMAND)
			do_command_state(&fsm, &word_start, &fsm_result, ptr);
		ptr++;
	}
	do_option_state(&fsm, word_start, &fsm_result, ptr);
	return (fsm_result);
}

static void	do_nothing_state(t_state_machine *fsm, char **word_start, char *ptr)
{
	if (!ft_isspace3(*ptr))
	{
		(*fsm).e_state = IN_COMMAND;
		*word_start = ptr;
	}
}

static void do_command_state(t_state_machine *fsm, char **word_start, \
								t_fsm_results **result, char *ptr)
{
	if (ft_isspace3(*ptr) && *(ptr - 1) == '\\')
		return ;
	if (ft_isspace3(*ptr))
	{
		(*fsm).e_state = IN_OPTION;
		enqueue(*result, ft_substr(*word_start, 0, ptr - *word_start));
		*word_start = ptr + 1;
	}
}

static void do_option_state(t_state_machine *fsm, char *word_start, \
								t_fsm_results **result, char *ptr)
{
	if ((*fsm).e_state != NOTHING)
		enqueue(*result, ft_substr(word_start, 0, ptr - word_start));
}

void	init_state_machine(t_state_machine *fsm)
{
	(*fsm).e_state = NOTHING;
}