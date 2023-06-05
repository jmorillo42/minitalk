/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ui_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:31:54 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/03 14:08:57 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

size_t	ft_ui_len(unsigned int number)
{
	size_t	count;

	count = 0;
	if (!number)
		count = 1;
	while (number)
	{
		number = number / 10;
		count++;
	}
	return (count);
}
