/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:40:27 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/03 14:09:10 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static char	get_char_to_print(t_fmt_text *ftext);

void	print_character(t_fmt_text *ftext)
{
	size_t	padding;

	padding = calculate_padding(ftext, 1);
	if (!ftext->minus_flag)
		print_padding(ftext, padding);
	update_count(ftext, ft_put_char(get_char_to_print(ftext)));
	if (ftext->minus_flag)
		print_padding(ftext, padding);
}

static char	get_char_to_print(t_fmt_text *ftext)
{
	if (ftext->type == VBLE_MARK)
		return (VBLE_MARK);
	else
		return (va_arg(ftext->arguments, int));
}
