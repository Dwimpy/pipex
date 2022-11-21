/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_spec_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 02:03:27 by arobu             #+#    #+#             */
/*   Updated: 2022/11/21 20:16:21 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_strdup_spec_s(char *str)
{
	char	*output;

	if (str == NULL)
		return (ft_strdup("(null)"));
	else
		output = ft_strdup(str);
	return (output);
}

char	*ft_strdup_spec_p(char *str)
{
	char	*output;

	if (str == NULL)
		return (ft_strdup("(nil)"));
	else
		output = ft_strdup(str);
	return (output);
}
