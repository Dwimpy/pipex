/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_commands_option_helper.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 03:42:31 by arobu             #+#    #+#             */
/*   Updated: 2023/02/25 14:30:01 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_commands.h"

char	*create_access_option(t_fsm_results_node *word)
{
	char				*options;
	char				*trimmed_option;

	if (ft_strrchr(word->word, '/') && \
		!ft_strnstr(word->word, ".sh", ft_strlen(word->word)))
		trimmed_option = ft_strtrim(ft_strrchr(word->word, '/') + 1, " \t\r\v\f\n");
	else
		trimmed_option = ft_strtrim(word->word, " \r\t\v\f\n");
	options = ft_strdup(trimmed_option);
	free(trimmed_option);
	return (options);
}

char	*create_regular_option(t_fsm_results_node *word)
{
	char	*trimmed_option;
	char	*options;

	trimmed_option = ft_strtrim(word->word, " \t\r\v\f\n");
	options = ft_strdup(trimmed_option);
	free(trimmed_option);
	return (options);
}
