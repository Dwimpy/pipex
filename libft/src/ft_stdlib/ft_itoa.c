/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:42:29 by arobu             #+#    #+#             */
/*   Updated: 2022/11/04 14:53:25 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static int	count_digits(intmax_t n)
{
	int	digits;

	if (n > 0)
		digits = 0;
	else
		digits = 1;
	while (n > 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(intmax_t n)
{
	int		digits;
	char	*nbr;

	digits = count_digits(n);
	if (n == 0)
		return (ft_strdup("0"));
	nbr = (char *)malloc(sizeof(char) * (digits + 1));
	if (!nbr)
		return (NULL);
	if (n < 0)
		nbr[0] = '-';
	nbr[digits] = '\0';
	while (digits-- > 0 && n > 0)
	{
		nbr[digits] = (n % 10) + '0';
		n = n / 10;
	}
	return (nbr);
}
