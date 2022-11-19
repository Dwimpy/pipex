/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:50:18 by arobu             #+#    #+#             */
/*   Updated: 2022/10/17 03:10:20 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = 0;
	src_len = 0;
	while ((*src || src) && dst_len < dstsize && *dst)
	{
		dst++;
		dst_len++;
	}
	if (dst_len == dstsize)
		return (dst_len + ft_strlen(src));
	while (src[src_len])
	{
		if (src_len < dstsize - dst_len - 1)
			*dst++ = src[src_len];
		src_len++;
	}
	*dst = '\0';
	return (dst_len + src_len);
}
