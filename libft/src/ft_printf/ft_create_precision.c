/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 06:52:46 by arobu             #+#    #+#             */
/*   Updated: 2022/11/05 15:54:54 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_create_precision(t_fields *field)
{
	if (field -> precision.isprovided && field->precision.padding > 0)
		field -> precision.padding_field = \
		ft_strnew_zeros(field -> precision.padding, '0');
	else
		field -> precision.padding_field = ft_strdup("");
}
