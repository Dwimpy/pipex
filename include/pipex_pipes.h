/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:37:57 by arobu             #+#    #+#             */
/*   Updated: 2023/01/15 17:15:31 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_PIPES_H
# define PIPEX_PIPES_H
# define READ_END 0
# define WRITE_END 0

# include <stdio.h>
# include <unistd.h>

typedef struct s_pipex_pipes
{
	int			pipe_one[2];
	int			pipe_two[2];
}				t_pipex_pipes;

int	ft_redirect_io(int input, int output);

#endif