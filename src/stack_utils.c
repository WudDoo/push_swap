/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:21:50 by mortins-          #+#    #+#             */
/*   Updated: 2023/05/05 19:02:26 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	stk_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	tmp = stk_last(*lst);
	if (!lst || !new)
		return ;
	if (tmp)
		tmp->next = new;
	else
		*lst = new;
}

t_stack	*stk_new(int data)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void	stk_free(t_stack **lst)
{
	t_stack	*tmp;
	t_stack	*node;

	node = *lst;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(lst);
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
	int		count;
	t_stack	*tmp;

	tmp = lst;
	count = 0;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
