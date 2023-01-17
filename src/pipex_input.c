/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:25:21 by arobu             #+#    #+#             */
/*   Updated: 2023/01/17 15:44:59 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	check_arguments(t_pipex_input *input, t_pipex_errors *err_handler);

t_pipex_input	*pipex_new_input(int argc, char **argv, \
						char **envp, t_pipex_errors *err_handler)
{
	t_pipex_input	*input;

	if (argc == 1)
		exit(EXIT_FAILURE);
	input = (t_pipex_input *)malloc(sizeof(t_pipex_input));
	if (!input)
		return (NULL);
	input->argc = argc;
	input->argv = argv;
	input->envp = envp;
	err_handler->input_ptr = input;
	return (input);
}

void	pipex_input_validator(t_pipex_input *input, t_pipex_errors *err_handler)
{
	if (input->argc < 5 && ft_strncmp(input->argv[1], "here_doc", 9))
		exit_with_err_status_custom(err_handler, \
								ERR_INCORRECT_USAGE, EXIT_FAILURE);
	else if (!ft_strncmp(input->argv[1], "here_doc", 9))
		exit_with_err_status_custom(err_handler, \
								ERR_INCORRECT_USAGE_HEREDOC, EXIT_FAILURE);
	check_arguments(input, err_handler);
}

static void	check_arguments(t_pipex_input *input, t_pipex_errors *err_handler)
{
	int				i;
	char			*str;

	i = 1;
	while (i < input->argc)
	{
		str = ft_strtrim(input->argv[i], " \r\t\v\f\n");
		if (!ft_strncmp(str, "\0", 1))
		{
			free(str);
			exit_with_err_status_custom(err_handler, \
								ERR_EMPTY_ARGUMENTS, EXIT_FAILURE);
		}
		i++;
		free(str);
	}
}
