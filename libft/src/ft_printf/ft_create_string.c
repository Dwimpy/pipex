/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:29:39 by arobu             #+#    #+#             */
/*   Updated: 2022/11/07 12:02:33 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_create_string(va_list args, t_fields *field)
{
	char	*output;

	if (field -> specifier == 's')
		output = ft_create_string_s(args, field);
	if (field -> specifier == 'p')
		output = ft_create_string_p(args, field);
	if (ft_contains("di", field -> specifier))
		output = ft_create_string_di(args, field);
	if (field -> specifier == 'u')
		output = ft_create_string_u(args, field);
	if (ft_contains("xX", field -> specifier))
		output = ft_create_string_x(args, field);
	if (field -> specifier == '%')
		output = ft_create_string_percent(field);
	return (output);
}
