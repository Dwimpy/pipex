/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_specifier_p.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 04:26:11 by arobu             #+#    #+#             */
/*   Updated: 2022/11/05 16:35:49 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_handle_specifier_p(t_fields *field, void *data)
{
	char		*str;
	uintmax_t	p;
	size_t		flag_len;

	p = *(uintmax_t *)data;
	flag_len = 2;
	if (p != 0)
		field->ndigits = ft_count_udigits(p, BASE_HEX_MINOR);
	else
	{
		field -> ndigits = ft_strlen("0x0");
		flag_len = 0;
	}
	ft_validate_specifier_p(field);
	if (field -> precision.isprovided)
		field -> precision.padding = field -> precision.valuegiven - \
		ft_min(field -> precision.valuegiven, field -> ndigits);
	if (field -> width.isprovided)
		field -> width.padding = field -> width.valuegiven - \
		ft_min(field -> width.valuegiven, field->precision.padding \
				+ field->ndigits + flag_len);
	str = ft_itoa_ubase(p, BASE_HEX_MINOR);
	return (str);
}
