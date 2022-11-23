/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:21:17 by arobu             #+#    #+#             */
/*   Updated: 2022/11/23 18:04:50 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/path_handler.h"
#include "../libft/include/libft.h"

char	**get_bin_paths(char **envp)
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

t_path *newPath(char **envp, char *cmd)
{
	t_path *path;

	path = malloc(sizeof(t_path));
	if (!path)
		return (NULL);
	
	path -> bin_paths = get_bin_paths;
	
	return (path);
}