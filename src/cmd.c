/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:59:06 by arobu             #+#    #+#             */
/*   Updated: 2022/11/27 21:20:09 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cmd.h"

static void		create_commands(t_cmd ***me, char **argv, int command_count);
static void		get_command(t_cmd ***cmd, int command_count);
static void		get_options(t_cmd ***cmd, int command_count);
static void		format_options(t_cmd ***cmd);

void	cmd_ctor(t_cmd **me, t_environment env, int argc, char **argv)
{
	int		command_count;
	
	command_count = argc - 3;
	*me = malloc(sizeof(t_cmd) * command_count);
	create_commands(&me, argv, command_count);
	get_command(&me, command_count);
	get_options(&me, command_count);
	file_cmd_path(*me, env, command_count);
	format_options(&me);
}

static void create_commands(t_cmd ***me, char **argv, int command_count)
{
	int i;
	
	i = -1;
	while (++i < command_count)
		(**me)[i].full_cmd = argv[i + 2];
}

static void get_command(t_cmd ***cmd, int command_count)
{
	int 	i;
	int 	j;
	int 	cmd_len;
	char	*str;
	i = 0;
	j = -1;
	cmd_len = 0;
	while (++j < command_count)
	{
		i = 0;
		cmd_len = 0;
		str = ft_strtrim((**cmd)[j].full_cmd, "\r\v\f\t ");
		while(str[cmd_len] != '\0' && !ft_isspace3(str[cmd_len]))
			++cmd_len;
		(**cmd)[j].cmd = ft_substr(str, 0, cmd_len);
	}
}

static void	get_options(t_cmd ***cmd, int command_count)
{
	int j;
	int full_cmd_len;
	int	cmd_len;
	char	*str;
	
	j = -1;
	while (++j < command_count)
	{
		full_cmd_len = ft_strlen((**cmd)[j].full_cmd);
		cmd_len = ft_strlen((**cmd)[j].cmd);
		str = ft_strnstr((**cmd)[j].full_cmd, (**cmd)[j].cmd, full_cmd_len);
		if (!str)
			return ;
		(**cmd)[j].options = ft_substr(str, str - &str[0] + cmd_len + 1, ft_strrchr(str, '\0') - &str[0]);
	}
}

static void format_options(t_cmd ***cmd)
{
	int		i;
	int		opt_count;
	char	**cmd_opts;

	i = -1;
	opt_count = 0;
	cmd_opts = pipex_split((**cmd)->options, ' ');
	while (cmd_opts[opt_count] != NULL)
		opt_count++;
	(**cmd)->exec_options = malloc(sizeof(char *) * (opt_count + 2));
	while (++i < opt_count)
	{
		(**cmd)->exec_options[0] = (**cmd)->path.full_path;
		(**cmd)->exec_options[i + 1] = ft_strdup(cmd_opts[i]);
	}
}