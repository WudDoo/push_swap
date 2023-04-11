/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:39:11 by mortins-          #+#    #+#             */
/*   Updated: 2023/04/11 19:51:32 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap(t_stack **stack)
{
	int	tmp;

	tmp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = tmp;
}

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

void	rev_rotate(t_stack **stack)
{
	t_stack	*rotate;
	int		tmp;

	rotate = stk_last(*stack);
	tmp = stk_last(rotate)->data;
	while (rotate->previous)
	{
		rotate = rotate->previous;
		rotate->next->data = rotate->data;
	}
	rotate->data = tmp;
}

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