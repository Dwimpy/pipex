/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 21:33:28 by arobu             #+#    #+#             */
/*   Updated: 2022/11/04 12:15:05 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_three(const char *s1, const char *s2, \
						const char *s3)
{
	char	*joint_string;
	size_t	s1_len;
	size_t	s2_len;
	size_t	s3_len;

	if (!s1 || !s2 || !s3)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3_len = ft_strlen(s3);
	joint_string = (char *)malloc(sizeof(char) * \
					(s1_len + s2_len + s3_len + 1));
	if (!joint_string)
		return (NULL);
	while (*s1)
		*joint_string++ = *s1++;
	while (*s2)
		*joint_string++ = *s2++;
	while (*s3)
		*joint_string++ = *s3++;
	*joint_string = '\0';
	return (joint_string - s1_len - s2_len - s3_len);
}
