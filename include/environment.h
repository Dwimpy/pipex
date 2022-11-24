/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:17:49 by arobu             #+#    #+#             */
/*   Updated: 2022/11/24 18:20:33 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

#include "../libft/include/ft_printf.h"

typedef struct s_environment
{
	char	**envp;
	char	*bin_path_variable;
	char	**bin_paths;
}				t_environment;

void	env_ctor(t_environment *const me, char **envp);

#endif