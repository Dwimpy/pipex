/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:41:20 by arobu             #+#    #+#             */
/*   Updated: 2022/10/17 03:10:07 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*pt_dest;
	unsigned char	*pt_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	pt_dest = (unsigned char *)dest;
	pt_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*((char *)pt_dest + i) = *((char *)pt_src + i);
		i++;
	}
	return (dest);
}
