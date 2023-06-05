
NAME			=	minitalk
CLIENT			=	client
SERVER			=	server

SRC_DIR			=	src/
OBJ_DIR			=	obj
FT_DIR			=	ft/
PRINTF_DIR		=	printf/
BONUS_DIR		=	bonus/

PRINTF_LIB		=	./printf/libprintf.a
FT_LIB			=	./ft/libft.a

CC				=	gcc
CC_FLAGS		=	-Wall -Wextra -Werror

RM_OBJ			=	rm -rf $(OBJ_DIR)

SRCS			=	server.c \
					client.c

OBJS			=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

SRCS_BONUS		=	server_bonus.c \
					client_bonus.c

OBJS_BONUS		=	$(SRCS_BONUS:%.c=$(OBJ_DIR)/%.o)

all:				$(NAME)

$(OBJ_DIR)/%.o:		$(SRC_DIR)%.c
					$(CC) $(CC_FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o:		$(BONUS_DIR)%.c
					$(CC) $(CC_FLAGS) -c $< -o $@

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

$(FT_LIB):
					$(MAKE) -C $(FT_DIR)

$(PRINTF_LIB):
					$(MAKE) -C $(PRINTF_DIR)

$(NAME):			$(OBJ_DIR) $(OBJS) $(FT_LIB) $(PRINTF_LIB) $(CLIENT) $(SERVER)

$(CLIENT):
					$(CC) $(CC_FLAGS) obj/client.o $(PRINTF_LIB) $(FT_LIB) -o $(CLIENT)

$(SERVER):
					$(CC) $(CC_FLAGS) obj/server.o $(PRINTF_LIB) $(FT_LIB) -o $(SERVER)

bonus:				$(OBJ_DIR) $(OBJS_BONUS) $(FT_LIB) $(PRINTF_LIB)
					$(CC) $(CC_FLAGS) obj/client_bonus.o $(PRINTF_LIB) $(FT_LIB) -o $(CLIENT)
					$(CC) $(CC_FLAGS) obj/server_bonus.o $(PRINTF_LIB) $(FT_LIB) -o $(SERVER)

clean:
					$(RM_OBJ)
					$(MAKE) -C $(FT_DIR) fclean
					$(MAKE) -C $(PRINTF_DIR) fclean

fclean:				clean
					rm -f $(CLIENT)
					rm -f $(SERVER)

re:					fclean all

.PHONY:				all bonus clean fclean re
