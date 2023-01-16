/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:37:57 by arobu             #+#    #+#             */
/*   Updated: 2023/01/16 21:57:45 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_PIPES_H
# define PIPEX_PIPES_H
# define READ_END 0
# define WRITE_END 0

# include <stdio.h>
# include <unistd.h>
# include "pipex.h"

typedef struct s_pipex_pipes
{
	int			fd[2];
}				t_pipex_pipes;

t_pipex_pipes	*create_pipes(int pipes_number);

int	ft_redirect_pipes(t_pipex_pipes **pipes, t_pipex_data *data, \
						int child_number);
int				ft_redirect_io(int input, int output);
void			close_pipe_fds(t_pipex_pipes *pipes, int pipes_number);
void			pipe_the_pipes(t_pipex_pipes **pipes, int pipes_number);
#endif