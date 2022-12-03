/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:59:06 by arobu             #+#    #+#             */
/*   Updated: 2022/12/03 16:17:08 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cmd.h"
#include "../include/pipex_split.h"

static void		create_commands(t_cmd ***me, char **argv, int command_count);
static void		get_command(t_cmd ***cmd, int command_count);
static void		get_options(t_cmd ***cmd, int command_count);
static void format_options(t_cmd ***cmd, int command_count);

void	cmd_ctor(t_cmd **me, t_environment env, int argc, char **argv)
{

	*me = malloc(sizeof(t_cmd) * (argc - 3));
	(*me)->command_count = (argc - 3);
	create_commands(&me, argv, (*me)->command_count);
	get_command(&me, (*me)->command_count);
	get_options(&me, (*me)->command_count);
	file_cmd_path(*me, env, (*me)->command_count);
	format_options(&me, (*me)->command_count);
}

static void	create_commands(t_cmd ***me, char **argv, int command_count)
{
	int	i;

	i = -1;
	while (++i < command_count)
		(**me)[i].full_cmd = argv[i + 2];
}

static void	get_command(t_cmd ***cmd, int command_count)
{
	int		j;
	int		cmd_len;
	char	*str;

	j = -1;
	cmd_len = 0;
	while (++j < command_count)
	{
		cmd_len = 0;
		str = ft_strtrim((**cmd)[j].full_cmd, "\r\v\f\t ");
		while (str[cmd_len] != '\0' && !ft_isspace3(str[cmd_len]))
			++cmd_len;
		(**cmd)[j].cmd = ft_substr(str, 0, cmd_len);
		free(str);
	}
}

static void	get_options(t_cmd ***cmd, int command_count)
{
	int		j;
	int		full_cmd_len;
	int		cmd_len;
	char	*str;

	j = -1;
	while (++j < command_count)
	{
		full_cmd_len = ft_strlen((**cmd)[j].full_cmd);
		cmd_len = ft_strlen((**cmd)[j].cmd);
		str = ft_strnstr((**cmd)[j].full_cmd, (**cmd)[j].cmd, full_cmd_len);
		if (!str)
			return ;
		(**cmd)[j].options = ft_substr(str, \
		str - &str[0] + cmd_len + 1, ft_strrchr(str, '\0') - &str[0]);
	}
}

static void format_options(t_cmd ***cmd, int command_count)
{
	int		i;
	
	i = -1;
	while(++i < command_count)
	{
		(**cmd)[i].exec_options = pipex_split((**cmd)[i].full_cmd, ' ');
		free((**cmd)[i].exec_options[0]);
		(**cmd)[i].exec_options[0] = ft_strdup((**cmd)[i].path.full_path);
	}
}