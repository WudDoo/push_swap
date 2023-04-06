/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:15:48 by mortins-          #+#    #+#             */
/*   Updated: 2023/04/05 16:24:48 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../src/push_swap.h"

//	Deletes and frees the given node and all of its successors
//	using the function ’del’ and free

void	ft_lstclear(t_stack **lst)
{
	t_stack	*temp;

	temp = *lst;
	while (temp)
	{
		*lst = (*lst)-> next;
		temp -> data = 0;
		free(temp);
		temp = *lst;
	}
}
