 # -*- MakeFile -*-

NAME		=	push_swap
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf

C_FILES	=	push_swap.c stack.c op_swap.c op_push.c op_rotate.c op_reverse_rotate.c stack_utils.c stack_utils2.c utils.c sort.c

SRCS		=	$(addprefix src/, $(C_FILES))

OBJS		=	$(addprefix obj/, $(C_FILES:%.c=%.o))

.PHONY:		all val clean fclean re

all:		$(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) -g $(SRCS) -o $@

$(OBJS):	$(SRCS)
	@mkdir -p obj
	@$(CC) $(CFLAGS) -o $@ -c $<

val:	$(NAME)
	@valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./push_swap 90 320 500 400

clean:
	@$(RM) obj

fclean:		clean
	@$(RM) $(NAME)

re:			fclean all 