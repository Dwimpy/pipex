/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:01:38 by arobu             #+#    #+#             */
/*   Updated: 2022/12/05 22:34:54 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/file.h"
#include <stdio.h>

int	open_input_file(t_file file, t_environment env)
{
	int	fd;

	if (env.here_doc == 1)
		get_heredoc_input(env, file);
	fd = open(file.file_name, O_RDONLY);
	if (fd < 0)
	{
		perror("Input file");
	}
	return (fd);
}

void	get_heredoc_input(t_environment env, t_file file)
{
	char	*line;
	int		limiter_len;
	int		fd;

	fd = open(file.file_name, O_RDWR | O_APPEND | O_CREAT, 0644);
	limiter_len = ft_strlen(env.break_kw);
	while (1)
	{
		ft_putstr_fd("here_doc > ", 1);
		line = get_next_line(STDIN_FILENO);
		if (!ft_strncmp(line, env.break_kw, limiter_len))
		{
			free(line);
			close(fd);
			break ;
		}
		else
			ft_putstr_fd(line, fd);
		free(line);
	}
}

int	open_output_file(t_file file, t_environment env)
{
	int	fd;

	if (env.here_doc == 0)
		fd = open(file.file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(file.file_name, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
	{
		perror("Output file");
		exit(errno);
	}
	return (fd);
}
