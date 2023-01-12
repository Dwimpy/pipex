/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_file_memory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:15:30 by arobu             #+#    #+#             */
/*   Updated: 2023/01/11 15:19:03 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_file.h"

void	ft_free_file(t_pipex_file *file)
{
	free(file->filename);
	if (file->filepath)
		free(file->filepath);
	free(file);
}