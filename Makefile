 # -*- MakeFile -*-

NAME		=	push_swap
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf

SRC_FILES	=	push_swap.c stack_checker.c sorters.c stack_fts.c stack_fts2.c

SRCS		=	$(patsubst %, src/%, $(SRC_FILES))

OBJS		=	$(patsubst src/%, obj/%, $(SRCS:%.c=%.o))

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJS)
	@$(MAKE) bonus --no-print-directory -C libft
	@$(CC) $(CFLAGS) -g $(SRCS) libft/libft.a -o $@

$(OBJS):	$(SRCS)
	@mkdir -p obj
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) obj
	@$(MAKE) clean --no-print-directory -C libft

fclean:		clean
	@$(RM) $(NAME)
	@$(MAKE) fclean --no-print-directory -C libft

re:			fclean all 