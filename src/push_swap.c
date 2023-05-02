/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:28:00 by mortins-          #+#    #+#             */
/*   Updated: 2023/05/02 18:11:40 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	print_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;

	a = *stack_a;
	b = *stack_b;
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
	t_stack	*stk_a;
	t_stack	*stk_b;

	stk_a = NULL;
	stk_b = NULL;
	if (argc < 2)
		return (0);
	if (!(check_format(argc, argv)))
		stk_error();
	if (check_sorted(argc, argv))
		return (0);
	if (argc == 3)
		return (write(1, "sa\n", 3));
	make_stack(argc, argv, &stk_a);
/* 	printf("%d\n\n", stk_size(stk_a));
	print_stack(&stk_a, &stk_b); */
	if (special_cases(&stk_a, &stk_b))
	{
		stk_clear(&stk_a);	
		stk_clear(&stk_b);
		return (0);
	}
	stk_clear(&stk_a);
	stk_clear(&stk_b);
}
