/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_state_machine_results_utils.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:06:17 by arobu             #+#    #+#             */
/*   Updated: 2023/01/14 21:18:52 by arobu            ###   ########.fr       */
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

void	ft_free_results(t_fsm_results **result, int size)
{
	int	i;
	
	i = 0;
	while (i < size)
	{
			free(result[i]->front->word);
			if (result[i]->rear && result[i]->rear->word)
				free(result[i]->rear->word);
			free(result[i]->front);
			if (result[i]->rear)
				free(result[i]->rear);
			free(result[i]);
		i++;
	}
	free(result);
}