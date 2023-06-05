/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:54:11 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/10 20:10:17 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

int	ft_send_number(pid_t server_pid, unsigned int number)
{
	int	i;
	int	bit;
	int	error;

	i = 0;
	error = 0;
	while (i < 32 && !error)
	{
		bit = number & (1 << i);
		error = ft_send_bit(server_pid, bit);
		i++;
	}
	return (error);
}
