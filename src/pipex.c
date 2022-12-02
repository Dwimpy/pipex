/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:38:54 by arobu             #+#    #+#             */
/*   Updated: 2022/12/02 22:57:04 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../include/pipeline.h"

void	pipex(int argc, char **argv, char **envp)
{
	t_cmd			*cmd;
	t_environment	env;
	t_pipeline		pipeline;
	int				i;

	i = 0;
	env_ctor(&env, envp);
	cmd_ctor(&cmd, env, argc, argv);
	pipeline_ctor(&pipeline, cmd, argc, argv);
}

	// int fdd;
	// fdd = open("file2", O_WRONLY);

	// dup2(pipeline.file_fd_input, STDIN_FILENO);
	// close(fdd);
	// char	*binaryPath = "/bin/cat";
	// char	*test[] = {binaryPath, "-e", NULL};
	// execve("/bin/cat", test, NULL);
	// ft_printf("Full_cmd 0:%s\n", cmd[0].full_cmd);
	// ft_printf("Full_cmd 1:%s\n", cmd[1].full_cmd);
	// while (cmd[1].exec_options[i] != NULL)
	// {
	//  	ft_printf("Cmd 1:%s\n", cmd[1].exec_options[i]);
	// 	i++;
	// }

	// dup2(stdout, STDOUT_FILENO);
	// ft_printf("%s", buffer);
	// ft_printf("Cmd bin 0:%s\n", cmd[0].path.full_path);
	// ft_printf("Cmd bin 1:%s\n", cmd[1].path.full_path);
	// ft_printf("Pipe input file: %s\n", pipe.input.file_name);
	// ft_printf("Pipe output file: %s\n", pipe.output.file_name);