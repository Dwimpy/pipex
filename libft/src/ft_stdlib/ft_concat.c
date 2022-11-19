/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:34:33 by arobu             #+#    #+#             */
/*   Updated: 2022/11/05 16:56:58 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_concat(const char *str1, const char *str2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	result = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	ft_memcpy(result, str1, len1);
	ft_memcpy(result + len1, str2, len2);
	return (result);
}
