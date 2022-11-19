/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_string_percent.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:49:15 by arobu             #+#    #+#             */
/*   Updated: 2022/11/07 12:02:10 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_create_flag_percent(t_fields *field)
{
	if (field -> flags.minus)
		field -> flag.left_justify = 1;
	if (field -> flags.zero)
		field -> flag.zero_padded = 1;
}

char	*ft_create_string_percent(t_fields *field)
{
	char	*str;
	char	*output;

	str = ft_handle_specifier_percent(field);
	ft_create_flag_percent(field);
	ft_create_width(field);
	if (field -> flag.left_justify)
		output = ft_strjoin(str, field -> width.padding_field);
	else
		output = ft_strjoin(field -> width.padding_field, str);
	free(field -> width.padding_field);
	free(str);
	return (output);
}
