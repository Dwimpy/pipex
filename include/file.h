/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:00:47 by arobu             #+#    #+#             */
/*   Updated: 2022/12/05 00:01:02 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H

# define FILE_H

# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "get_next_line.h"
# include "../libft/include/ft_printf.h"
# include "environment.h"

typedef struct s_file
{
	char	*file_name;
}				t_file;

int		open_input_file(t_file file, t_environment env);
int		open_output_file(t_file file, t_environment env);
void	get_heredoc_input(t_environment env, t_file file);

#endif
