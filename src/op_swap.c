/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:40:42 by mortins-          #+#    #+#             */
/*   Updated: 2023/05/02 17:21:35 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap(t_stack **stack)
{
	int	tmp;

	if (stk_size(*stack) < 2)
		return ;
	tmp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = tmp;
}

void	swap_a(t_stack **stk_a)
{
	swap(stk_a);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **stk_b)
{
	swap(stk_b);
	write(1, "sb\n", 3);
}

void	swap_s(t_stack **stk_a, t_stack **stk_b)
{
	swap(stk_a);
	swap(stk_b);
	write(1, "ss\n", 3);
}
