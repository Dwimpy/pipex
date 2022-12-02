/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:00:47 by arobu             #+#    #+#             */
/*   Updated: 2022/12/02 15:06:03 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H

# define FILE_H

# include <fcntl.h>
# include "../libft/include/ft_printf.h"
# include <errno.h>
# include <string.h>

typedef struct s_file
{
	char	*file_name;
}				t_file;

int	open_input_file(t_file file);
int	open_output_file(t_file file);

#endif
