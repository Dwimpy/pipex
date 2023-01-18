/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:34:48 by arobu             #+#    #+#             */
/*   Updated: 2023/01/18 14:02:30 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	exit_with_error_status(t_pipex_errors *err_handler, int exit_code)
{
	err_handler->status = exit_code;
	print_errno_message(err_handler);
	ft_free_on_error(err_handler);
	exit(err_handler->status);
}

void	exit_with_err_status_custom(t_pipex_errors *err_handler, \
								char *str, int exit_code)
{
	err_handler->status = exit_code;
	print_special_error(err_handler, str);
	ft_free_on_error(err_handler);
	exit(err_handler->status);
}

void	print_errno_message(t_pipex_errors *err_handler)
{
	err_handler->msg = strerror(errno);
	ft_putstr_fd("\033[0;91mError: \033[0;39m", 2);
	ft_putstr_fd(err_handler->msg, 2);
	ft_putstr_fd("\n",2 );
}

void	print_special_error(t_pipex_errors *err_handler, \
							char *str)
{
	err_handler->msg = str;
	ft_putstr_fd("\033[0;91mError: \033[0;39m", 2);
	ft_putstr_fd(err_handler->msg, 2);
	ft_putstr_fd("\n",2 );
}

void	print_command_not_found(t_pipex_errors *err_handler, \
								char *str, char *command)
{
	err_handler->msg = str;
	ft_putstr_fd("\033[0;91mError: \033[0;39m", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(err_handler->msg, 2);
	ft_putstr_fd("\n",2 );
}

void	ft_free_on_error(t_pipex_errors *err_handler)
{
	if (err_handler->input_ptr)
		free(err_handler->input_ptr);
	if (err_handler->data_ptr)
		ft_free_allocated_memory(err_handler->data_ptr);
}