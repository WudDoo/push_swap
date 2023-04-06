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
	struct s_stack	*previous;
}	t_stack;

int				make_list(int argc, char **argv, t_stack **stack);
int				ft_atoi(const char *s, t_stack **stack);
void			stack_error(t_stack **stack);
void			check_dupes(int argc, char **argv);
void			swap(t_stack **stack);
void			rotate(t_stack **stack);
void			rev_rotate(t_stack **stack);

// V----------------------------- Libft ------------------------------V //

size_t			ft_strlen(const char *s);
t_stack			*ft_new(int data);
t_stack			*ft_last(t_stack *lst);
void			ft_clear(t_stack **lst);
void			ft_add_back(t_stack **lst, t_stack *new);

#endif