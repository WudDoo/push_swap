/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:28:00 by mortins-          #+#    #+#             */
/*   Updated: 2023/04/13 17:56:29 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*a;
	t_stack	*b;

	a = stack_a;
	b = stack_b;
	while (a || b)
	{
		if (a && b)
		{
			printf("   %d      %d\n", a->data, b->data);
			a = a->next;
			b = b->next;
		}
		else if (a && !b)
		{
			printf("   %d\n", a->data);
			a = a->next;
		}
		else if (!a && b)
		{
			printf("          %d\n", b->data);
			b = b->next;
		}
	}
	printf("   _      _\n");
	printf("   a      b\n");
	printf("--------------\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	check_list(argc, argv);
	make_stack(argc, argv, &stack_a);
	printf("%d\n\n", stk_size(stack_a));
	print_stack(stack_a, stack_b);
	/* swap(&stack_a); */
	int	i = 0;
	while (i++ < 5)
	{
		push(&stack_a, &stack_b);
		printf("Execute pb:\n\n");
		print_stack(stack_a, stack_b);
	}
	i = 0;
	while (i++ < 5)
	{
		push(&stack_b, &stack_a);
		printf("Execute pa:\n\n");
		print_stack(stack_a, stack_b);
	}
	stk_clear(&stack_a);
	stk_clear(&stack_b);
}
