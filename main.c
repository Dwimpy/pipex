/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:56:29 by arobu             #+#    #+#             */
/*   Updated: 2022/11/23 22:10:34 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"


int	main(int argc, char *argv[], char *envp[])
{	
	t_path *the_path;

	the_path = newPath(envp);
	ft_printf("%s", the_path ->sh_bin_path);
	char	*test[] = {the_path -> sh_bin_path, "-c", "ls -la | grep D", NULL};
	execve(the_path -> sh_bin_path, test, NULL);
	return (0);
}