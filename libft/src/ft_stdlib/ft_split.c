/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:48:11 by arobu             #+#    #+#             */
/*   Updated: 2022/11/05 16:58:39 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char *str, char sep)
{
	int	word_count;

	word_count = 0;
	if (!*str)
		return (0);
	if (*str++ != sep)
		word_count++;
	while (*str != '\0')
	{
		if (*str != sep && *(str - 1) == sep)
			word_count++;
		str++;
	}
	return (word_count);
}

static char	**ft_allocatememeory(char *str, char sep, int *wn, int *str_index)
{
	char	**words;
	int		word_count;

	*wn = -1;
	*str_index = 0;
	word_count = ft_word_count(str, sep);
	words = malloc(sizeof(*words) * (word_count + 1));
	if (!words)
		return (0);
	return (words);
}

static int	ft_next_word(char *str, char sep, int index)
{
	int		word_len;

	word_len = 0;
	while (*(str + index) == sep && *(str + index) != '\0')
		index++;
	while (*(str + index) != sep && *(str + index) != '\0')
	{
		word_len++;
		index++;
	}
	return (word_len);
}

static char	**ft_free(char	**words, int index)
{
	int	j;

	j = 0;
	while (j < index && words[j] != 0)
	{
		free(words[j]);
		j++;
	}
	free(words);
	return (0);
}

char	**ft_split(const char *str, char sep)
{
	char	**words;
	int		wn;
	int		char_index;
	int		str_index;

	if (!str)
		return (NULL);
	words = ft_allocatememeory((char *)str, sep, &wn, &str_index);
	if (!words)
		return (NULL);
	while (++wn < ft_word_count((char *)str, sep))
	{
		char_index = 0;
		words[wn] = \
		malloc(ft_next_word((char *)str, sep, str_index) + 1);
		if (!words[wn])
			return (ft_free(words, wn));
		while (str[str_index] != '\0' && str[str_index] == sep)
			str_index++;
		while (str[str_index] != '\0' && str[str_index] != sep)
			words[wn][char_index++] = str[str_index++];
		words[wn][char_index] = '\0';
	}
	words[wn] = 0;
	return (words);
}
