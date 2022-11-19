/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 01:22:48 by arobu             #+#    #+#             */
/*   Updated: 2022/11/05 16:14:07 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_count_digits(intmax_t n, char *base)
{
	size_t	ndigits;
	size_t	radix;

	ndigits = 0;
	radix = ft_strlen(base);
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= radix;
		ndigits++;
	}
	return (ndigits);
}

size_t	ft_count_udigits(uintmax_t n, char *base)
{
	size_t	ndigits;
	size_t	radix;

	ndigits = 0;
	radix = ft_strlen(base);
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= radix;
		ndigits++;
	}
	return (ndigits);
}
