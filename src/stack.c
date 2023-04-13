/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:55:19 by mortins-          #+#    #+#             */
/*   Updated: 2023/04/13 17:55:38 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_stack(int argc, char **argv, t_stack **stack)
{
	t_stack	*node;
	int		n;
	int		i;
	int		j;

	i = 1;
	n = 1;
	while (i < argc)
	{
		n = 1;
		j = 1;
		while (j < argc)
		{
			if (ps_atoi(argv[i], stack) > ps_atoi(argv[j], stack))
				n++;
			j++;
		}
		node = stk_new(n);
		stk_add_back(stack, node);
		i++;
	}
	return (0);
}

void	stk_error(t_stack **stack)
{
	if (stack)
		stk_clear(stack);
	write(2, "ERROR\n", 6);
	exit (0);
}

void	check_list(int argc, char **argv)
{
	int	n;
	int	i;

	n = 1;
	if (ft_strlen(argv[n]) > 11)
		stk_error(NULL);
	while (n < (argc - 1))
	{
		i = n + 1;
		while (i < argc)
		{
			if (ft_strlen(argv[i]) > 11 || (ps_atoi(argv[n], NULL) == \
			ps_atoi(argv[i], NULL)))
				stk_error(NULL);
			i++;
		}
		n++;
	}
}
