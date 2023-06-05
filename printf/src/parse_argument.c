/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:54:50 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/03 14:09:03 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static void	parse_argument_flags(t_fmt_text *ftext);
static void	parse_argument_width(t_fmt_text *ftext);
static void	parse_argument_precision(t_fmt_text *ftext);
static void	parse_argument_type(t_fmt_text *ftext);

void	parse_argument(t_fmt_text *ftext)
{
	reset_options(ftext);
	ftext->position++;
	parse_argument_flags(ftext);
	parse_argument_width(ftext);
	parse_argument_precision(ftext);
	parse_argument_type(ftext);
}

static void	parse_argument_flags(t_fmt_text *ftext)
{
	while (ftext->text[ftext->position])
	{
		if (ftext->text[ftext->position] == MINUS_FLAG)
			ftext->minus_flag = 1;
		else if (ftext->text[ftext->position] == PLUS_FLAG)
			ftext->plus_flag = 1;
		else if (ftext->text[ftext->position] == SHARP_FLAG)
			ftext->sharp_flag = 1;
		else if (ftext->text[ftext->position] == SPACE_FLAG)
			ftext->space_flag = 1;
		else if (ftext->text[ftext->position] == ZERO_FLAG)
			ftext->zero_flag = 1;
		else
			break ;
		ftext->position++;
	}
}

static void	parse_argument_width(t_fmt_text *ftext)
{
	if (ft_is_digit(ftext->text[ftext->position]))
	{
		ftext->width = ft_atoz(ftext->text + ftext->position);
		while (ft_is_digit(ftext->text[ftext->position]))
			ftext->position++;
	}
}

static void	parse_argument_precision(t_fmt_text *ftext)
{
	if (ftext->text[ftext->position] == DOT_FLAG)
	{
		ftext->dot_flag = 1;
		ftext->position++;
		ftext->precision = ft_atoz(ftext->text + ftext->position);
		while (ft_is_digit(ftext->text[ftext->position]))
			ftext->position++;
	}
}

static void	parse_argument_type(t_fmt_text *ftext)
{
	char	current_char;

	current_char = ftext->text[ftext->position];
	if (ftext->text[ftext->position] == INT_TYPE)
		ftext->type = DECIMAL_TYPE;
	else if (current_char == VBLE_MARK
		|| current_char == CHAR_TYPE
		|| current_char == STRING_TYPE
		|| current_char == POINTER_TYPE
		|| current_char == DECIMAL_TYPE
		|| current_char == UNSIGNED_TYPE
		|| current_char == HEX_LOW_TYPE
		|| current_char == HEX_UP_TYPE)
		ftext->type = current_char;
	else
		ftext->count = -1;
	ftext->position++;
}
