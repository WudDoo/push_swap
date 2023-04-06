/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:28:05 by mortins-          #+#    #+#             */
/*   Updated: 2023/04/05 19:04:37 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

int				make_list(int argc, char **argv, t_stack **stack);
int				ft_atoi(const char *s, t_stack **stack);
void			stack_error(t_stack **stack);
void			check_dupes(int argc, char **argv);

// V----------------------------- Libft ------------------------------V //

size_t			ft_strlen(const char *s);
unsigned int	ft_strlcpy(char *dest, const char *src, size_t size);
t_stack			*ft_lstnew(int data);
t_stack			*ft_lstlast(t_stack *lst);
void			ft_lstclear(t_stack **lst);
void			ft_lstadd_back(t_stack **lst, t_stack *new);

#endif