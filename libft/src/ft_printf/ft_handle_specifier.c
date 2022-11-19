/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:51:54 by arobu             #+#    #+#             */
/*   Updated: 2022/11/05 16:34:46 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_handle_cspdi(va_list args, t_fields *field)
{
	char		*tmp;
	char		*spec;
	uintmax_t	ua;
	intmax_t	a;

	if (field->specifier == 's')
	{
		tmp = va_arg(args, char *);
		spec = ft_handle_specifier_s(field, tmp);
	}
	if (field -> specifier == 'p')
	{
		ua = (uintmax_t)va_arg(args, unsigned long);
		spec = ft_handle_specifier_p(field, &ua);
	}
	if (ft_contains("di", field->specifier))
	{
		a = va_arg(args, int);
		spec = ft_handle_specifier_di(field, &a);
	}
	return (spec);
}

char	*ft_handle_uxxpercent(va_list args, t_fields *field)
{
	char		*spec;
	uintmax_t	ua;

	if (field->specifier == 'u')
	{
		ua = va_arg(args, unsigned int);
		spec = ft_handle_specifier_u(field, &ua);
	}
	if (field->specifier == 'x')
	{
		ua = va_arg(args, unsigned int);
		spec = ft_handle_specifier_x(field, &ua);
	}
	if (field->specifier == 'X')
	{
		ua = va_arg(args, unsigned int);
		spec = ft_handle_specifier_x(field, &ua);
	}
	if (field->specifier == '%')
	{
		spec = ft_handle_specifier_percent(field);
	}
	return (spec);
}

char	*ft_handle_specifier(va_list args, t_fields *field)
{
	char		*spec;

	if (ft_contains("cspdi", field -> specifier))
		spec = ft_handle_cspdi(args, field);
	if (ft_contains("uxX%", field -> specifier))
		spec = ft_handle_uxxpercent(args, field);
	return (spec);
}
