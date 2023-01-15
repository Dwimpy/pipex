/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_state_machine_results.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:41:44 by arobu             #+#    #+#             */
/*   Updated: 2023/01/15 15:12:37 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_parser.h"

t_fsm_results_node	*new_result_node(char *word)
{
	t_fsm_results_node	*node;

	node = (t_fsm_results_node *)malloc(sizeof(t_fsm_results_node));
	if (!node)
		return (NULL);
	node->word = word;
	node->next = NULL;
	return (node);
}

t_fsm_results	*create_result(void)
{
	t_fsm_results	*results;

	results = (t_fsm_results *)malloc(sizeof(t_fsm_results));
	if (!results)
		return (NULL);
	results->front = NULL;
	results->rear = NULL;
	results->size = 0;
	return (results);
}

int	is_empty(t_fsm_results *results)
{
	return (results->size == 0);
}

void	enqueue(t_fsm_results *results, char *str)
{
	t_fsm_results_node	*node;

	node = new_result_node(str);
	if (is_empty(results))
	{
		results->front = node;
		results->rear = node;
	}
	else
	{
		results->rear->next = node;
		results->rear = results->rear->next;
	}
	results->size++;
}

void	dequeue(t_fsm_results *results)
{
	t_fsm_results_node	*node;

	if (is_empty(results))
		return ;
	else if (results->front == results->rear)
	{
		node = results->front;
		free(node->word);
		free(node);
		results->front = NULL;
		results->rear = NULL;
	}
	else
	{
		node = results->front;
		results->front = results->front->next;
		free(node->word);
		free(node);
		node = NULL;
	}
	results->size--;
}