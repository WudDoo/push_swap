 # -*- MakeFile -*-

NAME		=	push_swap
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -g
RM			=	rm -rf

C_FILES	=	push_swap.c stack.c op_swap.c op_push.c op_rotate.c op_reverse_rotate.c stack_utils.c stack_utils2.c utils.c sort.c

SRC_DIR	=	src
OBJ_DIR	=	obj

SRCS		=	$(addprefix $(SRC_DIR)/, $(C_FILES))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(C_FILES:%.c=%.o))

.PHONY:		all val clean fclean re

all:		$(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) $(SRCS) -o $@

$(OBJ_DIR)/%.o:	$(SRCS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

val:	$(NAME)
	@valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./push_swap 2 3 5 1 4

clean:
	@$(RM) $(OBJ_DIR)

fclean:		clean
	@$(RM) $(NAME)

re:			fclean all 