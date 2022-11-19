/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_specifier_u.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 05:06:16 by arobu             #+#    #+#             */
/*   Updated: 2022/11/06 21:19:14 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_specifier_u_check_cases(uintmax_t u, t_fields *field)
{
	if (u == 0 && field->precision.valuegiven == 0 && \
		field->precision.isprovided && field->flags.plus)
	{
		field -> plus_zero_prec = 1;
		field -> width.padding += 1;
	}
	if (u == 0 && field->precision.valuegiven == 0 && \
		field->precision.isprovided && !field->flags.plus)
	{
		field -> msz_prec = 1;
		field -> width.padding += 1 ;
	}
}

static void	ft_pw_padding(t_fields *field)
{
	if (field -> precision.isprovided)
		field -> precision.padding = field->precision.valuegiven - \
		ft_min(field -> precision.valuegiven, field->ndigits);
	if (field -> width.isprovided)
		field -> width.padding = field -> width.valuegiven - ft_min(field -> \
		width.valuegiven, field -> precision.padding + field -> ndigits);
}

char	*ft_handle_specifier_u(t_fields *field, void *data)
{
	uintmax_t	u;
	char		*str;

	u = *(uintmax_t *)data;
	field->ndigits = ft_count_udigits(u, BASE_DECIMAL);
	ft_validate_specifier_u(field);
	ft_pw_padding(field);
	ft_specifier_u_check_cases(u, field);
	str = ft_uitoa(u);
	return (str);
}
