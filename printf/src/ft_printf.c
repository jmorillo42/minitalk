/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 10:44:24 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/03 14:08:35 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int	ft_printf(char const *text, ...)
{
	t_fmt_text	*ftext;

	if (!text)
		return (-1);
	init_fmt_text(&ftext, text);
	if (!ftext)
		return (-1);
	va_start(ftext->arguments, text);
	while (ftext->count >= 0 && text[ftext->position])
	{
		if (text[ftext->position] == VBLE_MARK)
			print_argument(ftext);
		else
			print_text_position(ftext);
	}
	return (end_fmt_text(&ftext));
}
