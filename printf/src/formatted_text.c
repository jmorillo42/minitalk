/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatted_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:09:50 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/03 14:08:20 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	reset_options(t_fmt_text *ftext)
{
	ftext->type = 0;
	ftext->width = 0;
	ftext->precision = 0;
	ftext->dot_flag = 0;
	ftext->minus_flag = 0;
	ftext->plus_flag = 0;
	ftext->sharp_flag = 0;
	ftext->space_flag = 0;
	ftext->zero_flag = 0;
}

void	init_fmt_text(t_fmt_text **ftext, const char *text)
{
	*ftext = malloc(sizeof(t_fmt_text));
	if (!*ftext)
		return ;
	(*ftext)->text = (char *) text;
	(*ftext)->position = 0;
	(*ftext)->count = 0;
}

int	end_fmt_text(t_fmt_text **ftext)
{
	int	chars_count;

	chars_count = (*ftext)->count;
	va_end((*ftext)->arguments);
	free(*ftext);
	*ftext = NULL;
	return (chars_count);
}
