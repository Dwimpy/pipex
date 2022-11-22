/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:01:26 by arobu             #+#    #+#             */
/*   Updated: 2022/11/22 17:53:45 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "../libft/include/libft.h"
#include "../libft/include/ft_printf.h"
#include "unistd.h"

typedef struct s_cmd
{
	char	*cmd;
	char	*options;
	char	*path;
}				t_cmd;

typedef struct s_data
{
	int		argc;
	t_cmd	*s_cmd;
	char	**argv;
	char	**envp;
}				t_data;


#endif
