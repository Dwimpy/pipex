/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_commands.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:11:23 by arobu             #+#    #+#             */
/*   Updated: 2023/01/19 04:04:24 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_COMMANDS_H
# define PIPEX_COMMANDS_H

# include "../include/pipex.h"

typedef struct s_pipex_command
{
	t_pipex_file	*file;
	char			*cmd;
	char			**options;
}				t_pipex_command;

t_pipex_command	*get_pipex_commands(t_pipex_input *pipex_input, \
								t_pipex_data	*pipex_data);
t_pipex_command	*initialize_commands(int size);
t_pipex_file	*get_command_path(char *cmd, char **binaries);

void			create_script_command(t_fsm_results **result, \
										t_pipex_command *commands, \
										t_pipex_data *data, int i);
void			create_access_command(t_fsm_results **result, \
										t_pipex_command *commands, \
										t_pipex_data *data, int i);
void			create_regular_command(t_fsm_results **result, \
										t_pipex_command *commands, \
										t_pipex_data *data, int i);
char			*create_access_option(t_fsm_results_node *word);
char			*create_regular_option(t_fsm_results_node *word);

char			**get_command_option(t_fsm_results *result);

void			parse_nodes(t_fsm_results **result, int size);
void			parse_escape(char **str);
void			ft_free_commands(t_pipex_command *commands, int size);
void			ft_free_command_options(char **options);

#endif
