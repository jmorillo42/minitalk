/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:18:05 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/03 14:09:34 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	update_count(t_fmt_text *ftext, int count)
{
	if (ftext->count >= 0 && count > 0)
		ftext->count += count;
	else if (count < 0)
		ftext->count = -1;
}
