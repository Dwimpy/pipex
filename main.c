/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:56:29 by arobu             #+#    #+#             */
/*   Updated: 2023/01/20 13:12:59 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{	
	const char	*envps[2] = \
	{"PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin", 0};

	if (envp[0] != NULL)
		pipex(argc, argv, envp);
	else
		pipex(argc, argv, (char **)envps);
	return (0);
}
