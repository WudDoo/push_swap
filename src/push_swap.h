/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:28:05 by mortins-          #+#    #+#             */
/*   Updated: 2023/03/30 19:36:29 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

long			ft_atoi(const char *s);
size_t			ft_strlen(const char *s);
unsigned int	ft_strlcpy(char *dest, const char *src, size_t size);
t_stack			*ft_lstnew(int data);
t_stack			*ft_lstlast(t_stack *lst);
void			ft_lstadd_back(t_stack **lst, t_stack *new);

int		make_list(int argc, char **argv, t_stack **stack);

#endif