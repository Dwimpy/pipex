/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 07:10:46 by arobu             #+#    #+#             */
/*   Updated: 2022/11/05 16:12:21 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_create_width(t_fields *field)
{
	if (field -> width.isprovided && field->width.padding > 0)
	{
		if (field -> flags.zero)
			field -> width.padding_field = \
			ft_strnew_zeros(field->width.padding, '0');
		else
			field -> width.padding_field = \
			ft_strnew_zeros(field->width.padding, ' ');
	}
	else
		field -> width.padding_field = ft_strdup("");
}
