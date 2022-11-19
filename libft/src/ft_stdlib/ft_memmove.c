/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:32:41 by arobu             #+#    #+#             */
/*   Updated: 2022/10/20 01:58:16 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char	*destination;
	unsigned char	*source;
	size_t			i;

	destination = dst;
	source = src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (destination > source)
	{
		while (len-- > 0)
		{
			destination[len] = source[len];
		}
	}
	else
	{
		while (i < len)
		{
			destination[i] = source[i];
			i++;
		}
	}
	return (dst);
}
