/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:56:29 by arobu             #+#    #+#             */
/*   Updated: 2023/01/15 15:02:57 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{	
	pipex(argc, argv, envp);

	// t_fsm_stack	*stack;
	// t_fsm_results *results;
	// char	*args[3];

	// args[0] = "awk";
	// args[1] = "\"{count++} END {printf \"count: %i\" , count}\"";
	// args[2] = NULL;
	// execve("/usr/bin/awk", args, NULL);
	// stack = create_state_stack();
	// results = create_result();
	// push_state(stack, 'a');
	// push_state(stack, 'b');
	// pop_state(stack);
	// pop_state(stack);
	// if (peek_state(stack) != -1)
	//  	ft_printf("%c\n", peek_state(stack));
	// enqueue(results, "FUCK YOU");
	// enqueue(results, "WHATSUP");
	// display_result_values(results);
	// dequeue(results);
	// dequeue(results);
	// free(stack);
	// free(results);
	return (0);
}
