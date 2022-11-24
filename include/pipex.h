/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:01:26 by arobu             #+#    #+#             */
/*   Updated: 2022/11/24 16:39:26 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "../libft/include/ft_printf.h"
#include "cmd.h"

typedef struct s_data
{
	t_cmd	*s_cmd;
}				t_data;

void	pipex(int argc, char **argv, char **envp);

#endif
