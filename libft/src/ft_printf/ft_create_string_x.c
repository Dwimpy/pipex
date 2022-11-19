/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_string_x.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 22:45:19 by arobu             #+#    #+#             */
/*   Updated: 2022/11/05 16:29:29 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_create_flag_x(t_fields *field)
{
	if (field -> flags.minus)
		field -> flag.left_justify = 1;
	if (field -> flags.zero)
		field -> flag.zero_padded = 1;
	if (field -> flags.hash && field -> specifier == 'x')
		field -> sign.sign = ft_strdup("0x");
	else if (field -> flags.hash && field -> specifier == 'X')
		field -> sign.sign = ft_strdup("0X");
	else if (!field -> flags.hash)
		field -> sign.sign = ft_strdup("");
}

static char	*ft_create_string_x_helper(t_fields *field, char *str)
{
	char	*output;

	if (field -> msz_prec)
		output = ft_strjoin(field->width.padding_field, "");
	else if (field -> flag.left_justify)
		output = ft_strjoin_four(field -> sign.sign, \
								field -> precision.padding_field, \
								str, field -> width.padding_field);
	else
	{
		if (field -> flag.zero_padded)
			output = ft_strjoin_four(field -> sign.sign, \
									field->width.padding_field, \
									field -> precision.padding_field, str);
		else
			output = ft_strjoin_four(field -> width.padding_field, \
									field -> sign.sign, \
									field -> precision.padding_field, str);
	}
	return (output);
}

char	*ft_create_string_x(va_list args, t_fields *field)
{
	char	*output;
	char	*str;

	str = ft_handle_specifier(args, field);
	ft_create_flag_x(field);
	ft_create_precision(field);
	ft_create_width(field);
	output = ft_create_string_x_helper(field, str);
	free(field -> sign.sign);
	free(field -> width.padding_field);
	free(field -> precision.padding_field);
	free(str);
	return (output);
}
