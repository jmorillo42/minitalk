/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:04:10 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/09 19:26:07 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

/*
* Prints the error message (str) on the terminal error output (stderr) and exit.
*/
void	ft_put_error(char *str)
{
	if (str)
	{
		write(STDERR_FILENO, "\x1b[31m", 5);
		write(STDERR_FILENO, str, ft_str_len(str));
		write(STDERR_FILENO, "\x1b[0m", 4);
	}
	exit (1);
}
