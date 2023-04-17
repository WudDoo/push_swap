/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:28:05 by mortins-          #+#    #+#             */
/*   Updated: 2023/04/17 18:39:00 by mortins-         ###   ########.fr       */
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
	struct s_stack	*previous;
	int				data;
	struct s_stack	*next;
}	t_stack;

int		make_stack(int argc, char **argv, t_stack **stack);
void	stk_error(void);
int		check_format(int argc, char **argv);
int		check_sorted(int argc, char **argv);

int		special_cases(int argc, char **argv);
void	case_3(char **argv);

void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	rev_rotate(t_stack **stack);
void	push(t_stack **src, t_stack **dest);

int		ft_strlen(const char *s);
int		ps_atoi(const char *s);

t_stack	*stk_new(int data);
int		stk_size(t_stack *lst);
void	stk_clear(t_stack **lst);
t_stack	*stk_last(t_stack *lst);
void	stk_add_front(t_stack **lst, t_stack *new);
void	stk_add_back(t_stack **lst, t_stack *new);

#endif