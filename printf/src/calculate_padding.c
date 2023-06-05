/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:23:06 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/03 14:08:09 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

size_t	calculate_padding(t_fmt_text *ftext, size_t	length)
{
	if (ftext->width > length)
		return (ftext->width - length);
	return (0);
}
