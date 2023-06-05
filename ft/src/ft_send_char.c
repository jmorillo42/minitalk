/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:54:07 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/10 20:10:12 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

int	ft_send_char(pid_t server_pid, unsigned char character)
{
	int	i;
	int	bit;
	int	error;

	i = 0;
	error = 0;
	while (i < 8 && !error)
	{
		bit = character & (1 << i);
		error = ft_send_bit(server_pid, bit);
		i++;
	}
	return (error);
}
