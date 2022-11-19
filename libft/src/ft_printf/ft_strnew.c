/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 01:51:57 by arobu             #+#    #+#             */
/*   Updated: 2022/11/05 16:54:46 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_strnew(char c)
{
	char	*str;

	str = ft_calloc(2, sizeof(char));
	if (c)
		str[0] = c;
	else
		str[0] = 0;
	return (str);
}
