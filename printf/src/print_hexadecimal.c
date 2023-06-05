/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 09:49:43 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/03 14:09:12 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

#define HEX_BASE 16

static size_t	hex_len(unsigned int number);
static void		print_number(unsigned int number, char *base,
					t_fmt_text *ftext);
static void		print_left_padding(t_fmt_text *ftext, unsigned int number);
static void		print_sharp(t_fmt_text *ftext, unsigned int number);

void	print_hexadecimal(t_fmt_text *ftext)
{
	char			*base;
	unsigned int	number;
	int				count;

	if (ftext->type == HEX_LOW_TYPE)
		base = HEX_LOW_BASE;
	else
		base = HEX_UP_BASE;
	number = va_arg(ftext->arguments, unsigned int);
	count = ftext->count;
	print_left_padding(ftext, number);
	print_number(number, base, ftext);
	count = ftext->count - count;
	if (ftext->minus_flag && count >= 0 && (int) ftext->width > count)
		print_padding(ftext, ftext->width - count);
}

static	size_t	hex_len(unsigned int number)
{
	size_t	count;

	count = 0;
	if (!number)
		count = 1;
	while (number)
	{
		number = number / HEX_BASE;
		count++;
	}
	return (count);
}

static void	print_number(unsigned int number, char *base, t_fmt_text *ftext)
{
	if (ftext->dot_flag && !ftext->precision && !number)
		return ;
	if (number >= HEX_BASE)
	{
		print_number(number / HEX_BASE, base, ftext);
		number = number % HEX_BASE;
	}
	update_count(ftext, ft_put_char(base[number]));
}

static void	print_left_padding(t_fmt_text *ftext, unsigned int number)
{
	size_t	left_pad;
	size_t	right_pad;
	size_t	len_sharp;
	size_t	length;

	length = hex_len(number)
		* !(!number && ftext->dot_flag && !ftext->precision);
	len_sharp = 2 * !(!ftext->sharp_flag || !number);
	right_pad = 0;
	if (ftext->precision > length)
		right_pad = ftext->precision - length;
	if (!ftext->minus_flag && ftext->zero_flag
		&& !ftext->dot_flag && ftext->width > length)
		right_pad = ftext->width - length - len_sharp;
	left_pad = 0;
	if (ftext->width > (length + len_sharp + right_pad) && !ftext->minus_flag)
		left_pad = ftext->width - length - len_sharp - right_pad;
	update_count(ftext, ft_put_char_rep(' ', left_pad));
	print_sharp(ftext, number);
	update_count(ftext, ft_put_char_rep('0', right_pad));
}

static void	print_sharp(t_fmt_text *ftext, unsigned int number)
{
	if (!ftext->sharp_flag || !number)
		return ;
	update_count(ftext, ft_put_char('0'));
	update_count(ftext, ft_put_char(ftext->type));
}
