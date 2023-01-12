/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_file.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:23:15 by arobu             #+#    #+#             */
/*   Updated: 2023/01/11 15:18:06 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_FILE_H
# define PIPEX_FILE_H
#include <stdlib.h>

typedef enum e_file_type
{
	IO_FILE = 0,
	EXE_FILE = 1
}			t_file_type;

typedef struct s_pipex_file
{
	char		*filename;
	char		*filepath;
	t_file_type	file_type;
}				t_pipex_file;

void	ft_free_file(t_pipex_file *file);

#endif