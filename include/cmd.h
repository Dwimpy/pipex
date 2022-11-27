/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:59:04 by arobu             #+#    #+#             */
/*   Updated: 2022/11/27 21:20:19 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "path.h"

void	cmd_ctor(t_cmd **me, t_environment env, int argc, char **argv);
char	**pipex_split(const char *str, char sep);

#endif
