/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:38:23 by arobu             #+#    #+#             */
/*   Updated: 2022/11/05 17:04:09 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_init_field_helper(t_fields *field)
{
	field->flags.isprovided = 0;
	field->flags.hash = 0;
	field->flags.space = 0;
	field->flags.plus = 0;
	field->flags.minus = 0;
	field->flags.zero = 0;
	field->flag.flag = NULL;
	field->flag.flag_len = 0;
	field->flag.flag = 0;
	field->flag.left_justify = 0;
	field->flag.zero_padded = 0;
	field->sign.has_sign = 0;
	field->sign.is_negative = 0;
	field->sign.sign = NULL;
	field->specifier = 0;
	field->plus_zero_prec = 0;
	field->msz_prec = 0;
	field->empty_str = 0;
	field->buff_index = 0;
	field->format_index = 0;
	field->bytes_to_skip = 0;
	field->empty_ptr = 0;
}

static void	ft_init_pw(t_fields *field)
{
	field->precision.isprovided = 0;
	field->precision.valuegiven = 0;
	field->precision.padding = 0;
	field->precision.padding_field = NULL;
	field->width.isprovided = 0;
	field->width.valuegiven = 0;
	field->width.padding = 0;
	field->width.padding_field = NULL;
}

static void	ft_reset_field_helper(t_fields *field)
{
	field->flags.isprovided = 0;
	field->flags.hash = 0;
	field->flags.space = 0;
	field->flags.plus = 0;
	field->flags.minus = 0;
	field->flags.zero = 0;
	field->flag.flag = NULL;
	field->flag.flag_len = 0;
	field->sign.has_sign = 0;
	field->sign.is_negative = 0;
	field->sign.sign = NULL;
	field->flag.left_justify = 0;
	field->flag.zero_padded = 0;
	field->specifier = 0;
	field->plus_zero_prec = 0;
	field->msz_prec = 0;
	field->empty_str = 0;
	field->empty_ptr = 0;
}

t_fields	ft_init_field(void)
{
	t_fields	field;

	ft_init_field_helper(&field);
	ft_init_pw(&field);
	return (field);
}

void	ft_reset_field(t_fields *field)
{
	ft_reset_field_helper(field);
	field->precision.isprovided = 0;
	field->precision.valuegiven = 0;
	field->precision.padding = 0;
	field->precision.padding_field = NULL;
	field->width.isprovided = 0;
	field->width.valuegiven = 0;
	field->width.padding = 0;
	field->width.padding_field = NULL;
	field->bytes_to_skip = 0;
}
