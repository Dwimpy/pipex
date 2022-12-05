/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:21:17 by arobu             #+#    #+#             */
/*   Updated: 2022/12/05 15:22:32 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/ft_printf.h"
#include "../include/path.h"

void	cmd_file_exists(t_cmd *cmd, t_environment env);
void	get_cmd_bin_path(t_cmd *cmd, t_environment env, int command_count);
void	get_paths(t_cmd **cmd, char *file_cmd_path, char *full_path);
void	get_paths_access_failed(t_cmd **cmd);

void	file_cmd_path( t_cmd *cmd, t_environment env, int command_count)
{
	get_cmd_bin_path(cmd, env, command_count);
}

void	cmd_file_exists(t_cmd *cmd, t_environment env)
{
	char	*file_cmd_path;
	char	*full_path;
	int		i;

	i = 0;
	file_cmd_path = ft_strjoin("/", cmd->cmd);
	(*cmd).path.full_path = NULL;
	while ((env.bin_paths[i]) != NULL)
	{
		full_path = ft_strjoin((env.bin_paths[i]), file_cmd_path);
		if (access(full_path, F_OK) == 0)
		{
			(*cmd).path.dir_path = ft_strdup(env.bin_paths[i]);
			get_paths(&cmd, file_cmd_path, full_path);
			return ;
		}
		free(full_path);
		i++;
	}
	if ((*cmd).path.full_path == NULL)
		get_paths_access_failed(&cmd);
	free(file_cmd_path);
}

void	get_paths(t_cmd **cmd, char *file_cmd_path, char *full_path)
{
	(**cmd).path.file_name = ft_strdup(file_cmd_path);
	(**cmd).path.full_path = ft_strdup(full_path);
	(**cmd).cmd_exists = 1;
	free(file_cmd_path);
	free(full_path);
}

void	get_paths_access_failed(t_cmd **cmd)
{
	(**cmd).cmd_exists = 0;
	(*cmd)->path.full_path = ft_strdup("");
	(*cmd)->path.file_name = ft_strdup("");
	(*cmd)->path.dir_path = ft_strdup("");
}

void	get_cmd_bin_path(t_cmd *cmd, t_environment env, int command_count)
{
	int	i;

	i = -1;
	while (++i < command_count)
	{
		cmd_file_exists(&cmd[i], env);
		if (cmd[i].path.full_path[0] == '\0')
		{
			ft_putstr_fd("pipex: command not found: ", 2);
			ft_putstr_fd(cmd[i].cmd, 2);
			ft_putchar_fd('\n', 2);
		}
	}
}
