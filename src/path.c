/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:21:17 by arobu             #+#    #+#             */
/*   Updated: 2022/12/01 04:02:03 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/ft_printf.h"
#include "../include/path.h"

void	cmd_file_exists(t_cmd *cmd, t_environment env);
void	get_cmd_bin_path(t_cmd *cmd, t_environment env, int command_count);

void	file_cmd_path( t_cmd *cmd, t_environment env, int command_count)
{
	if (!strncmp(cmd->cmd, "\0", 1))
	{
		ft_printf("Program exited. Empty command arguments");
		exit(-1);
	}
	get_cmd_bin_path(cmd, env, command_count);
}

void	cmd_file_exists(t_cmd *cmd, t_environment env)
{
	char	*file_cmd_path;
	char	*full_path;
	int		i;

	i = 0;
	file_cmd_path = ft_strjoin("/", cmd->cmd);
	while ((env.bin_paths[i]) != NULL)
	{
		full_path = ft_strjoin((env.bin_paths[i]), file_cmd_path);
		if (access(full_path, F_OK) == 0)
		{
			(*cmd).path.dir_path = ft_strdup(env.bin_paths[i]);
			(*cmd).path.file_name = ft_strdup(file_cmd_path);
			(*cmd).path.full_path = ft_strdup(full_path);
			free(file_cmd_path);
			free(full_path);
			return ;
		}
		free(full_path);
		i++;
	}
	free(file_cmd_path);
}

void	get_cmd_bin_path(t_cmd *cmd, t_environment env, int command_count)
{
	int	i;

	i = -1;
	while (++i < command_count)
	{
		cmd_file_exists(&cmd[i], env);
		if (cmd[i].path.full_path == NULL)
		{	
			ft_printf("Command does not exist: %s\nProgram exited with \
			error code %d: %s", cmd[i].cmd, errno, strerror(errno));
			exit(-1);
		}
	}
}
