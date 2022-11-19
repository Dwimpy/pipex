/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_width_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 02:03:49 by arobu             #+#    #+#             */
/*   Updated: 2022/11/05 19:18:22 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char	*ft_create_width_c(t_fields *field)
{
	char	*width;

	if (field -> flags.zero)
		width = ft_strnew_zeros(field -> width.valuegiven - 1, '0');
	else
		width = ft_strnew_zeros(field -> width.valuegiven - 1, ' ');
	return (width);
}

static size_t	ft_create_string_c(char **str, char c, \
								size_t len, t_fields *field)
{
	size_t	size;

	size = 0;
	if (field->flags.minus)
	{
		ft_memset(*str, c, 1);
		ft_memset(*str + 1, ' ', len);
		size = len + 1;
	}	
	else
	{
		ft_memset(*str, ' ', len);
		ft_memset(*str + len, c, 1);
		size = len + 1;
	}
	return (size);
}

void	ft_add_width_c(char **str, char c, t_fields *field, size_t *size)
{
	char	*width;
	size_t	width_len;

	width = (NULL);
	if ((int)field -> width.valuegiven - 1 <= 0)
		field -> width.valuegiven = 0;
	if (field -> width.valuegiven == 0)
	{
		*str = malloc(sizeof(char) * 2);
		ft_memset(*str, c, 1);
		*size += 1;
	}
	if (field -> width.valuegiven > 0)
	{
		width = ft_create_width_c(field);
		width_len = ft_strlen(width);
		*str = malloc(sizeof(char) * (width_len + 1));
		*size = ft_create_string_c(str, c, width_len, field);
		free(width);
	}
}
