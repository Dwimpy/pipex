/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:32:53 by arobu             #+#    #+#             */
/*   Updated: 2023/01/13 16:58:35 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../include/pipex_scanner.h"
#include "../include/pipex_state_machine.h"

void	ft_free_pipex_memory(t_pipex_data *data, \
							t_pipex_input *input, t_pipex_scanner *scanner);

void	pipex(int argc, char **argv, char **envp)
{
	t_pipex_input		*pipex_input;
	t_pipex_data		*pipex_data;
	t_pipex_scanner		*scanner;
	int					i;

	pipex_input = pipex_new_input(argc, argv, envp);
	pipex_input_validator(pipex_input);
	pipex_data = create_new_data(pipex_input);
	scanner = scan_input(pipex_input, pipex_data);
	display_scanner_results(scanner);
	ft_free_pipex_memory(pipex_data, pipex_input, scanner);
}

void	ft_free_pipex_memory(t_pipex_data *data, \
							t_pipex_input *input, t_pipex_scanner *scanner)
{
	ft_free_allocated_memory(data);
	ft_free_scanner(scanner);
	free(input);
}