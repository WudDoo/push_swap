/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:50:59 by mortins-          #+#    #+#             */
/*   Updated: 2023/05/03 16:26:12 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	sort(t_stack **stk_a, t_stack **stk_b)
{
	if (stk_size(*stk_a) > 5)
		return (0);
	if (stk_size(*stk_a) == 2)
		write(1, "sa\n", 1);
	else if (stk_size(*stk_a) == 3)
		sort_3(stk_a);
	else if (stk_size(*stk_a) > 3 && stk_size(*stk_a) < 6)
		sort_4_5(stk_a, stk_b);
	return (1);
}

void	sort_3(t_stack **stk_a)
{
	int	n1;
	int	n2;
	int	n3;

	if (stk_size(*stk_a) != 3)
		return ;
	n1 = (*stk_a)->data;
	n2 = (*stk_a)->next->data;
	n3 = stk_last(*stk_a)->data;
	if (n1 < n2 && n1 < n3 && n2 > n3)
	{
		rev_rotate_a(stk_a);
		swap_a(stk_a);
	}
	else if (n1 > n2 && n1 < n3)
		swap_a(stk_a);
	else if (n1 < n2 && n1 > n3)
		rev_rotate_a(stk_a);
	else if (n1 > n2 && n1 > n3 && n2 < n3)
		rotate_a(stk_a);
	else if (n1 > n2 && n1 > n3 && n2 > n3)
	{
		swap_a(stk_a);
		rev_rotate_a(stk_a);
	}
}

void	sort_4_5(t_stack **stk_a, t_stack **stk_b)
{
	while ((!check_sorted(*stk_a)) && stk_size(*stk_a) != 3)
	{
		if (find_min(*stk_a) < 2)
		{
			while (find_min(*stk_a) != 0)
				rotate_a(stk_a);
			if (check_sorted(*stk_a))
				break ;
			push_b(stk_a, stk_b);
		}
		else
		{
			while (find_min(*stk_a) != 0)
				rev_rotate_a(stk_a);
			if (check_sorted(*stk_a))
				break ;
			push_b(stk_a, stk_b);
		}
	}
	sort_3(stk_a);
	push_a(stk_a, stk_b);
	if (stk_b)
		push_a(stk_a, stk_b);
}

int	find_min(t_stack *stack)
{
	int	buf;
	int	pos_buf;
	int	pos;

	buf = stack->data;
	pos = 0;
	pos_buf = 0;
	while (stack)
	{
		stack = stack->next;
		pos++;
		if (stack && buf > stack->data)
		{
			buf = stack->data;
			pos_buf = pos;
		}
	}
	return (pos_buf);
}
