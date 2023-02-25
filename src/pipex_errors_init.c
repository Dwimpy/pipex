/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:18:03 by arobu             #+#    #+#             */
/*   Updated: 2023/02/25 14:31:09 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_error_handler(t_pipex_errors *err_handler)
{	
	err_handler->data_ptr = NULL;
	err_handler->input_ptr = NULL;
	err_handler->msg = NULL;
	err_handler->status = 0;
	err_handler->pid_exit_code = 0;
}
