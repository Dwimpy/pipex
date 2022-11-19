/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_string_u.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:47:40 by arobu             #+#    #+#             */
/*   Updated: 2022/11/05 16:14:29 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_create_flag(t_fields *field)
{
	if (field->flags.minus)
		field->flag.left_justify = 1;
	if (field->flags.zero)
		field->flag.zero_padded = 1;
}

static void	ft_create_string_u_helper(char **output, char *str, t_fields *field)
{
	if (field -> plus_zero_prec)
		*output = ft_strjoin(field->width.padding_field, "+");
	else if (field -> msz_prec)
		*output = ft_strjoin(field->width.padding_field, "");
	else if (field->flag.left_justify)
		*output = ft_strjoin_three(field -> precision.padding_field, \
									str, field -> width.padding_field);
	else
	{
		if (field -> flag.zero_padded)
			*output = ft_strjoin_three(field -> width.padding_field, \
									field -> precision.padding_field, str);
		else if (!field -> flag.zero_padded)
			*output = ft_strjoin_three(field->width.padding_field, \
									field->precision.padding_field, str);
	}
}

char	*ft_create_string_u(va_list args, t_fields *field)
{
	char	*output;
	char	*str;

	output = (NULL);
	str = ft_handle_specifier(args, field);
	ft_create_flag(field);
	ft_create_precision(field);
	ft_create_width(field);
	ft_create_string_u_helper(&output, str, field);
	free(field -> precision.padding_field);
	free(field -> width.padding_field);
	free(str);
	return (output);
}
