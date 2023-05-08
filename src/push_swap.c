/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:28:00 by mortins-          #+#    #+#             */
/*   Updated: 2023/05/08 19:03:52 by mortins-         ###   ########.fr       */
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
	t_stack	**a;
	t_stack	**b;

	a = malloc(sizeof(t_stack));
	if (!a)
		return (0);
	*a = NULL;
	b = malloc(sizeof(t_stack));
	if (!b)
		return (0);
	*b = NULL;
	if (argc < 2)
		return (0);
	if (!(check_format(argc, argv)))
		stk_error(a, b);
	if (argc == 3)
		return (write(1, "sa\n", 3));
	make_stack(argc, argv, a);
	if (!check_sorted(a))
		sort(a, b);
	stk_free(b);
	stk_free(a);
	return (0);
}
