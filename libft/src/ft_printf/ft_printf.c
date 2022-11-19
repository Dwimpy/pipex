/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:12:53 by arobu             #+#    #+#             */
/*   Updated: 2022/11/10 13:36:46 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_print_str(char *str, size_t size, int fd, t_fields *field)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		while (i < size)
		{
			ft_putchar_fd(str[i++], fd);
			field->buff_index++;
		}
	}
}

void	ft_handle_args(const char *format, \
						t_fields *field, va_list args)
{
	char	*str;
	char	c;
	size_t	size;

	field -> bytes_to_skip = 0;
	field -> bytes_to_skip += ft_handle_options(field, format);
	if (field -> specifier == 'c')
	{
		size = 0;
		c = va_arg(args, int);
		ft_add_width_c(&str, c, field, &size);
		ft_print_str(str, size, 1, field);
		free(str);
	}
	else
	{
		str = ft_create_string(args, field);
		ft_print_str(str, ft_strlen(str), 1, field);
		free(str);
	}
	field->format_index += field->bytes_to_skip;
}

size_t	ft_print(const char *format, va_list args)
{
	t_fields	field;

	field = ft_init_field();
	while (format[field.format_index] != '\0')
	{
		if (format[field.format_index] == '%')
		{	
			ft_reset_field(&field);
			ft_handle_args(&format[field.format_index], &field, args);
		}
		else
		{
			ft_putchar_fd(format[field.format_index], 1);
			field.buff_index++;
		}
		field.format_index++;
	}
	return (field.buff_index);
}

size_t	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	len;

	len = 0;
	va_start(args, format);
	len = ft_print(format, args);
	va_end(args);
	return (len);
}
