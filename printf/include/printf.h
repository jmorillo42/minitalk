/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:09:49 by jmorillo          #+#    #+#             */
/*   Updated: 2022/10/08 20:38:29 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define VBLE_MARK '%'

# define CHAR_TYPE 'c'
# define STRING_TYPE 's'
# define POINTER_TYPE 'p'
# define DECIMAL_TYPE 'd'
# define INT_TYPE 'i'
# define UNSIGNED_TYPE 'u'
# define HEX_LOW_TYPE 'x'
# define HEX_UP_TYPE 'X'

# define DOT_FLAG '.'
# define MINUS_FLAG '-'
# define PLUS_FLAG '+'
# define SHARP_FLAG '#'
# define SPACE_FLAG ' '
# define ZERO_FLAG '0'

# define NULL_STR "(null)"
# define HEX_LOW_BASE "0123456789abcdef"
# define HEX_UP_BASE "0123456789ABCDEF"

typedef struct s_fmt_text
{
	char			*text;
	va_list			arguments;
	size_t			position;
	int				count;
	char			type;
	size_t			width;
	size_t			precision;
	unsigned int	dot_flag;
	unsigned int	minus_flag;
	unsigned int	plus_flag;
	unsigned int	sharp_flag;
	unsigned int	space_flag;
	unsigned int	zero_flag;
}	t_fmt_text;

int		ft_printf(char const *text, ...);

size_t	ft_atoz(char *str);
size_t	ft_int_len(int number);
int		ft_is_digit(char c);
size_t	ft_lu_base_len(unsigned long number, unsigned int base);
int		ft_put_char(char c);
int		ft_put_char_rep(char c, size_t count);
int		ft_put_str(char *str);
int		ft_put_str_len(char *str, size_t length);
size_t	ft_str_len(const char *s);
size_t	ft_ui_len(unsigned int number);

size_t	calculate_padding(t_fmt_text *ftext, size_t	length);
int		end_fmt_text(t_fmt_text **ftext);
void	init_fmt_text(t_fmt_text **ftext, const char *text);
void	print_text_position(t_fmt_text *ftext);
void	parse_argument(t_fmt_text *ftext);
void	print_argument(t_fmt_text *ftext);
void	print_character(t_fmt_text *ftext);
void	print_hexadecimal(t_fmt_text *ftext);
void	print_integer(t_fmt_text *ftext);
void	print_padding(t_fmt_text *ftext, size_t length);
void	print_padding_sign(t_fmt_text *ftext, size_t length, int is_negative);
void	print_pointer(t_fmt_text *ftext);
void	print_string(t_fmt_text *ftext);
void	print_unsigned(t_fmt_text *ftext);
void	reset_options(t_fmt_text *ftext);
void	update_count(t_fmt_text *ftext, int count);

#endif
