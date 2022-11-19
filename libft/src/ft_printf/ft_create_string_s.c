/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_string_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 08:56:03 by arobu             #+#    #+#             */
/*   Updated: 2022/11/05 16:00:08 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_create_flag_s(t_fields *field)
{
	if (field -> flags.minus)
		field -> flag.left_justify = 1;
}

char	*ft_create_string_s(va_list args, t_fields *field)
{
	char	*output;
	char	*tmp;
	char	*str;

	str = ft_handle_specifier(args, field);
	if (field -> precision.isprovided)
	{
		tmp = ft_substr(str, 0, field->precision.padding);
		free(str);
	}
	else
		tmp = str;
	ft_create_flag_s(field);
	ft_create_width(field);
	if (field -> flag.left_justify)
		output = ft_strjoin(tmp, field->width.padding_field);
	else
		output = ft_strjoin(field->width.padding_field, tmp);
	free(field -> width.padding_field);
	free(tmp);
	return (output);
}
