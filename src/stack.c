/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:55:19 by mortins-          #+#    #+#             */
/*   Updated: 2023/05/10 16:03:41 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_stack(int argc, char **argv, t_stack **stack)
{
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
		ft_lstadd_back(stack, ft_lstnew(bin_converter(n)));
		i++;
	}
	return (0);
}

void	stk_error(t_stack **a, t_stack **b)
{
	if (a)
		stk_free(a);
	if (b)
		stk_free(b);
	write(2, "Error\n", 6);
	exit (0);
}

int	check_format(int argc, char **argv)
{
	int	n;
	int	i;

	n = 1;
	if (ft_strlen(argv[n]) > 11)
		stk_error(NULL, NULL);
	while (n < (argc - 1))
	{
		i = n + 1;
		while (i < argc)
		{
			if (ft_strlen(argv[i]) > 11 || (ps_atoi(argv[n]) == \
			ps_atoi(argv[i])))
				stk_error(NULL, NULL);
			i++;
		}
		n++;
	}
	return (1);
}

int	check_sorted(t_stack **stack)
{
	t_stack	*buf;

	buf = (*stack);
	while (buf && buf->next)
	{
		if (buf->data < buf->next->data)
			buf = buf->next;
		else
			return (0);
	}
	return (1);
}
