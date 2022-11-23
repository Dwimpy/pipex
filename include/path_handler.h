/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_handler.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:41:05 by arobu             #+#    #+#             */
/*   Updated: 2022/11/23 21:21:32 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_path_fct_ptr
{
	char	**(*bin_path_fct)();
	char	*(*sh_bin_path_fct)();
}				t_path_fct_ptr;

typedef struct s_path
{
	char 	**bin_path;
	char	*sh_bin_path;
	t_path_fct_ptr path_fct_ptr;
}				t_path;


t_path	*newPath(char **envp);
