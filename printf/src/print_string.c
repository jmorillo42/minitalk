/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:22:17 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/03 14:09:24 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static size_t	calc_length(t_fmt_text *ftext, char	*str);

void	print_string(t_fmt_text *ftext)
{
	char	*arg_str;
	size_t	length;
	size_t	padding;

	arg_str = va_arg(ftext->arguments, char *);
	if (!arg_str)
		arg_str = NULL_STR;
	length = calc_length(ftext, arg_str);
	padding = calculate_padding(ftext, length);
	if (!ftext->minus_flag)
		print_padding(ftext, padding);
	update_count(ftext, ft_put_str_len(arg_str, length));
	if (ftext->minus_flag)
		print_padding(ftext, padding);
}

static size_t	calc_length(t_fmt_text *ftext, char	*str)
{
	size_t	length;

	length = ft_str_len(str);
	if (ftext->dot_flag && ftext->precision < length)
		length = ftext->precision;
	return (length);
}
