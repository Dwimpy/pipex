/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execution_child_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:28:10 by arobu             #+#    #+#             */
/*   Updated: 2023/01/20 15:06:19 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_pipes.h"
#include "../include/pipex.h"

void	run_child_fd_checker(t_pipex_data *data, t_pipex_errors *err_handler, \
							t_pipex_pipeline *pipeline)
{
	if (pipeline->child == 0)
		if (check_input_file_access(data, err_handler) < 0)
			exit(EXIT_FAILURE);
	if (pipeline->child == data->command_number - 1)
		if (check_output_file_access(data, err_handler) < 0)
			exit(EXIT_FAILURE);
}
