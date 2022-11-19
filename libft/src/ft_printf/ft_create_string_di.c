/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_string_di.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:40:52 by arobu             #+#    #+#             */
/*   Updated: 2022/11/05 15:56:57 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	void	ft_create_flag_di(t_fields *field)
{
	if (field -> sign.is_negative)
		field -> sign.sign = ft_strdup("-");
	else if (field -> flags.plus)
		field -> sign.sign = ft_strdup("+");
	else if (field -> flags.space)
		field -> sign.sign = ft_strdup(" ");
	else
		field -> sign.sign = ft_strdup("");
	if (field -> flags.minus)
		field -> flag.left_justify = 1;
	if (field -> flags.zero)
		field -> flag.zero_padded = 1;
}

static	char	*ft_create_string_di_helper(char *str, t_fields *field)
{
	char	*output;

	if (field -> flag.left_justify)
		output = ft_strjoin_four(field -> sign.sign, \
		field -> precision.padding_field, str, field -> width.padding_field);
	else
		output = ft_strjoin_four(field -> width.padding_field, \
		field -> sign.sign, field -> precision.padding_field, str);
	if (field -> flag.zero_padded)
	{
		free(output);
		output = ft_strjoin_four(field -> sign.sign, \
		field -> precision.padding_field, field -> width.padding_field, str);
	}
	return (output);
}

static void	ft_create_string_di_edge_cases(char **output, \
											char *str,
											t_fields *field)
{
	if (field -> plus_zero_prec)
	{
		if (field -> flag.left_justify)
			*output = ft_strjoin("+", field->width.padding_field);
		else
			*output = ft_strjoin(field->width.padding_field, "+");
	}
	else if (field -> msz_prec)
	{
		if (field -> flag.left_justify)
			*output = ft_strjoin("", field->width.padding_field);
		else
			*output = ft_strjoin(field->width.padding_field, "");
	}
	else
		*output = ft_create_string_di_helper(str, field);
}

char	*ft_create_string_di(va_list args, t_fields *field)
{
	char	*output;
	char	*str;

	str = ft_handle_specifier(args, field);
	ft_create_flag_di(field);
	ft_create_width(field);
	ft_create_precision(field);
	ft_create_string_di_edge_cases(&output, str, field);
	free(field -> sign.sign);
	free(field -> width.padding_field);
	free(field -> precision.padding_field);
	free(str);
	return (output);
}
