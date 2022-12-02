/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:56:29 by arobu             #+#    #+#             */
/*   Updated: 2022/12/02 13:58:42 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"
#include "include/pipex_split.h"

int	main(int argc, char *argv[], char *envp[])
{	

	if (argc < 5)
	{
		ft_printf("%s", "Too few arguments, usage ./pipex file1 cmd cmd file2");
	 return (0);
	}

	
	pipex(argc, argv, envp);

	// char str[100] = "file1 ls -l -a | awk -F '{print $1}' | sed -n 's/.*/ /g' file2";
	// char **str_split = pipex_split(str, ' ');
	// char **split_split = ft_split(str, ' ');
	// int i;

	// i = -1;
	// while (str_split[++i] != NULL)
	// 	ft_printf("Pipex Split: %s\n", str_split[i]);
	// i = -1;
	// while (split_split[++i] != NULL)
	// 	ft_printf("Ft Split: %s\n", split_split[i]);
	
	//ft_printf("%s\n", ft_split(str, ' ')[5]);
	// t_pipe pipe;
	// pid_t child, wpid;
	// int status;
	// int i ;
	// char	*binaryPath = "/bin/ls";
	// char	*test[] = { binaryPath, "-l", "-a", NULL};
	// execve("/bin/ls", test, NULL);
	return (0);
}