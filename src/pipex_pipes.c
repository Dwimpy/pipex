/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:40:37 by arobu             #+#    #+#             */
/*   Updated: 2023/01/20 15:36:34 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_pipes.h"
#include "../include/pipex.h"
#include "../include/get_next_line.h"

static int	redirect_first_child(t_pipex_pipeline **pipeline, \
						t_pipex_data *data, int child);
static int	redirect_other_children(t_pipex_pipeline **pipeline, \
						t_pipex_data *data, int child);
static int	redirect_last_child(t_pipex_pipeline **pipeline, \
						t_pipex_data *data, int child);

int	ft_redirect_io(int input, int output)
{
	if (dup2(input, STDIN_FILENO) == -1)
		return (-1);
	if (dup2(output, STDOUT_FILENO) == -1)
		return (-1);
	return (0);
}

int	ft_redirect_pipes(t_pipex_pipeline **pipeline, t_pipex_data *data, \
					t_pipex_errors *err_handler, int command_number)
{
	int				is_success;
	int				fd;
	int				child;
	t_pipex_pipes	*pipes;

	child = (**pipeline).child;
	pipes = (*pipeline)->pipe;
	is_success = 0;
	if (child == 0)
		is_success = redirect_first_child(pipeline, data, child);
	else if (child == command_number - 1)
		is_success = redirect_last_child(pipeline, data, child);
	else
		is_success = redirect_other_children(pipeline, data, child);
	return (is_success);
}

static int	redirect_first_child(t_pipex_pipeline **pipeline, \
						t_pipex_data *data, int child)
{
	t_pipex_pipes	*pipes;
	int				is_success;

	pipes = (*pipeline)->pipe;
	is_success = 0;
	(*pipeline)->file_fd_input = open(data->input_file->filename, O_RDONLY);
	is_success = ft_redirect_io((**pipeline).file_fd_input, \
								pipes[child].fd[WRITE_END]);
	close((*pipeline)->file_fd_input);
	return (is_success);
}

static int	redirect_last_child(t_pipex_pipeline **pipeline, \
						t_pipex_data *data, int child)
{
	t_pipex_pipes	*pipes;
	int				is_success;

	pipes = (*pipeline)->pipe;
	is_success = 0;
	if (data->here_doc == 0)
		(*pipeline)->file_fd_output = \
			open(data->output_file->filename, O_WRONLY, 0644);
	else
		(*pipeline)->file_fd_output = \
			open(data->output_file->filename, O_WRONLY | O_APPEND, 0644);
	is_success = ft_redirect_io(pipes[child - 1].fd[READ_END], \
								(**pipeline).file_fd_output);
	close((*pipeline)->file_fd_output);
	return (is_success);
}

static int	redirect_other_children(t_pipex_pipeline **pipeline, \
						t_pipex_data *data, int child)
{
	t_pipex_pipes	*pipes;
	int				is_success;

	pipes = (*pipeline)->pipe;
	is_success = 0;
	is_success = ft_redirect_io(pipes[child - 1].fd[READ_END], \
							pipes[child].fd[WRITE_END]);
	return (is_success);
}
