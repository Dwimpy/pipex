/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:38:54 by arobu             #+#    #+#             */
/*   Updated: 2022/12/05 15:22:47 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../include/pipeline.h"
#include "../include/pipex_split.h"

void	free_memory(t_cmd *cmd, t_environment *env, t_pipeline *pipes)
{
	int	i;

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

	if (argc < 5)
	{
		ft_printf("%s", \
		"Incorrect usage. Use ./pipex input_file cmd1 cmd2 output_file");
		exit(1);
	}
	if (!ft_strncmp(argv[1], "here_doc", 9) && argc < 6)
	{
		ft_printf("%s", \
		"Incorrect usage. Use ./pipex here_doc limiter cmd1 cmd2 output_file");
	}
	env_ctor(&env, envp, argc, argv);
	cmd_ctor(&cmd, env, argc);
	pipeline_ctor(&pipeline, cmd, &env);
	if (env.here_doc)
		unlink("here_doc.tmp");
	free_memory(cmd, &env, &pipeline);
}
