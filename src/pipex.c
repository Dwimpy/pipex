/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:38:54 by arobu             #+#    #+#             */
/*   Updated: 2022/11/24 22:02:18 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	pipex(int argc, char **argv, char **envp)
{
	t_cmd *cmd;
	t_environment env;
	
	
	env_ctor(&env, envp);
	cmd_ctor(&cmd, argc, argv);
	
	ft_printf("%s\n", cmd[0].full_cmd);
	ft_printf("%s\n", cmd[1].full_cmd);
	ft_printf("%s\n", cmd[1].cmd);

}