/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:08:13 by arobu             #+#    #+#             */
/*   Updated: 2022/11/25 19:18:52 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	tofnd;

	i = 0;
	str = (unsigned char *)s;
	tofnd = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == tofnd)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
