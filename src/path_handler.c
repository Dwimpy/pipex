/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:21:17 by arobu             #+#    #+#             */
/*   Updated: 2022/11/23 21:23:50 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/path_handler.h"
#include "../libft/include/libft.h"
#include "../libft/include/ft_printf.h"

static char	**get_bin_paths(char **envp)
{
	char	**bin_paths;
	
	while(*envp)
	{
		if (!ft_strncmp("PATH=", *envp, 5))
		{
			bin_paths = ft_split(*(envp) + 5, ':');
			break;
		}
		(*envp)++;
	}
	return (bin_paths);
}

static char	*get_bin_shell_path(char **bin_paths)
{
	char	*shell_path;

	while (*bin_paths)
	{
		shell_path = ft_strjoin(*bin_paths, "/sh");
		if (access(shell_path, F_OK) == 0)
		{
			return (shell_path);
			break;
		}
		(*bin_paths)++;
		free(shell_path);
	}
	return (NULL);
}

t_path *newPath(char **envp)
{
	t_path			*path;
	
	path = malloc(sizeof(t_path));
	if (!path)
		return (NULL);
	
	path -> path_fct_ptr.bin_path_fct = get_bin_paths;
	path -> path_fct_ptr.sh_bin_path_fct = get_bin_shell_path;
	path ->	bin_path = path -> path_fct_ptr.bin_path_fct(envp);
	path -> sh_bin_path = path -> path_fct_ptr.sh_bin_path_fct(path -> bin_path);
	return (path);
}