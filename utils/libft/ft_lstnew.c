/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:12:04 by mortins-          #+#    #+#             */
/*   Updated: 2023/03/30 19:26:18 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../src/push_swap.h"

//	Returns a new node with 'data' as its content

t_stack	*ft_lstnew(int data)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node -> data = data;
	node -> next = NULL;
	return (node);
}
