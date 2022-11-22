/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:56:29 by arobu             #+#    #+#             */
/*   Updated: 2022/11/22 21:41:54 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char *sal;
	char	*path = "/bin/date";
	char *test1[] = {path, NULL};
	char	buffer[1024];
	int fd[2];
	int n;
	pid_t child;
	pipe(fd);
	
	child = fork();
	buffer = malloc(sizeof(char) * 20);
	while (*envp)
	{
		if (!ft_strncmp("PATH=", *envp, 5))
			break;
		(*envp)++;
	}
	
	if (child == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		execve(path, test1, NULL);
	}
	else
	{
		close(fd[1]);
		n = read(fd[0], buffer, 1024);
		ft_printf("%s", buffer);
	}

	return (0);
}