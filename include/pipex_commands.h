/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_commands.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:11:23 by arobu             #+#    #+#             */
/*   Updated: 2023/01/08 22:14:15 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_COMMANDS_H
# define PIPEX_COMMANDS_H

# include "pipex_file.h"

typedef struct s_pipex_command
{
	t_pipex_file	*path;
	char			*cmd;
	char			*option;	
}				t_pipex_command;

#endif
