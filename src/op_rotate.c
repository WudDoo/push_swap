/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:05:13 by mortins-          #+#    #+#             */
/*   Updated: 2023/05/02 17:11:27 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*rotate;
	int		tmp;

	rotate = (*stack);
	tmp = rotate->data;
	while (rotate->next)
	{
		rotate = rotate->next;
		rotate->previous->data = rotate->data;
	}
	rotate->data = tmp;
}

void	rotate_a(t_stack **stk_a)
{
	rotate(stk_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **stk_b)
{
	rotate(stk_b);
	write(1, "rb\n", 3);
}

void	rotate_r(t_stack **stk_a, t_stack **stk_b)
{
	rotate(stk_a);
	rotate(stk_b);
	write(1, "rr\n", 3);
}
