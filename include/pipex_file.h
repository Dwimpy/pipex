/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_file.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:23:15 by arobu             #+#    #+#             */
/*   Updated: 2023/01/07 14:37:53 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_FILE_H
# define PIPEX_FILE_H

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

#endif