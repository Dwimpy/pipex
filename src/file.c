/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:21:17 by arobu             #+#    #+#             */
/*   Updated: 2022/11/24 17:26:32 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/ft_printf.h"
#include "../include/file.h"


void	file_ctor(t_file *const me, char *dir_path, char *file_name)
{
	me -> dir_path = dir_path;
	me -> file_name = file_name;
}

int		file_exists(t_file *const me)
{
	char	*dir_path_with_separator;
	char	*file_full_path;
	
	dir_path_with_separator = ft_strjoin(me -> dir_path, "/");
	file_full_path = ft_strjoin(dir_path_with_separator, me -> file_name);
	
	if (access(file_full_path, F_OK) == 0)
	{
		free(dir_path_with_separator);
		return (0);
	}
	else
		return (1);
}