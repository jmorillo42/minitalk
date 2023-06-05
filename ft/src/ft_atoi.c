/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:48:01 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/08 19:51:39 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ZERO 48
#define NINE 57
#define SPACE 32
#define TAB 9
#define RETURN 13

/*
* Converts a text string (str) to an integer. If it is not a number, returns
* zero.
*/
int	ft_atoi(const char *str)
{
	int	i;
	int	result;

	result = 0;
	i = 0;
	while ((str[i] >= TAB && str[i] <= RETURN) || str[i] == SPACE)
		i++;
	while (str[i] >= ZERO && str[i] <= NINE)
	{
		result = result * 10 + (str[i] - ZERO);
		i++;
	}
	return (result);
}
