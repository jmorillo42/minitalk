/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:04:13 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/10 21:57:36 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

# define SIGNAL_DELAY 350

int		ft_atoi(const char *str);
void	ft_put_error(char *str);
int		ft_send_bit(pid_t server_pid, int bit);
int		ft_send_char(pid_t server_pid, unsigned char character);
int		ft_send_number(pid_t server_pid, unsigned int number);
size_t	ft_str_len(const char *str);

#endif
