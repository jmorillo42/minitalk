/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:59:25 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/03 14:09:28 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	print_text_position(t_fmt_text *ftext)
{
	int	count;

	count = ft_put_char(ftext->text[ftext->position]);
	if (count < 0)
		ftext->count = count;
	else
		ftext->count += count;
	ftext->position++;
}
