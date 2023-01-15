/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_commands.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:11:23 by arobu             #+#    #+#             */
/*   Updated: 2023/01/15 15:30:10 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_COMMANDS_H
# define PIPEX_COMMANDS_H

# include "../include/pipex.h"

typedef struct s_pipex_command
{
	t_pipex_file	*file;
	char			*cmd;
	char			*option;	
}				t_pipex_command;

t_pipex_command	*get_pipex_commands(t_pipex_input *pipex_input, \
								t_pipex_data	*pipex_data);
void			parse_nodes(t_fsm_results **result, int size);
void			parse_escape(char **str);
void			ft_free_commands(t_pipex_command *commands, int size);

#endif
