/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:26:37 by arobu             #+#    #+#             */
/*   Updated: 2023/01/15 17:08:05 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define ERR_INCORRECT_USAGE "\033[0;91mError:\033[0;39m Incorrect use:\n./pipex \
input_file cmd1 cmd2 .. output_file\n"
# define ERR_INCORRECT_USAGE_HEREDOC "\033[0;91mError:\033[0;39m Incorrect use:\n./pipex \
here_doc LIMITER cmd1 cmd2 .. output_file\n"
# define ERR_EMPTY_ARGUMENTS "\033[0;91mError:\033[0;39m Empty command arguments\n"
# define ERR_ENOENT "\033[0;91mError:\033[0;39m No such file or directory\n"
# define ERR_EACCESS "\033[0;91mError:\033[0;39m Permission denied\n"
# define ERR_EBADF "\033[0;91mError:\033[0;39m Bad file descriptor\n"
# define ENOENT 2				/* No such file or directory */
# define EBADF 9				/* Bad file descriptor */
# define EACCES 13				/* Permission denied */
# define ECOMMAND_EX_PERISSION 126
# define ECOMMAND_NOT_FOUND	127
# include "../libft/include/ft_printf.h"
# include "pipex_file.h"
# include "pipex_scanner.h"
# include "pipex_parser.h"
# include <errno.h>

typedef struct s_pipex_input
{
	int				argc;
	char			**envp;
	char			**argv;
}				t_pipex_input;

typedef struct s_pipex_data
{
	t_pipex_file	*input_file;
	t_pipex_file	*output_file;
	int				here_doc;
	char			*limiter;
	char			**binaries;
}				t_pipex_data;

void				pipex(int argc, char **argv, char **envp);
void				pipex_input_validator(t_pipex_input *input);
void				init_t_pipex_data(t_pipex_data **data);
void				check_input_file_access(t_pipex_data *data, char *filename);
void				check_output_file_access(t_pipex_data *data,\
											char *filename);
int					check_exe_file_access(char *filepath);
void				ft_free_allocated_memory(t_pipex_data *data);
t_pipex_scanner		*scan_input(t_pipex_input *input, t_pipex_data *data);
t_pipex_input		*pipex_new_input(int argc, char **argv, char **envp);
t_pipex_data		*create_new_data(t_pipex_input *input);
t_pipex_file		*new_pipex_input_file(t_pipex_data *data, char *filename);
t_pipex_file		*new_pipex_output_file(t_pipex_data *data, char *filename);
t_pipex_file		*new_pipex_exe_file(char *filename, char *filepath);

#endif