/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:28:05 by mortins-          #+#    #+#             */
/*   Updated: 2023/05/08 19:04:03 by mortins-         ###   ########.fr       */
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

int		make_stack(int argc, char **argv, t_stack **stack);
void	stk_error(t_stack **a, t_stack **b);
int		check_format(int argc, char **argv);
int		check_sorted(t_stack **stack);

int		sort(t_stack **a, t_stack **b);
void	sort_3(t_stack **a);
void	sort_4_5(t_stack **stk_a, t_stack **stk_b);
int		find_min(t_stack *stack);
void	my_radix(t_stack **a, t_stack **b);

void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

int		ft_strlen(const char *s);
int		ps_atoi(const char *s);
int		bin_converter(int dec);

void	stk_free(t_stack **lst);

int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstnew(int data);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);

#endif