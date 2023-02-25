/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_state_machine_initializer.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:49:04 by arobu             #+#    #+#             */
/*   Updated: 2023/02/25 14:31:09 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_parser.h"

void	initialize_state_machine(t_word_tracker *word, \
								t_fsm_results **result,
								t_state_machine *fsm,
								char *parsed_input)
{
	word->ptr = parsed_input;
	init_state_machine(fsm);
	(*result) = create_result();
}
