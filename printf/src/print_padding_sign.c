/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding_sign.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:45:08 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/03 14:09:17 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static size_t	calc_left_pad(t_fmt_text *ftext, size_t length, size_t sign);
static size_t	calc_right_pad(t_fmt_text *ftext, size_t length, size_t sign);
static size_t	length_unsigned(size_t length, int is_negative);

void	print_padding_sign(t_fmt_text *ftext, size_t length, int is_negative)
{
	size_t	left_pad;
	size_t	right_pad;
	size_t	sign;
	size_t	len_unsigned;

	sign = (is_negative || ftext->plus_flag || ftext->space_flag);
	len_unsigned = length_unsigned(length, is_negative);
	right_pad = calc_right_pad(ftext, len_unsigned, sign);
	left_pad = calc_left_pad(ftext, len_unsigned + right_pad, sign);
	update_count(ftext, ft_put_char_rep(' ', left_pad));
	if (is_negative)
		update_count(ftext, ft_put_char('-'));
	else if (ftext->plus_flag)
		update_count(ftext, ft_put_char('+'));
	else if (ftext->space_flag)
		update_count(ftext, ft_put_char(' '));
	update_count(ftext, ft_put_char_rep('0', right_pad));
}

static size_t	calc_left_pad(t_fmt_text *ftext, size_t length, size_t sign)
{
	size_t	result;

	result = 0;
	if (ftext->precision > length)
		length = ftext->precision;
	if (ftext->width > (length + sign) && !ftext->minus_flag)
		result = ftext->width - length - sign;
	return (result);
}

static size_t	calc_right_pad(t_fmt_text *ftext, size_t length, size_t sign)
{
	size_t	result;

	result = 0;
	if (ftext->precision > length)
		result = ftext->precision - length;
	if (!ftext->minus_flag && ftext->zero_flag
		&& !ftext->dot_flag && ftext->width > length)
		result = ftext->width - length - sign;
	return (result);
}

static size_t	length_unsigned(size_t length, int is_negative)
{
	if (is_negative)
		length--;
	return (length);
}
