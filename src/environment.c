/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:17:49 by arobu             #+#    #+#             */
/*   Updated: 2022/12/03 18:43:58 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/environment.h"
#include <string.h>

static void	get_path_variable(t_environment *const me);
static void	extract_paths(t_environment *const env);

void	env_ctor(t_environment *const me, char **envp, int argc, char **argv)
{
	me -> envp = envp;
	me -> argc = argc;
	me -> argv = argv;
	get_path_variable(me);
	extract_paths(me);
}

static void	get_path_variable(t_environment *const me)
{
	char	*str;

	while (me -> envp && *me -> envp)
	{
		if (!ft_strncmp("PATH=", *me -> envp, 5))
		{
			str = ft_strnstr((*me -> envp), "/bin", ft_strlen(*me -> envp));
			if (str)
			{
				me -> bin_path_variable = ft_strdup(*me -> envp + 5);
				break ;
			}
		}
		(*me -> envp)++;
	}
}

static void	extract_paths(t_environment *const me)
{
	me -> bin_paths = ft_split(me -> bin_path_variable, ':');
}
