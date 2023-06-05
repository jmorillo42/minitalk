/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 09:49:43 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/03 14:09:22 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

#define HEX_BASE 16

static void	print_long(unsigned long number, t_fmt_text *ftext);

void	print_pointer(t_fmt_text *ftext)
{
	unsigned long	number;
	size_t			padding;
	size_t			len;

	number = va_arg(ftext->arguments, unsigned long);
	len = ft_lu_base_len(number, 16) + 2;
	padding = calculate_padding(ftext, len);
	if (!ftext->minus_flag)
		print_padding(ftext, padding);
	update_count(ftext, ft_put_str("0x"));
	print_long(number, ftext);
	if (ftext->minus_flag)
		print_padding(ftext, padding);
}

static void	print_long(unsigned long number, t_fmt_text *ftext)
{
	if (number >= HEX_BASE)
	{
		print_long(number / HEX_BASE, ftext);
		number = number % HEX_BASE;
	}
	update_count(ftext, ft_put_char(HEX_LOW_BASE[number]));
}
