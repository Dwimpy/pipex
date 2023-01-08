/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:25:21 by arobu             #+#    #+#             */
/*   Updated: 2023/01/08 13:20:22 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	check_arguments(t_pipex_input *input);

t_pipex_input	*pipex_new_input(int argc, char **argv, char **envp)
{
	t_pipex_input	*input;

	input = (t_pipex_input *)malloc(sizeof(t_pipex_input));
	if (!input)
		return (NULL);
	input->argc = argc;
	input->argv = argv;
	input->envp = envp;
	return (input);
}

void	pipex_input_validator(t_pipex_input *input)
{
	if (input->argc < 5 && ft_strncmp(input->argv[1], "here_doc", 9))
	{
		ft_putstr_fd(ERR_INCORRECT_USAGE, 2);
		exit(EXIT_FAILURE);
	}
	else if (!ft_strncmp(input->argv[1], "here_doc", 9))
	{
		if (input->argc < 6)
		{
			ft_putstr_fd(ERR_INCORRECT_USAGE_HEREDOC, 2);
			exit(EXIT_FAILURE);
		}
	}
	check_arguments(input);
}

static void	check_arguments(t_pipex_input *input)
{
	int	i;

	i = 1;
	while (i < input->argc)
	{
		if (!ft_strncmp(input->argv[i], "\0", 1))
		{
			ft_putstr_fd(ERR_EMPTY_ARGUMENTS, 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
