/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:22:02 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/10 21:59:16 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

static void	sigusr_handler(int signum, siginfo_t *info, void *uap);
static void	print_message(char c, unsigned int *len, int pid);

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sa.sa_sigaction = sigusr_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("%sPID: %i%s\n", CYAN, getpid(), RESET);
	while (1)
		pause();
}

static void	sigusr_handler(int signum, siginfo_t *info, void *dummy)
{
	static unsigned int		bitpos = 0;
	static unsigned char	character = 0;
	static unsigned int		length = 0;
	static int				number = 1;

	(void)dummy;
	if (!number && signum == SIGUSR2)
		character |= 1 << bitpos;
	else if (number && signum == SIGUSR2)
		length |= 1 << bitpos;
	bitpos++;
	if (number && bitpos == 32)
	{
		number = 0;
		bitpos = 0;
	}
	else if (!number && bitpos == 8)
	{
		print_message(character, &length, info->si_pid);
		if (!character)
			number = 1;
		bitpos = 0;
		character = 0;
	}
}

static void	print_message(char c, unsigned int *len, int pid)
{
	if (c && *len > 0)
	{
		write(1, &c, 1);
		(*len)--;
	}
	else if (!c && *len == 0)
	{
		ft_printf("%s<PID:%i>%s\n", CYAN, pid, RESET);
		kill(pid, SIGUSR2);
	}
	else
	{
		kill(pid, SIGUSR1);
		*len = 0;
	}
}
