/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:21:48 by arobu             #+#    #+#             */
/*   Updated: 2022/12/01 03:58:58 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include <string.h>

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trimmed_str;
	size_t	s1_len;
	size_t	i;

	trimmed_str = NULL;
	if (!s1 || !set)
		return (NULL);
	i = 0;
	s1_len = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	if (i == ft_strlen(s1))
	{
		trimmed_str = (char *)malloc(sizeof(char) * 1);
		if (!trimmed_str)
			return (NULL);
		trimmed_str[0] = '\0';
		return (trimmed_str);
	}
	while (s1_len && ft_strchr(set, s1[s1_len]))
		s1_len--;
	trimmed_str = ft_substr(s1, i, s1_len - i + 1);
	return (trimmed_str);
}

char	*ft_strtrim_char(const char *s1, const char c)
{
	char	*trimmed_str;
	size_t	s1_len;
	size_t	i;

	trimmed_str = NULL;
	if (!s1)
		return (NULL);
	i = 0;
	s1_len = ft_strlen(s1) - 1;
	while (s1[i] == c)
		i++;
	if (i == ft_strlen(s1))
	{
		trimmed_str = (char *)malloc(sizeof(char) * 1);
		if (!trimmed_str)
			return (NULL);
		trimmed_str[0] = '\0';
		return (trimmed_str);
	}
	while (s1_len && s1[s1_len] == c)
		s1_len--;
	trimmed_str = ft_substr(s1, i, s1_len - i + 1);
	return (trimmed_str);
}
