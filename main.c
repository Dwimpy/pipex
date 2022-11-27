/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:56:29 by arobu             #+#    #+#             */
/*   Updated: 2022/11/27 18:21:17 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"


int	main(int argc, char *argv[], char *envp[])
{	
	if (argc < 5)
	{
		ft_printf("%s", "Too few arguments, usage ./pipex file1 cmd cmd file2");
		return (0);
	}

	pipex(argc, argv, envp);

	// t_pipe pipe;
	// pid_t child, wpid;
	// int status;
	// int i ;
	// char	*binaryPath = "/bin/ls";
	// char	*test[] = { binaryPath, "-l", "-a", NULL};
	// execve("/bin/ls", test, NULL);
	return (0);
}