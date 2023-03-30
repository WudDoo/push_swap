/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:28:00 by mortins-          #+#    #+#             */
/*   Updated: 2023/03/30 19:42:33 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a = NULL;

	if (argc <= 2)
		return (0);
	make_list(argc, argv, &stack_a);
	while (stack_a)
	{
		printf("%i\n", stack_a->data);
		stack_a = stack_a->next;
	}
}

int	make_list(int argc, char **argv, t_stack **stack)
{
	t_stack	*node;
	int		i;

	i = 1;
	while (i < argc)
	{
		node = ft_lstnew(ft_atoi(argv[i++]));
		ft_lstadd_back(stack, node);
	}
	return (0);
}
