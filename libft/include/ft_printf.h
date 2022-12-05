/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 05:24:32 by arobu             #+#    #+#             */
/*   Updated: 2022/12/04 23:29:17 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAGS "-+0 #"
# define SPECS "cspdiouxX%"
# define WIDTH "0123456789"
# define PRECISION ".0123456789"
# define BASE_HEX_MINOR "0123456789abcdef"
# define BASE_HEX_MAJOR "0123456789ABCDEF"
# define BASE_DECIMAL "0123456789"

# include "libft.h"

typedef struct s_flags
{
	size_t		isprovided;
	size_t		hash;
	size_t		zero;
	size_t		plus;
	size_t		minus;
	size_t		space;
}				t_flags;

typedef struct s_options
{
	int			isprovided;
	size_t		valuegiven;
	size_t		padding;
	char		*padding_field;
}				t_options;

typedef struct s_sign
{
	int		has_sign;
	int		is_negative;
	char	*sign;
}				t_sign;

typedef struct s_flag
{
	size_t	flag_len;
	size_t	left_justify;
	size_t	zero_padded;
	char	*flag;
}				t_flag;

typedef struct s_fields
{
	t_flags		flags;
	t_flag		flag;
	t_sign		sign;
	t_options	width;
	t_options	precision;
	size_t		empty_str;
	size_t		empty_ptr;
	size_t		plus_zero_prec;
	size_t		msz_prec;
	size_t		buff_index;
	size_t		format_index;
	size_t		bytes_to_skip;
	size_t		ndigits;
	char		specifier;
}				t_fields;

t_fields	ft_init_field(void);
void		ft_reset_field(t_fields *field);

size_t		ft_printf(const char *format, ...);
size_t		ft_print(const char *format, va_list args);

void		ft_handle_args(const char *format, \
						t_fields *field, va_list args);

size_t		ft_get_flags(t_fields *field, const char *format);
size_t		ft_get_width(t_fields *field, const char *format);
size_t		ft_get_precision(t_fields *field, const char *format);
size_t		ft_get_specifier(t_fields *field, const char *format);
size_t		ft_handle_options(t_fields *field, const char *format);
size_t		ft_count_digits(long n, char *base);
size_t		ft_count_udigits(uintmax_t n, char *base);

char		*ft_handle_specifier_s(t_fields *field, void *data);
char		*ft_handle_specifier_p(t_fields *field, void *data);
char		*ft_handle_specifier_di(t_fields *field, void *data);
char		*ft_handle_specifier_u(t_fields *field, void *data);
char		*ft_handle_specifier_x(t_fields *field, void *data);
char		*ft_handle_specifier_percent(t_fields *field);

void		ft_validate_specifier_s(t_fields *field);
void		ft_validate_specifier_di(t_fields *field);
void		ft_validate_specifier_p(t_fields *field);
void		ft_validate_specifier_u(t_fields *field);
void		ft_validate_specifier_x(t_fields *field);
void		ft_validate_specifier_percent(t_fields *field);
void		ft_print_str(char *str, size_t size, int fd, t_fields *field);

void		ft_create_precision(t_fields *field);
void		ft_create_width(t_fields *field);

char		*ft_create_string_s(va_list args, t_fields *field);
char		*ft_create_string_p(va_list args, t_fields *field);
char		*ft_create_string_di(va_list args, t_fields *field);
char		*ft_create_string_u(va_list args, t_fields *field);
char		*ft_create_string_x(va_list args, t_fields *field);
char		*ft_create_string_percent(t_fields *field);
char		*ft_create_string(va_list args, t_fields *field);

char		*ft_itoa_pbase(uintmax_t n, const char *base);
void		ft_process_flags(t_fields *field);
void		ft_add_width_c(char **str, char c, t_fields *field, size_t *size);

char		*ft_handle_specifier(va_list args, t_fields *field);
char		*ft_add_precision(char **str, t_fields *field);
char		*ft_strnew(char c);
char		*ft_strdup_spec_s(char *str);
char		*ft_strdup_spec_p(char *str);

#endif
