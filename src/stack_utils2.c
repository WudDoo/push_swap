/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:21:50 by mortins-          #+#    #+#             */
/*   Updated: 2023/05/08 16:57:46 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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
