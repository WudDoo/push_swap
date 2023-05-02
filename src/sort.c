/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:50:59 by mortins-          #+#    #+#             */
/*   Updated: 2023/05/02 19:00:06 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	special_cases(t_stack **stk_a, t_stack **stk_b)
{
	if (stk_size(*stk_a) > 5)
		return (0);
	if (stk_size(*stk_a) == 2)
		write(1, "sa\n", 1);
	else if (stk_size(*stk_a) == 3)
		case_3(stk_a);
	else if (stk_size(*stk_a) > 3 && stk_size(*stk_a) < 6)
		case_4_5(stk_a, stk_b);
	return (1);
}

void	case_3(t_stack **stk_a)
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

void	case_4_5(t_stack **stk_a, t_stack **stk_b)
{
	int	i;

	i = 0;
	while (i < 1)
	{
		while ((*stk_a)->data != 1)
			rotate_a(stk_a);
		push_b(stk_a, stk_b);
		while ((*stk_a)->data != 2)
			rotate_a(stk_a);
		push_b(stk_a, stk_b);
		i++;
	}
	case_3(stk_a);
	push_a(stk_a, stk_b);
	if (stk_b)
		push_a(stk_a, stk_b);
}
