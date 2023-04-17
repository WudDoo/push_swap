/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:55:19 by mortins-          #+#    #+#             */
/*   Updated: 2023/04/17 17:36:42 by mortins-         ###   ########.fr       */
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
			if (ps_atoi(argv[i]) > ps_atoi(argv[j]))
				n++;
			j++;
		}
		node = stk_new(n);
		stk_add_back(stack, node);
		i++;
	}
	return (0);
}

void	stk_error(void)
{
	write(2, "ERROR\n", 6);
	exit (0);
}

int	check_format(int argc, char **argv)
{
	int	n;
	int	i;

	n = 1;
	if (ft_strlen(argv[n]) > 11)
		stk_error();
	while (n < (argc - 1))
	{
		i = n + 1;
		while (i < argc)
		{
			if (ft_strlen(argv[i]) > 11 || (ps_atoi(argv[n]) == \
			ps_atoi(argv[i])))
				stk_error();
			i++;
		}
		n++;
	}
	return (1);
}

int	check_sorted(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < (argc - 1))
	{
		if (ps_atoi(argv[i]) < ps_atoi(argv[i + 1]))
			i++;
		else
			return (0);
	}
	return (1);
}
