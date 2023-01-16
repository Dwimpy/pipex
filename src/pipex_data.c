/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:16:12 by arobu             #+#    #+#             */
/*   Updated: 2023/01/16 18:38:11 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../include/pipex_file.h"

static int	set_here_doc(t_pipex_input *input);
static char	**set_path_binaries(t_pipex_input *input);
static char	*set_limiter(char **argv, int here_doc);

t_pipex_data	*create_new_data(t_pipex_input *input)
{
	t_pipex_data	*data;

	data = (t_pipex_data *)malloc(sizeof(t_pipex_data));
	if (!data)
		return (NULL);
	init_t_pipex_data(&data);
	data->here_doc = set_here_doc(input);
	(*data).command_number = input->argc - data->here_doc - 3;
	if (data->here_doc == 0)
		data->input_file = new_pipex_input_file(data, input->argv[1]);
	else
		data->input_file = NULL;
	data->output_file = new_pipex_output_file(data, \
											input->argv[input->argc - 1]);
	data->limiter = set_limiter(input->argv, data->here_doc);
	data->binaries = set_path_binaries(input);
	return (data);
}

static int	set_here_doc(t_pipex_input *input)
{
	int	here_doc;

	here_doc = 0;
	if (!ft_strncmp(input->argv[1], "here_doc", 9))
		here_doc = 1;
	return (here_doc);
}

static char	*set_limiter(char **argv, int here_doc)
{
	char	*limiter;

	if (here_doc == 1)
		limiter = ft_strdup(argv[2]);
	else
		limiter = NULL;
	return (limiter);
}

static char	**set_path_binaries(t_pipex_input *input)
{
	char	**binaries;
	char	**env_ptr;
	char	*env_path;

	env_ptr = input->envp;
	binaries = NULL;
	env_path = NULL;
	while (env_ptr != NULL)
	{
		if (!ft_strncmp("PATH=", *env_ptr, 5))
		{
			if (ft_strnstr(*env_ptr, "/bin", ft_strlen(*env_ptr)))
			{
				env_path = ft_strdup(*env_ptr);
				break ;
			}
		}
		env_ptr++;
	}
	if (env_path)
		binaries = ft_split(env_path + 5, ':');
	free(env_path);
	return (binaries);
}
