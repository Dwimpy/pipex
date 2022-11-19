/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_specifier_s.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 08:48:27 by arobu             #+#    #+#             */
/*   Updated: 2022/11/05 16:54:57 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_validate_specifier_s(t_fields *field)
{
	if (field -> flags.space)
		field -> flags.space = 0;
	if (field -> flags.hash)
		field -> flags.hash = 0;
	if (field -> flags.zero)
		field -> flags.zero = 0;
	if (field -> flags.space)
		field -> flags.space = 0;
	return ;
}
