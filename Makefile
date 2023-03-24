# -*- MakeFile -*-

NAME	=	push_swap
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -rf

INC		=	-I utils/libft

PS_SRCS		=	src/push_swap.c
LFT_SRCS	=	utils/libft/ft_atoi.c utils/libft/ft_split.c /utils/libft/lstadd_back_bonus.c /utils/libft/lstnew_bonus.c

SRCS	=	$(LFT_SRCS) $(PS_SRCS)
OBJS	=	$(patsubst utils/libft/%, obj/%, $(LFT_SRCS:%.c=%.o)) $(patsubst src/%, obj/%, $(PS_SRCS:%.c=%.o))

PHONY:	all clean fclean re

all:	$(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) -g $(INC) $(SRCS) -o $@

obj/%.o:	$(SRCS)
	@mkdir -p obj
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all