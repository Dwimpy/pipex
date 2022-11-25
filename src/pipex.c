/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:38:54 by arobu             #+#    #+#             */
/*   Updated: 2022/11/25 21:06:56 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	pipex(int argc, char **argv, char **envp)
{
	t_cmd *cmd;
	t_environment env;
	
	
	env_ctor(&env, envp);
	cmd_ctor(&cmd, env, argc, argv);
	

	ft_printf("Full_cmd 0:%s\n", cmd[0].full_cmd);
	ft_printf("Full_cmd 1:%s\n", cmd[1].full_cmd);
	ft_printf("Cmd 1:%s\n", cmd[1].cmd);
	ft_printf("Cmd 1 options:%s\n", cmd[1].options);
	ft_printf("Cmd bin 0:%s\n", cmd[0].file.full_path);
	ft_printf("Cmd bin 1:%s\n", cmd[1].file.full_path);


}