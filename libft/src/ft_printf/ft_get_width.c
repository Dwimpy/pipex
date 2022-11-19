/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:37:15 by arobu             #+#    #+#             */
/*   Updated: 2022/11/07 12:04:53 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_get_width(t_fields *field, const char *format)
{
	char	buffer[11];
	size_t	i;

	i = 0;
	while (ft_contains(WIDTH, format[i]))
	{
		if (!field->width.isprovided)
			field->width.isprovided = 1;
		buffer[i] = format[i];
		i++;
	}
	buffer[i] = '\0';
	if (field->width.isprovided)
	{
		field -> width.valuegiven = ft_atoi(buffer);
		return (i);
	}
	else
		return (0);
}
