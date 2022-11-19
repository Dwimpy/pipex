/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:35:47 by arobu             #+#    #+#             */
/*   Updated: 2022/11/07 12:04:44 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t	get_total_len(char *buffer, size_t *i, \
							size_t *j, t_fields *field)
{
	if (field->precision.isprovided)
	{
		field -> precision.valuegiven += ft_atoi(buffer);
		return (*i + *j);
	}
	else if (*j > 0)
	{
		field->precision.isprovided = 1;
		return (*j);
	}
	return (*i + *j);
}

static size_t	ft_get_precision_helper(const char *format, \
										char *buffer, t_fields *field)
{
	size_t	i;
	size_t	j;
	size_t	total_len;

	i = 0;
	j = 0;
	total_len = 0;
	while (format[j] == '.' || format[j] == '0')
		j++;
	while (ft_contains(PRECISION, format[i + j]))
	{
		if (!field->precision.isprovided)
			field->precision.isprovided = 1;
		buffer[i] = format[i + j];
		i++;
	}
	buffer[i] = '\0';
	total_len = get_total_len(buffer, &i, &j, field);
	return (total_len);
}

size_t	ft_get_precision(t_fields *field, const char *format)
{
	char	buffer[11];
	size_t	len;

	len = ft_get_precision_helper(format, buffer, field);
	return (len);
}
