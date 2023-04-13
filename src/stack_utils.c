/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:21:50 by mortins-          #+#    #+#             */
/*   Updated: 2023/04/11 19:52:38 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	stk_add_back(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	if (stk_last(*lst))
	{
		new->previous = stk_last(*lst);
		stk_last(*lst)->next = new;
	}
	else
		*lst = new;
}

t_stack	*stk_new(int data)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

void	stk_clear(t_stack **lst)
{
	t_stack	*tmp;

	tmp = *lst;
	while (tmp)
	{
		*lst = (*lst)-> next;
		tmp->data = 0;
		free(tmp);
		tmp = *lst;
	}
}

t_stack	*stk_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

int	stk_size(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst -> next;
		count++;
	}
	return (count);
}
