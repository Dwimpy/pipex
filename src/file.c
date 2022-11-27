/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:01:38 by arobu             #+#    #+#             */
/*   Updated: 2022/11/27 18:19:24 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/file.h"
# include <stdio.h>

int	open_input_file(t_file file)
{
	int	fd;

	fd = open(file.file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Program exit with error code %d: %s", errno, strerror(errno));
		exit (1);
	}
	return (fd);
}

int	open_output_file(t_file file)
{
	int	fd;

	fd = open(file.file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Program exit with error code %d: %s", errno, strerror(errno));
		exit (1);
	}
	return (fd);
}
