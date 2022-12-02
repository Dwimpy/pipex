/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:01:26 by arobu             #+#    #+#             */
/*   Updated: 2022/12/02 13:25:33 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H


# include "../libft/include/ft_printf.h"
# include "pipeline.h"
# include "cmd.h"

void	pipex(int argc, char **argv, char **envp);

#endif
