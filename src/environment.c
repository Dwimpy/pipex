/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:17:49 by arobu             #+#    #+#             */
/*   Updated: 2022/12/05 14:48:42 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/environment.h"
#include <string.h>

static void	get_path_variable(t_environment *const me);
static void	extract_paths(t_environment *const env);

void	env_ctor(t_environment *const me, char **envp, int argc, char **argv)
{
	int	i;

	i = 0;
	me -> envp = envp;
	me -> argc = argc;
	me -> argv = argv;
	me -> here_doc = 0;
	while (i < argc)
	{
		if (!strncmp(argv[i], "\0", 1))
		{
			ft_printf("%s\n", argv[i]);
			ft_printf("Empty command arguments");
			exit(1);
		}
		i++;
	}
	if (!ft_strncmp(me -> argv[1], "here_doc", 9))
	{
		me->break_kw = ft_strdup(me->argv[2]);
		me->here_doc = 1;
	}
	get_path_variable(me);
	extract_paths(me);
}

static void	get_path_variable(t_environment *const me)
{
	char	*str;
	int		i;

	i = 0;
	while (me -> envp && me -> envp[i])
	{
		if (!ft_strncmp("PATH=", me -> envp[i], 5))
		{
			str = ft_strnstr((me -> envp[i]), "/bin", ft_strlen(me -> envp[i]));
			if (str)
			{
				me -> bin_path_variable = ft_strdup(me -> envp[i] + 5);
				break ;
			}
		}
		i++;
	}
}

static void	extract_paths(t_environment *const me)
{
	me -> bin_paths = ft_split(me -> bin_path_variable, ':');
}
