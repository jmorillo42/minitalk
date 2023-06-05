/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:56:16 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/03 14:09:31 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static size_t	calculate_length(t_fmt_text *ftext, unsigned int number);
static void		print_number(t_fmt_text *ftext, unsigned int number);
static size_t	calc_left_pad(t_fmt_text *ftext, size_t length);
static size_t	calc_right_pad(t_fmt_text *ftext, size_t length);

void	print_unsigned(t_fmt_text *ftext)
{
	unsigned int	number;
	int				count;
	size_t			length;
	size_t			left_pad;
	size_t			right_pad;

	number = va_arg(ftext->arguments, unsigned int);
	length = calculate_length(ftext, number);
	count = ftext->count;
	right_pad = calc_right_pad(ftext, length);
	left_pad = calc_left_pad(ftext, length + right_pad);
	update_count(ftext, ft_put_char_rep(' ', left_pad));
	update_count(ftext, ft_put_char_rep('0', right_pad));
	print_number(ftext, number);
	count = ftext->count - count;
	if (ftext->minus_flag && count >= 0 && (int) ftext->width > count)
		print_padding(ftext, ftext->width - count);
}

static void	print_number(t_fmt_text *ftext, unsigned int number)
{
	if (ftext->dot_flag && !ftext->precision && !number)
		return ;
	if (number < 10)
		update_count(ftext, ft_put_char(number + 48));
	else
	{
		print_number(ftext, number / 10);
		update_count(ftext, ft_put_char(number % 10 + 48));
	}
}

static size_t	calculate_length(t_fmt_text *ftext, unsigned int number)
{
	size_t	len;

	len = ft_ui_len(number);
	if (ftext->dot_flag && !ftext->precision && !number)
		len = 0;
	return (len);
}

static size_t	calc_left_pad(t_fmt_text *ftext, size_t length)
{
	size_t	result;

	result = 0;
	if (ftext->precision > length)
		length = ftext->precision;
	if (ftext->width > length && !ftext->minus_flag)
		result = ftext->width - length;
	return (result);
}

static size_t	calc_right_pad(t_fmt_text *ftext, size_t length)
{
	size_t	result;

	result = 0;
	if (ftext->precision > length)
		result = ftext->precision - length;
	if (!ftext->minus_flag && ftext->zero_flag
		&& !ftext->dot_flag && ftext->width > length)
		result = ftext->width - length;
	return (result);
}
