/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:38:53 by arobu             #+#    #+#             */
/*   Updated: 2023/01/18 19:26:39 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strdup(const char *string)
{
	char	*destination;
	char	*dst_start;
	int		string_len;

	string_len = ft_strlen(string);
	destination = (char *)malloc(sizeof(char) * (string_len + 1));
	if (!destination)
		return (NULL);
	dst_start = destination;
	while (*string)
	{
		*destination = *string;
		destination++;
		string++;
	}
	*destination = '\0';
	return (dst_start);
}
