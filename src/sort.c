/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:50:59 by mortins-          #+#    #+#             */
/*   Updated: 2023/05/10 16:47:16 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	sort(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 2)
		write(1, "sa\n", 3);
	else if (ft_lstsize(*a) == 3)
		sort_3(a);
	else if (ft_lstsize(*a) == 4 || ft_lstsize(*a) == 5)
		sort_4_5(a, b);
	else if (ft_lstsize(*a) >= 6)
		my_radix(a, b);
	return (1);
}

void	sort_3(t_stack **a)
{
	int	n1;
	int	n2;
	int	n3;

	if (ft_lstsize(*a) != 3)
		return ;
	n1 = (*a)->data;
	n2 = (*a)->next->data;
	n3 = ft_lstlast(*a)->data;
	if (n1 < n2 && n1 < n3 && n2 > n3)
	{
		rra(a);
		sa(a);
	}
	else if (n1 > n2 && n1 < n3)
		sa(a);
	else if (n1 < n2 && n1 > n3)
		rra(a);
	else if (n1 > n2 && n1 > n3 && n2 < n3)
		ra(a);
	else if (n1 > n2 && n1 > n3 && n2 > n3)
	{
		sa(a);
		rra(a);
	}
}

void	sort_4_5(t_stack **a, t_stack **b)
{
	while ((!check_sorted(a)) && ft_lstsize(*a) != 3)
	{
		if (find_min(*a) < 2)
		{
			while (find_min(*a) != 0)
				ra(a);
			if (check_sorted(a))
				break ;
			pb(a, b);
		}
		else
		{
			while (find_min(*a) != 0)
				rra(a);
			if (check_sorted(a))
				break ;
			pb(a, b);
		}
	}
	sort_3(a);
	pa(a, b);
	if (*b)
		pa(a, b);
}

int	find_min(t_stack *stack)
{
	t_stack	*tmp;
	int		buf;
	int		pos_buf;
	int		pos;

	tmp = (stack);
	buf = (stack)->data;
	pos = 0;
	pos_buf = 0;
	while (tmp)
	{
		tmp = tmp->next;
		pos++;
		if (tmp && buf > tmp->data)
		{
			buf = tmp->data;
			pos_buf = pos;
		}
	}
	return (pos_buf);
}

void	my_radix(t_stack **a, t_stack **b)
{
	int	i;
	int	n;
	int	x;

	n = ft_lstsize(*a);
	x = 1;
	while (!check_sorted(a))
	{
		i = 0;
		while (i < n)
		{
			if (((*a)->data / x) % 10 != 0)
				ra(a);
			else if (((*a)->data / x) % 10 == 0)
				pb(a, b);
			i++;
		}
		while (*b)
			pa(a, b);
		x *= 10;
	}
}
