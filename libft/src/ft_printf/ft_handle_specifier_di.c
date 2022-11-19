/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_specifier_di.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 01:34:10 by arobu             #+#    #+#             */
/*   Updated: 2022/11/05 15:36:01 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_specifier_s.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 01:24:45 by arobu             #+#    #+#             */
/*   Updated: 2022/11/04 01:33:44 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_check_edge_cases(t_fields *field, intmax_t number)
{
	if (number == 0 && field->precision.valuegiven == 0 && \
		field->precision.isprovided && !field -> width.isprovided && \
		field -> flags.space)
	{
		field -> msz_prec = 1;
		field -> width.isprovided = 1;
		field -> width.padding = 1;
	}
	else if (number == 0 && field->precision.valuegiven == 0 && \
			field->precision.isprovided && field->flags.plus)
	{
		field -> plus_zero_prec = 1;
		if (field -> width.valuegiven > 1)
			field -> width.padding += 1;
	}
	else if (number == 0 && field->precision.valuegiven == 0 && \
			field->precision.isprovided && !field->flags.plus)
	{
		field -> msz_prec = 1;
		field -> width.padding = field->width.valuegiven;
	}
}

char	*ft_handle_specifier_di(t_fields *field, void *data)
{
	intmax_t	number;
	char		*str;

	number = *(intmax_t *)data;
	if (number < 0 || field->flags.space || field->flags.plus)
	{
		field->sign.has_sign = 1;
		if (number < 0)
		{
			field->sign.is_negative = 1;
			number *= -1;
		}
	}
	ft_validate_specifier_di(field);
	field->ndigits = ft_count_digits(number, BASE_DECIMAL);
	if (field->precision.isprovided)
		field->precision.padding = field->precision.valuegiven - \
		ft_min(field->precision.valuegiven, field->ndigits);
	if (field->width.isprovided)
		field -> width.padding = field -> width.valuegiven - \
		ft_min(field -> width.valuegiven, \
		field -> precision.padding + field->ndigits + field->sign.has_sign);
	ft_check_edge_cases(field, number);
	str = ft_itoa(number);
	return (str);
}
