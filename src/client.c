/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:57:26 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/10 22:04:20 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	sigusr_handler(int signum);
static void	init_sigaction(struct sigaction *sa);
static int	send_message(int server_pid, char *message);

int	main(int argc, char **argv)
{
	int					server_pid;
	struct sigaction	sa;

	if (argc != 3)
		ft_put_error(NARG_ERR);
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0 || server_pid > 99999)
		ft_put_error(PID_ERR);
	init_sigaction(&sa);
	ft_printf("%sPID: %i%s\n", CYAN, getpid(), RESET);
	if (send_message(server_pid, argv[2]))
		ft_put_error(NEXIST_ERR);
	if (!sleep(TIMEOUT))
		ft_put_error(TIMEOUT_ERR);
}

static void	sigusr_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("%sKO%s\n", RED, RESET);
	else if (signum == SIGUSR2)
		ft_printf("%sOK%s\n", GREEN, RESET);
	exit (signum == SIGUSR2);
}

static void	init_sigaction(struct sigaction *sa)
{
	sigemptyset(&sa->sa_mask);
	sa->sa_flags = SA_RESTART;
	sa->sa_handler = sigusr_handler;
	sigaction(SIGUSR1, sa, NULL);
	sigaction(SIGUSR2, sa, NULL);
}

static int	send_message(int server_pid, char *message)
{
	int	error;

	error = ft_send_number(server_pid, ft_str_len(message));
	while (*message && !error)
	{
		error = ft_send_char(server_pid, *message);
		message++;
	}
	if (!error)
		ft_send_char(server_pid, 0);
	return (error);
}
