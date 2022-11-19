/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 21:33:28 by arobu             #+#    #+#             */
/*   Updated: 2022/10/20 19:04:46 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joint_string;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joint_string = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!joint_string)
		return (NULL);
	while (*s1)
		*joint_string++ = *s1++;
	while (*s2)
		*joint_string++ = *s2++;
	*joint_string = '\0';
	return (joint_string - s1_len - s2_len);
}
