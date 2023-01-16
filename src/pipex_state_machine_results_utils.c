/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_state_machine_results_utils.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:06:17 by arobu             #+#    #+#             */
/*   Updated: 2023/01/16 15:19:37 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_parser.h"

void	display_result_values(t_fsm_results *results)
{
	t_fsm_results_node	*node;

	node = results->front;
	while (node)
	{
		ft_printf("%s\n", node->word);
		node = node->next;
	}
}

void	init_state_machine(t_state_machine *fsm)
{
	(*fsm).e_state = NOTHING;
	(*fsm).states = create_state_stack();
}

void	ft_free_results(t_fsm_results **result, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		while (result[i]->front != NULL)
			dequeue(result[i]);
		free(result[i]);
		i++;
	}
	free(result);
}