/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:32:53 by arobu             #+#    #+#             */
/*   Updated: 2023/01/07 22:53:14 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	pipex(int argc, char **argv, char **envp)
{
	t_pipex_input	*pipex_input;
	t_pipex_data	*pipex_data;
	t_pipex_parser	*parser;
	t_parser_input	*parser_input;
	int				i;

	parser = create_parser();
	pipex_input = pipex_new_input(argc, argv, envp);
	pipex_input_validator(pipex_input);
	pipex_data = create_new_data(pipex_input);
	parser_input = create_input(pipex_input->argv[2]);
	i = 0;
	// while (pipex_data->binaries[i] != NULL)
	// {
	// 	ft_printf("%s\n", pipex_data->binaries[i]);
	// 	i++;
	// }
	// enqueue(parser, 'a');
	// enqueue(parser, 'b');
	run_parser(parser, parser_input);
	display_node_values(parser);
}