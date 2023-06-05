
NAME			=	libprintf.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

SRC_DIR			=	src
SRCS			=	ft_printf.c \
					calculate_padding.c \
					formatted_text.c \
					ft_atoz.c \
					ft_int_len.c \
					ft_is_digit.c \
					ft_lu_base_len.c \
					ft_put_char.c \
					ft_put_char_rep.c \
					ft_put_str.c \
					ft_put_str_len.c \
					ft_str_len.c \
					ft_ui_len.c \
					parse_argument.c \
					print_argument.c \
					print_character.c \
					print_hexadecimal.c \
					print_integer.c \
					print_padding.c \
					print_padding_sign.c \
					print_pointer.c \
					print_string.c \
					print_text_position.c \
					print_unsigned.c \
					update_count.c

OBJ_DIR			=	obj
OBJS			=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(OBJ_DIR) $(OBJS)
					$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
