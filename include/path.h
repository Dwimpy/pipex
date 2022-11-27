/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:19:05 by arobu             #+#    #+#             */
/*   Updated: 2022/11/27 20:29:41 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

# include "environment.h"
# include <stdio.h>

void	file_cmd_path(t_cmd *cmd, t_environment env, int command_count);
void	cmd_file_exists(t_cmd *cmd, t_environment env);

#endif
