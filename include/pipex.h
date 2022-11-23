/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:01:26 by arobu             #+#    #+#             */
/*   Updated: 2022/11/23 20:44:27 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "../libft/include/libft.h"
#include "../libft/include/ft_printf.h"
#include "path_handler.h"
#include <unistd.h>

typedef struct s_cmd
{
	char	*cmd;
	char	*options;
}				t_cmd;

typedef struct s_data
{
	t_cmd	*s_cmd;
	t_path	*path;
}				t_data;


#endif
