/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_four.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 21:33:28 by arobu             #+#    #+#             */
/*   Updated: 2022/11/05 17:16:30 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_str_len(const char *s1, const char *s2, \
						const char *s3, const char *s4)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	s3_len;
	size_t	s4_len;

	if (!s1 || !s2 || !s3 || !s4)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3_len = ft_strlen(s3);
	s4_len = ft_strlen(s4);
	return (s1_len + s2_len + s3_len + s4_len);
}

char	*ft_strjoin_four(const char *s1, const char *s2, \
						const char *s3, const char *s4)
{
	char	*joint_string;
	size_t	str_len;

	str_len = get_str_len(s1, s2, s3, s4);
	joint_string = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!joint_string)
		return (NULL);
	while (*s1)
		*joint_string++ = *s1++;
	while (*s2)
		*joint_string++ = *s2++;
	while (*s3)
		*joint_string++ = *s3++;
	while (*s4)
		*joint_string++ = *s4++;
	*joint_string = '\0';
	return (joint_string - str_len);
}
