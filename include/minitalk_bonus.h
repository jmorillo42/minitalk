/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:58:11 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/10 22:04:08 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include "../printf/include/printf.h"
# include "../ft/include/ft.h"

# define CYAN "\x1b[36m"
# define GREEN "\x1b[32m"
# define RED "\x1b[31m"
# define RESET "\x1b[0m"

# define NARG_ERR "Error: Número de argumentos incorrectos.\n"
# define PID_ERR "Error: El PID no es correcto.\n"
# define NEXIST_ERR "Error: No existe el proceso servidor.\n"
# define TIMEOUT_ERR "Error: Se superó el tiempo de envío.\n"

# define TIMEOUT 30

#endif
