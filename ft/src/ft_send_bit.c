/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_bit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:51:38 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/10 21:58:30 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

/*
* Sends one bit to a process with "server_pid" using user defined signals. After
* sending the signal, a delay of SIGNAL_DELAY microseconds is performed.
* If everything is correct returns 0. Otherwise, -1 is returned.
*/
int	ft_send_bit(pid_t server_pid, int bit)
{
	int	result;

	if (bit)
		result = kill(server_pid, SIGUSR2);
	else
		result = kill(server_pid, SIGUSR1);
	if (!result)
		result = usleep(SIGNAL_DELAY);
	return (result);
}
