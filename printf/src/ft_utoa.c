/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:37:25 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/03 14:08:59 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static size_t	number_len(unsigned int n);

char	*ft_utoa(unsigned int n)
{
	char	*result;
	size_t	pos;
	size_t	digits;

	digits = number_len(n);
	result = malloc(digits + 1);
	if (!result)
		return (result);
	result[digits] = 0;
	if (n == 0)
		result[0] = '0';
	pos = digits - 1;
	while (n)
	{
		result[pos] = n % 10 + 48;
		n = n / 10;
		pos--;
	}
	return (result);
}

static size_t	number_len(unsigned int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		count++;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}
