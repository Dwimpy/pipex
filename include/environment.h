/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:17:49 by arobu             #+#    #+#             */
/*   Updated: 2022/12/03 18:47:10 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "../libft/include/ft_printf.h"
# include <errno.h>
# include <string.h>

typedef struct s_environment
{
	char	**envp;
	int		argc;
	char	**argv;
	char	*bin_path_variable;
	char	**bin_paths;
}				t_environment;

typedef struct s_file_vtable
{
	void	(*get_cmd_path)();
}				t_file_vtable;

typedef struct s_path
{
	t_environment	env;
	char			*dir_path;
	char			*file_name;
	char			*full_path;
}					t_path;

typedef struct s_cmd
{
	t_path	path;
	int		command_count;
	char	*cmd;
	char	*options;
	char	*full_cmd;
	char	**exec_options;
}			t_cmd;

void	env_ctor(t_environment *const me, char **envp, int argc, char **argv);

#endif