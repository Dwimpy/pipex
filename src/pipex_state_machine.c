/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_state_machine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:09:31 by arobu             #+#    #+#             */
/*   Updated: 2023/01/12 19:36:13 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_scanner.h"
#include "../include/pipex_state_machine.h"

void	fsm_run(t_pipex_scanner_results *result)
{
	t_state_machine	fsm;
	char			*res_ptr;
	char			*word_start;
	char			*word;

	res_ptr = result->parsed_input;
	init_state_machine(&fsm);
	while (*res_ptr)
	{

		if (fsm.state == NOTHING)
		{
			if (ft_isspace3(*res_ptr))
			{
				res_ptr++;
				continue ;
			}
			if (*res_ptr == '\'')
			{
				fsm.type = IN_SINGLE_QUOTE;
				fsm.state = IN_STRING;
				res_ptr++;
				word_start = res_ptr;
				continue ;
			}
			if ((*res_ptr) == '\"')
			{
				fsm.type = IN_DOUBLE_QUOTE;
				fsm.state = IN_STRING;
				res_ptr++;
				word_start = res_ptr;
				continue ;
			}
			fsm.state = IN_WORD;
			word_start = res_ptr;
			res_ptr++;
			continue ;
		}
		else if (fsm.state == IN_STRING)
		{
			if (fsm.type == IN_SINGLE_QUOTE && (*res_ptr) == '\'')
			{
				word = ft_substr(word_start, 0, res_ptr - word_start);
				ft_printf("%s\n", word);
				fsm.type = REGULAR;
				fsm.state = NOTHING;
			}
			if (fsm.type == IN_DOUBLE_QUOTE && (*res_ptr) == '\"')
			{
				word = ft_substr(word_start, 0, res_ptr - word_start - 1);
				ft_printf("%s\n", word);
				fsm.type = REGULAR;
				fsm.state = NOTHING;
			}
			res_ptr++;
			continue ;
		}
		else if (fsm.state == IN_WORD)
		{
			if (ft_isspace3(*res_ptr))
			{
				word = ft_substr(word_start, 0, res_ptr - word_start);
				ft_printf("%s\n", word);
				fsm.state = NOTHING;
			}
			res_ptr++;
			continue ;
		}
	}
	if (fsm.state != NOTHING)
	{
		word = ft_substr(word_start, 0, res_ptr - word_start);
		ft_printf("%s\n", word);
	}	
}

void	init_state_machine(t_state_machine *fsm)
{
	(*fsm).state = NOTHING;
	(*fsm).type = REGULAR;
}