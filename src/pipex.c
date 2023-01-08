/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:32:53 by arobu             #+#    #+#             */
/*   Updated: 2023/01/08 22:36:51 by arobu            ###   ########.fr       */
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
	parser_input = create_input(pipex_input->argv[3]);
	run_parser(parser, parser->state_tracker, parser_input);
	display_node_values(parser);
}