/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:43:51 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/03 14:09:05 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static void	print_formatted(t_fmt_text *ftext);

void	print_argument(t_fmt_text *ftext)
{
	parse_argument(ftext);
	if (ftext->count < 0)
		return ;
	print_formatted(ftext);
}

static void	print_formatted(t_fmt_text *ftext)
{
	if (ftext->type == CHAR_TYPE || ftext->type == VBLE_MARK)
		print_character(ftext);
	else if (ftext->type == STRING_TYPE)
		print_string(ftext);
	else if (ftext->type == DECIMAL_TYPE)
		print_integer(ftext);
	else if (ftext->type == UNSIGNED_TYPE)
		print_unsigned(ftext);
	else if (ftext->type == HEX_LOW_TYPE || ftext->type == HEX_UP_TYPE)
		print_hexadecimal(ftext);
	else if (ftext->type == POINTER_TYPE)
		print_pointer(ftext);
}
