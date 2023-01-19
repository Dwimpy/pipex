/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:34:48 by arobu             #+#    #+#             */
/*   Updated: 2023/01/19 03:30:06 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	exit_with_error_status(t_pipex_errors *err_handler, \
							char *error_type, int exit_code)
{
	err_handler->status = exit_code;
	print_errno_message(err_handler, error_type);
	ft_free_on_error(err_handler);
	exit(err_handler->status);
}

void	exit_with_err_status_custom(t_pipex_errors *err_handler, \
								char *str, char *err_type, int exit_code)
{
	err_handler->status = exit_code;
	print_special_error(err_handler, str, err_type);
	ft_free_on_error(err_handler);
	exit(err_handler->status);
}

void	ft_free_on_error(t_pipex_errors *err_handler)
{
	if (err_handler->input_ptr)
		free(err_handler->input_ptr);
	if (err_handler->data_ptr)
		ft_free_allocated_memory(err_handler->data_ptr);
}
