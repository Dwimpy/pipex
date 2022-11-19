/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_specifier_di.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 08:48:27 by arobu             #+#    #+#             */
/*   Updated: 2022/11/05 16:54:49 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_validate_specifier_di(t_fields *field)
{
	if (field -> flags.plus && field -> flags.space)
		field -> flags.space = 0;
	if (field -> flags.zero && field -> flags.minus && field->width.isprovided)
		field -> flags.zero = 0;
	if (field -> flags.zero && field -> precision.isprovided)
		field -> flags.zero = 0;
	return ;
}
