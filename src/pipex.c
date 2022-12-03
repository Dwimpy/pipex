/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:38:54 by arobu             #+#    #+#             */
/*   Updated: 2022/12/03 16:41:31 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../include/pipeline.h"
#include "../include/pipex_split.h"

void	free_memory(t_cmd *cmd, t_environment *env, t_pipeline *pipes)
{
	int i;

	i = 0;
	free_words_split(env->bin_paths);
	free(env->bin_path_variable);
	while (i < cmd -> command_count)
	{
		free_words_split(cmd[i].exec_options);
		free(cmd[i].options);
		free(cmd[i].path.dir_path);
		free(cmd[i].path.file_name);
		free(cmd[i].path.full_path);
		free(cmd[i].cmd);
		i++;
	}
	free(cmd);
	free(pipes->input.file_name);
	free(pipes->output.file_name);
	free(pipes->pipe);

}

void	pipex(int argc, char **argv, char **envp)
{
	t_cmd			*cmd;
	t_environment	env;
	t_pipeline		pipeline;

	env_ctor(&env, envp);
	cmd_ctor(&cmd, env, argc, argv);
	pipeline_ctor(&pipeline, cmd, argc, argv);
	free_memory(cmd, &env, &pipeline);


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


	// dup2(stdout, STDOUT_FILENO);
	// ft_printf("%s", buffer);
	// ft_printf("Cmd bin 0:%s\n", cmd[0].path.full_path);
	// ft_printf("Cmd bin 1:%s\n", cmd[1].path.full_path);
	// ft_printf("Pipe input file: %s\n", pipe.input.file_name);
	// ft_printf("Pipe output file: %s\n", pipe.output.file_name);