/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:28:00 by mortins-          #+#    #+#             */
/*   Updated: 2023/04/05 19:27:12 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("%i\n", tmp->data);
		tmp = tmp->next;
	}
	printf("//--------------------//\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	check_dupes(argc, argv);
	make_list(argc, argv, &stack_a);
	print_stack(stack_a);
	/* swap(&stack_a); */
	/* int	i = 0;
	while (i++ < 5)
	{
		rotate(&stack_a);
		print_stack(stack_a);
	}
	i = 0;
	while (i++ < 5)
	{
		rev_rotate(&stack_a);
		print_stack(stack_a);
	} */
}

int	make_list(int argc, char **argv, t_stack **stack)
{
	t_stack	*node;
	int		i;

	i = 1;
	while (i < argc)
	{
		node = ft_new(ft_atoi(argv[i++], stack));
		ft_add_back(stack, node);
	}
	return (0);
}
