/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:00:21 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/03 14:34:57 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

/*
* Length of the text string (str). If null, returns zero.
*/
size_t	ft_str_len(const char *str)
{
	size_t	count;

	count = 0;
	if (str)
		while (str[count])
			count++;
	return (count);
}
