/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:13:48 by mortins-          #+#    #+#             */
/*   Updated: 2023/03/30 19:15:29 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../src/push_swap.h"

//	Adds the node ’new’ at the end of the list 'lst'

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	if (ft_lstlast(*lst))
		ft_lstlast(*lst)-> next = new;
	else
		*lst = new;
}
