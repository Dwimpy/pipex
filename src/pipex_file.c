/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:24:49 by arobu             #+#    #+#             */
/*   Updated: 2023/02/25 14:31:09 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_file.h"
#include "pipex.h"

t_pipex_file	*new_pipex_input_file(char *filename)
{
	t_pipex_file	*file;

	file = (t_pipex_file *)malloc(sizeof(t_pipex_file));
	if (!file)
		return (NULL);
	file->filename = ft_strdup(filename);
	file->filepath = NULL;
	file->file_type = IO_FILE;
	return (file);
}

t_pipex_file	*new_pipex_heredoc_file(char *limiter)
{
	t_pipex_file	*heredoc;
	char			*stdin_line;
	int				fd;

	fd = open("here_doc.tmp", O_RDWR | O_TRUNC | O_CREAT, 0644);
	heredoc = new_pipex_input_file("here_doc.tmp");
	while (1)
	{
		ft_putstr_fd("here_doc > ", 1);
		stdin_line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(stdin_line, limiter, \
			ft_strlen(stdin_line) - 1) == 0 && \
			ft_strlen(limiter) == ft_strlen(stdin_line) - 1)
		{
			close(fd);
			free(stdin_line);
			break ;
		}
		ft_putstr_fd(stdin_line, fd);
		free(stdin_line);
	}
	return (heredoc);
}

t_pipex_file	*new_pipex_output_file(char *filename)
{
	t_pipex_file	*file;

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
	if (filename)
		file->filename = ft_strdup(filename);
	else
		file->filename = NULL;
	if (filepath)
		file->filepath = ft_strdup(filepath);
	else
		file->filepath = NULL;
	file->file_type = EXE_FILE;
	return (file);
}
