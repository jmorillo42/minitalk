/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 22:12:27 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/03 14:08:44 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int	ft_put_char(char c)
{
	return (write(1, &c, 1));
}
