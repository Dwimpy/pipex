/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_specifier_percent.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 06:12:06 by arobu             #+#    #+#             */
/*   Updated: 2022/11/05 16:36:23 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_handle_specifier_percent(t_fields *field)
{
	field->ndigits += 1;
	ft_validate_specifier_percent(field);
	if (field -> width.isprovided)
		field -> width.padding = field -> width.valuegiven - \
		ft_min(field -> width.valuegiven, 1);
	else
		field -> width.padding = 0;
	return (ft_strnew('%'));
}
