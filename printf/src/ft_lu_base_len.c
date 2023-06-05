/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lu_base_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:37:39 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/03 14:08:33 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

size_t	ft_lu_base_len(unsigned long number, unsigned int base)
{
	size_t	count;

	count = 0;
	if (number <= 0)
		count++;
	while (number)
	{
		number = number / base;
		count++;
	}
	return (count);
}
