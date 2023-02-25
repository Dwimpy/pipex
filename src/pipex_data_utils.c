/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_data_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:03:42 by arobu             #+#    #+#             */
/*   Updated: 2023/02/25 14:30:13 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_free_binaries(t_pipex_data *data);

void	init_t_pipex_data(t_pipex_data **data)
{
	(**data).command_number = 0;
	(*data)->here_doc = 0;
	(*data)->binaries = NULL;
	(*data)->input_file = NULL;
	(*data)->output_file = NULL;
	(*data)->limiter = NULL;
}

void	ft_free_allocated_memory(t_pipex_data *data)
{
	if (data->input_file)
		ft_free_file(data->input_file);
	if (data->output_file)
		ft_free_file(data->output_file);
	if (data->limiter)
		free(data->limiter);
	if (data->binaries)
		ft_free_binaries(data);
	free(data);
}

static void	ft_free_binaries(t_pipex_data *data)
{
	int	i;

	i = 0;
	while (data->binaries[i] != NULL)
	{
		free(data->binaries[i]);
		i++;
	}
	free(data->binaries);
}
