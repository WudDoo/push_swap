/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:28:00 by mortins-          #+#    #+#             */
/*   Updated: 2023/03/24 19:50:46 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc <= 2)
		return (0);
	make_list(argc, argv, &stack_a);
}

int	make_list(int argc, char **argv, t_stack *stack)
{
	t_stack	*node;
	char	**list;
	int		i;

	i = 0;
	list = ft_split(argv[1], ' ');
	while (i < argc)
	{
		node = ft_lstnew(ft_atoi(list[i++]));
		ft_lstadd_back(&stack, node);
	}
	while (node->next)
	{
		printf("%li", stack->content);
		sta = node->next;
	}
}
