/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:17:49 by arobu             #+#    #+#             */
/*   Updated: 2022/11/25 21:09:17 by arobu            ###   ########.fr       */
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
	char	*bin_path_variable;
	char	**bin_paths;
}				t_environment;

typedef struct s_file_vtable
{
	void	(*get_cmd_path)();
}				t_file_vtable;

typedef struct s_file
{
	t_environment	env;
	t_file_vtable	file_vtable;
	char			*dir_path;
	char			*file_name;
	char			*full_path;
}					t_file;

typedef struct s_cmd
{
	t_file	file;
	char	*cmd;
	char	*options;
	char	*full_cmd;
}			t_cmd;

void	env_ctor(t_environment *const me, char **envp);

#endif