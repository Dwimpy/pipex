/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:26:37 by arobu             #+#    #+#             */
/*   Updated: 2023/01/18 14:02:59 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define ERR_INCORRECT_USAGE "Incorrect use:\n./pipex \
input_file cmd1 cmd2 .. output_file"
# define ERR_INCORRECT_USAGE_HEREDOC "Incorrect use:\n./pipex \
here_doc LIMITER cmd1 cmd2 .. output_file"
# define ERR_EMPTY_ARGUMENTS "Empty command arguments"
# define ERR_ENOENT "No such file or directory"
# define ERR_EACCESS "Permission denied"
# define ERR_EBADF "Bad file descriptor"
# define ENOENT 2				/* No such file or directory */
# define EBADF 9				/* Bad file descriptor */
# define EACCES 13				/* Permission denied */
# define ECOMMAND_NOT_FOUND_MSG "Command not found!"
# define ECOMMAND_EX_PERISSION 126
# define ECOMMAND_NOT_FOUND	127
# include "../libft/include/ft_printf.h"
# include "pipex_file.h"
# include "pipex_scanner.h"
# include "pipex_parser.h"
# include <errno.h>
# include <string.h>

typedef struct s_pipex_data		t_pipex_data;
typedef struct s_pipex_input	t_pipex_input;
typedef struct s_pipex_errors
{
	int				status;
	pid_t			pid_exit_code;
	char			*msg;
	t_pipex_data	*data_ptr;
	t_pipex_input	*input_ptr;
}				t_pipex_errors;

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
	int				command_number;
	int				here_doc;
	char			*limiter;
	char			**binaries;
}				t_pipex_data;

void				pipex(int argc, char **argv, char **envp);
void				pipex_input_validator(t_pipex_input *input, \
										t_pipex_errors *err_handler);
void				init_t_pipex_data(t_pipex_data **data);
int					check_input_file_access(t_pipex_data *data, t_pipex_errors *err_handler);
int					check_output_file_access(t_pipex_data *data, t_pipex_errors *err_handler);

int					check_exe_file_access(char *filepath);
void				ft_free_allocated_memory(t_pipex_data *data);
t_pipex_scanner		*scan_input(t_pipex_input *input, t_pipex_data *data);
t_pipex_input		*pipex_new_input(int argc, char **argv, \
									char **envp, t_pipex_errors *err_handler);
t_pipex_data		*create_new_data(t_pipex_input *input, \
									t_pipex_errors *err_handler);
t_pipex_file		*new_pipex_input_file(t_pipex_data *data, char *filename, \
									t_pipex_errors *err_handler);
t_pipex_file		*new_pipex_output_file(t_pipex_data *data, char *filename, \
									t_pipex_errors *err_handler);
t_pipex_file		*new_pipex_exe_file(char *filename, char *filepath);

void				init_error_handler(t_pipex_errors *err_handler);
void				exit_with_error_status(t_pipex_errors *err_handler, \
									int exit_code);
void				exit_with_err_status_custom(t_pipex_errors *err_handler, \
									char *str, int exit_code);
void				print_errno_message(t_pipex_errors *err_handler);
void				print_special_error(t_pipex_errors *err_handler, \
									char *str);
void				print_command_not_found(t_pipex_errors *err_handler, \
									char *str, char *command);
void				ft_free_on_error(t_pipex_errors *err_handler);

#endif