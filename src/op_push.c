/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:58:49 by mortins-          #+#    #+#             */
/*   Updated: 2023/05/02 17:02:52 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!src)
		return ;
	tmp = *src;
	(*src)->previous = NULL;
	*src = (*src)->next;
	stk_add_front(dest, tmp);
}

void	push_a(t_stack **stk_a, t_stack **stk_b)
{
	push(stk_b, stk_a);
	write(1, "pa\n", 3);
}

void	push_b(t_stack **stk_a, t_stack **stk_b)
{
	push(stk_a, stk_b);
	write(1, "pb\n", 3);
}
