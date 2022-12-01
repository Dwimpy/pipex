/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:58:47 by arobu             #+#    #+#             */
/*   Updated: 2022/12/01 16:59:05 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_split.h"

void	free_words(t_words *words)
{
	int i;

	i = 0;
	while (i < words->word_count && (*words).words[i].word != NULL)
	{
		free((*words).words[i].word);
		i++;
	}
	free((*words).words);
}

void	free_words_split(char **split_str)
{
	int i;

	i = 0;
	while (split_str[i] != NULL)
	{
		free(split_str[i]);
		i++;
	}
	free(split_str);
	split_str = NULL;
}