/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:59:06 by arobu             #+#    #+#             */
/*   Updated: 2022/11/24 22:03:29 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cmd.h"

static int		count_commands(int argc);
static void		create_commands(t_cmd ***me, char **argv, int command_count);
static void		get_command(t_cmd ***cmd, int command_count);

void	cmd_ctor(t_cmd **me,int argc, char **argv)
{
	int		command_count;
	
	command_count = count_commands(argc);
	*me = malloc(sizeof(t_cmd) * command_count);
	create_commands(&me, argv, command_count);
	get_command(&me, command_count);
}

static int	count_commands(int argc)
{
	return (argc - 3);
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
	int i;
	int j;
	int cmd_len;

	i = 0;
	j = -1;
	cmd_len = 0;
	while (++j < command_count)
	{
		i = 0;
		cmd_len = 0;
		while (ft_isspace3((**cmd)[j].full_cmd[i]))
			++i;
		while(ft_isalpha((**cmd)[j].full_cmd[i + cmd_len]))
			++cmd_len;
		(**cmd)[j].cmd = ft_substr((**cmd)[j].full_cmd, i, cmd_len);
	}
}

static void	get_options(t_cmd ***cmd, int command_count)
{
	
}