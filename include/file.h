/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:19:05 by arobu             #+#    #+#             */
/*   Updated: 2022/11/24 17:21:22 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

typedef struct s_file
{
	t_environment	env;
	char			*dir_path;
	char			*file_name;
}					t_file;

void	file_ctor(t_file *const me, char *dir_path, char *file_name);
int		file_exists(t_file *const me);