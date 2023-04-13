 # -*- MakeFile -*-

NAME		=	push_swap
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf

C_FILES	=	push_swap.c stack.c sorters.c stack_utils.c stack_utils2.c utils.c

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
	@valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./push_swap 7 3 5 1 2

clean:
	@$(RM) obj

fclean:		clean
	@$(RM) $(NAME)

re:			fclean all 