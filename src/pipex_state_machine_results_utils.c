/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_state_machine_results_utils.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:06:17 by arobu             #+#    #+#             */
/*   Updated: 2023/01/13 17:07:55 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_state_machine.h"

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