/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:24:49 by arobu             #+#    #+#             */
/*   Updated: 2023/01/18 13:21:16 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_file.h"
#include "../include/pipex.h"

t_pipex_file	*new_pipex_input_file(t_pipex_data *data, char *filename, \
									t_pipex_errors *err_handler)
{
	t_pipex_file	*file;

	//check_input_file_access(data, filename, err_handler);
	file = (t_pipex_file *)malloc(sizeof(t_pipex_file));
	if (!file)
		return (NULL);
	file->filename = ft_strdup(filename);
	file->filepath = NULL;
	file->file_type = IO_FILE;
	return (file);
}

t_pipex_file	*new_pipex_output_file(t_pipex_data *data, char *filename, \
									t_pipex_errors *err_handler)
{
	t_pipex_file	*file;

	//check_output_file_access(data, err_handler);
	file = (t_pipex_file *)malloc(sizeof(t_pipex_file));
	if (!file)
		return (NULL);
	file->filename = ft_strdup(filename);
	file->filepath = NULL;
	file->file_type = IO_FILE;
	return (file);
}

t_pipex_file	*new_pipex_exe_file(char *filename, char *filepath)
{
	t_pipex_file	*file;

	file = (t_pipex_file *)malloc(sizeof(t_pipex_file));
	if (!file)
		return (NULL);
	file->filename = ft_strdup(filename);
	file->filepath = ft_strdup(filepath);
	file->file_type = EXE_FILE;
	return (file);
}
