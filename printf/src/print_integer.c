/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:56:16 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/03 14:09:15 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static size_t	calculate_length(t_fmt_text *ftext, int number);
static char		digit_to_char(int n);
static void		print_number(t_fmt_text *ftext, int number);

void	print_integer(t_fmt_text *ftext)
{
	int		number;
	size_t	len;
	int		count;

	number = va_arg(ftext->arguments, int);
	len = calculate_length(ftext, number);
	count = ftext->count;
	print_padding_sign(ftext, len, number < 0);
	print_number(ftext, number);
	count = ftext->count - count;
	if (ftext->minus_flag && count >= 0 && (int) ftext->width > count)
		print_padding(ftext, ftext->width - count);
}

static void	print_number(t_fmt_text *ftext, int number)
{
	if (ftext->dot_flag && !ftext->precision && !number)
		return ;
	if (number > -10 && number < 10)
		update_count(ftext, ft_put_char(digit_to_char(number)));
	else
	{
		print_number(ftext, number / 10);
		update_count(ftext, ft_put_char(digit_to_char(number % 10)));
	}
}

static char	digit_to_char(int n)
{
	if (n < 0)
		n = -n;
	return ((unsigned char)n + 48);
}

static size_t	calculate_length(t_fmt_text *ftext, int number)
{
	size_t	len;

	len = ft_int_len(number);
	if (ftext->dot_flag && !ftext->precision && !number)
		len = 0;
	return (len);
}
