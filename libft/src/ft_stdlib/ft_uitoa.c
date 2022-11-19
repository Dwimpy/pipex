/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:01:52 by arobu             #+#    #+#             */
/*   Updated: 2022/11/05 17:01:57 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(uintmax_t n)
{
	int	digits;

	digits = 0;
	while (n > 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

char	*ft_uitoa(uintmax_t n)
{
	int		digits;
	char	*nbr;

	if (n <= 0)
		return (ft_strdup("0"));
	digits = count_digits(n);
	nbr = (char *)malloc(sizeof(char) * (digits + 1));
	if (!nbr)
		return (NULL);
	nbr[digits] = '\0';
	while (digits-- > 0)
	{
		nbr[digits] = (n % 10) + '0';
		n = n / 10;
	}
	return (nbr);
}
