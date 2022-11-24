/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:17:49 by arobu             #+#    #+#             */
/*   Updated: 2022/11/24 22:25:33 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/environment.h"

static void	get_path_variable(t_environment *const me);
static void	extract_paths(t_environment *const env);

void	env_ctor(t_environment *const me, char **envp)
{
	me -> envp = envp;
	get_path_variable(me);
	extract_paths(me);
}

static void	get_path_variable(t_environment *const me)
{
	
	while (me -> envp && *me -> envp)
	{
		if (!ft_strncmp("PATH=", *me -> envp, 5))
		{
			me -> bin_path_variable = ft_strdup(*me -> envp + 5);
			break ;
		}
		(*me -> envp)++;
	}
}

static void	extract_paths(t_environment *const me)
{
	me -> bin_paths = ft_split(me -> bin_path_variable, ':');
}
