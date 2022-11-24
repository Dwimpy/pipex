/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:59:04 by arobu             #+#    #+#             */
/*   Updated: 2022/11/24 20:24:53 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

typedef struct s_cmd
{
	t_file	file;
	char	*cmd;
	char	*options;
	char	*full_cmd;
}			t_cmd;

void	cmd_ctor(t_cmd **me, int argc, char **argv);
