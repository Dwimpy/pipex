/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:47:36 by arobu             #+#    #+#             */
/*   Updated: 2022/10/17 03:11:34 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start_index, size_t len)
{
	char	*substring;
	size_t	size;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	if (ft_strlen(str) < start_index)
		return (ft_strdup(""));
	str += start_index;
	size = ft_strlen(str);
	if (size < len)
		len = size;
	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	while (i < len)
	{
		substring[i] = str[i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

// int main(void)
// {
// 	char	str[] = "lorem ipsum dolor sit amet";
// 	char	*strsub;
// 	char *bullshit;
// 	bullshit = (char *)&strsub[30];
// 	bullshit = "FULL BULLSHIT";

// 	puts(ft_substr(str,0,42000));
// }