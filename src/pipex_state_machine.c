/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_state_machine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:09:31 by arobu             #+#    #+#             */
/*   Updated: 2023/01/13 19:03:13 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_scanner.h"
#include "../include/pipex_state_machine.h"

void	fsm_run(t_pipex_scanner_results *result)
{
	t_state_machine	fsm;
	char			*ptr;
	
	ptr = result->parsed_input;
	init_state_machine(&fsm);
	while (*ptr)
	{
		
	}
}

void	init_state_machine(t_state_machine *fsm)
{
	(*fsm).s_state = create_state_stack();
	(*fsm).e_state = NOTHING;
}