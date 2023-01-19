/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error_printing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 03:29:45 by arobu             #+#    #+#             */
/*   Updated: 2023/01/19 04:06:33 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	print_errno_message(t_pipex_errors *err_handler, char *error_type)
{
	err_handler->msg = strerror(errno);
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(error_type, 2);
	ft_putstr_fd(err_handler->msg, 2);
	ft_putstr_fd("\n", 2);
}

void	print_special_error(t_pipex_errors *err_handler, \
							char *str, char *error_type)
{
	err_handler->msg = str;
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(error_type, 2);
	ft_putstr_fd(err_handler->msg, 2);
	ft_putstr_fd("\n", 2);
}

void	print_command_not_found(t_pipex_errors *err_handler, \
								char *str, char *command)
{
	err_handler->msg = str;
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(err_handler->msg, 2);
	ft_putstr_fd("\n", 2);
}
