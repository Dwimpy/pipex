/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:21:48 by arobu             #+#    #+#             */
/*   Updated: 2022/10/23 00:46:21 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trimmed_str;
	size_t	s1_len;
	size_t	i;

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

// int main()
// {
// 	char s1[] = "lorem ipsum dolor sit amet";
// 	printf("%s", ft_strtrim(s1, "tel"));
// }