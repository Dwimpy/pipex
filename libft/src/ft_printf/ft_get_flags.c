/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 05:14:05 by arobu             #+#    #+#             */
/*   Updated: 2022/11/07 12:04:40 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_get_flags(t_fields *field, const char *format)
{
	size_t	count;

	count = 0;
	while (ft_contains(FLAGS, format[count]))
	{
		if (!field->flags.isprovided)
			field->flags.isprovided = 1;
		if (format[count] == '-')
			field ->flags.minus = 1;
		else if (format[count] == '+')
			field -> flags.plus = 1;
		else if (format[count] == ' ')
			field -> flags.space = 1;
		else if (format[count] == '#')
			field -> flags.hash = 1;
		else if (format[count] == '0')
			field -> flags.zero = 1;
		count++;
	}
	return (count);
}
