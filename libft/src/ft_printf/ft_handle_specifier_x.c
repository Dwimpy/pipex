/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_specifier_x.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 05:17:35 by arobu             #+#    #+#             */
/*   Updated: 2022/11/05 16:49:28 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_select_basse_edge_cases(uintmax_t number, \
									t_fields *field, char **base)
{
	if (field -> specifier == 'X')
		*base = BASE_HEX_MAJOR;
	if (field -> specifier == 'x')
		*base = BASE_HEX_MINOR;
	if (number == 0 && field -> precision.isprovided && \
		field -> precision.valuegiven == 0)
	{
		field -> msz_prec = 1;
		if (field->width.valuegiven > 0)
			field->width.padding += 1;
	}
}

static void	ft_pw_padding(t_fields *field, size_t flag)
{
	if (field -> precision.isprovided)
		field -> precision.padding = field -> precision.valuegiven - \
		ft_min(field -> precision.valuegiven, field->ndigits);
	if (field -> width.isprovided)
		field -> width.padding = field -> width.valuegiven - \
		ft_min(field -> width.valuegiven, field -> precision.padding + \
		field->ndigits + flag);
}

static void	ft_treat_sign(uintmax_t number, t_fields *field)
{
	if (number == 0)
	{
		field -> flags.hash = 0;
	}
	if (field -> flags.hash)
		field -> sign.has_sign = 1;
}

char	*ft_handle_specifier_x(t_fields *field, void *data)
{
	unsigned long long	number;
	size_t				flag;
	char				*str;
	char				*base;

	number = *(uintmax_t *)data;
	flag = 0;
	if (field->flags.hash && number > 0)
		flag += 2;
	field->ndigits = ft_count_udigits(number, BASE_HEX_MINOR);
	ft_treat_sign(number, field);
	ft_validate_specifier_x(field);
	ft_pw_padding(field, flag);
	ft_select_basse_edge_cases(number, field, &base);
	str = ft_itoa_ubase(number, base);
	return (str);
}
