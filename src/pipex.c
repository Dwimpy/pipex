/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:38:54 by arobu             #+#    #+#             */
/*   Updated: 2022/11/27 21:02:44 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../include/pipeline.h"

void	pipex(int argc, char **argv, char **envp)
{
	t_cmd 			*cmd;
	t_environment	env;
	t_pipeline		pipe;
	
	env_ctor(&env, envp);
	cmd_ctor(&cmd, env, argc, argv);
	pipeline_ctor(&pipe, cmd, argc, argv);
	
	// ft_printf("Full_cmd 0:%s\n", cmd[0].full_cmd);
	// ft_printf("Full_cmd 1:%s\n", cmd[1].full_cmd);
	ft_printf("Cmd 1:%s\n", cmd[0].exec_options[2]);
	// ft_printf("Cmd bin 0:%s\n", cmd[0].path.full_path);
	// ft_printf("Cmd bin 1:%s\n", cmd[1].path.full_path);
	// ft_printf("Pipe input file: %s\n", pipe.input.file_name);
	// ft_printf("Pipe output file: %s\n", pipe.output.file_name);



}