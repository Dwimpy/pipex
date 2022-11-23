/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:56:29 by arobu             #+#    #+#             */
/*   Updated: 2022/11/23 18:09:19 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"


int	main(int argc, char *argv[], char *envp[])
{
	
	

	char *sal;
	char	*path = "/bin/date";
	char *test1[] = {path, NULL};
	char	*buffer;
	int fd[2];
	int n;
	pid_t child;
	pipe(fd);
	
	t_path *the_path;

	the_path = newPath(envp, "ls");
	int i = 0;
	while (the_path -> bin_paths(envp)[i] != NULL)
	{
		ft_printf("%s\n", the_path -> bin_paths(envp)[i]);
		i++;
	}
	buffer = malloc(sizeof(char) * 20);

	return (0);
}