/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_handler.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:41:05 by arobu             #+#    #+#             */
/*   Updated: 2022/11/23 17:51:57 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_path
{
	char	**(*bin_paths)();
	//char	(*cmd_absolute_path)();
}				t_path;

char	**get_bin_paths(char **envp);
t_path	*newPath(char **envp, char *cmd);
