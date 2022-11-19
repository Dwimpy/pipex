/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_string_p.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 08:56:03 by arobu             #+#    #+#             */
/*   Updated: 2022/11/05 15:59:29 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_create_flag_p(t_fields *field)
{
	if (field -> flags.minus)
		field -> flag.left_justify = 1;
	if (field -> flags.zero)
		field -> flag.zero_padded = 1;
}

static char	*ft_create_string_p_helper(char *str, t_fields *field)
{
	char	*output;

	if (field -> flag.left_justify)
	{
		if (field -> flag.zero_padded)
			output = ft_strjoin_four("0x", field -> precision.padding_field, \
									field -> width.padding_field, str);
		else
			output = ft_strjoin_four("0x", field -> precision.padding_field, \
										str, field -> width.padding_field);
	}
	else
	{
		if (field -> flag.zero_padded)
			output = ft_strjoin_four("0x", field -> width.padding_field, \
									field->precision.padding_field, str);
		else
			output = ft_strjoin_four(field -> width.padding_field, "0x", \
									field->precision.padding_field, str);
	}
	return (output);
}

static char	*ft_create_string_p_helper_nil(char *str, t_fields *field)
{
	char	*output;

	if (field -> flag.left_justify)
	{
		if (field -> flag.zero_padded)
			output = ft_strjoin_three(field -> precision.padding_field, \
									field -> width.padding_field, str);
		else
			output = ft_strjoin_three(field -> precision.padding_field, \
									str, field -> width.padding_field);
	}
	else
	{
		if (field -> flag.zero_padded)
			output = ft_strjoin_three(field -> width.padding_field, \
									field->precision.padding_field, str);
		else
			output = ft_strjoin_three(field -> width.padding_field, \
									field->precision.padding_field, str);
	}
	return (output);
}

char	*ft_create_string_p(va_list args, t_fields *field)
{
	char	*output;
	char	*str;

	str = ft_handle_specifier(args, field);
	ft_create_flag_p(field);
	ft_create_width(field);
	ft_create_precision(field);
	if (ft_strncmp(str, "(nil)", 6) == 0)
		output = ft_create_string_p_helper_nil(str, field);
	else
		output = ft_create_string_p_helper(str, field);
	free(field -> width.padding_field);
	free(field -> precision.padding_field);
	free(str);
	return (output);
}
