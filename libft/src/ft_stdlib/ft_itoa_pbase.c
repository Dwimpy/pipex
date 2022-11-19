/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_pbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:57:35 by arobu             #+#    #+#             */
/*   Updated: 2022/11/05 16:58:00 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(unsigned long n, const char *base)
{
	int	digits;
	int	radix;

	radix = ft_strlen(base);
	if (n > 0)
		digits = 0;
	else
		digits = 1;
	while (n > 0)
	{
		n = n / radix;
		digits++;
	}
	return (digits);
}

char	*ft_itoa_pbase(uintmax_t n, const char *base)
{
	int		digits;
	char	*nbr;
	int		radix;

	digits = count_digits(n, base);
	radix = ft_strlen(base);
	if (n == 0)
		return (ft_strdup("(nil)"));
	nbr = (char *)malloc(sizeof(char) * (digits + 1));
	if (!nbr)
		return (NULL);
	nbr[digits] = '\0';
	while (digits-- > 0 && n > 0)
	{
		nbr[digits] = base[(n % radix)];
		n = n / radix;
	}
	return (nbr);
}
