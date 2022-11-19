/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_specifier_s.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 01:24:45 by arobu             #+#    #+#             */
/*   Updated: 2022/11/05 16:36:54 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_handle_specifier_s(t_fields *field, void *data)
{
	char	*str;

	str = ft_strdup_spec_s((char *)data);
	ft_validate_specifier_s(field);
	field->ndigits = ft_strlen(str);
	if (field -> precision.isprovided)
		field -> precision.padding = \
		ft_min(field->precision.valuegiven, field->ndigits);
	else
		field -> precision.padding = field -> ndigits;
	if (field -> width.isprovided)
	field -> width.padding = field -> width.valuegiven - \
	ft_min(field -> width.valuegiven, field -> precision.padding);
	return (str);
}
