/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:28:42 by mortins-          #+#    #+#             */
/*   Updated: 2023/05/03 15:29:47 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	stk_add_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	if (*lst != NULL)
		new->next = *lst;
	else
		new->next = NULL;
	*lst = new;
}
