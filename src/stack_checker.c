/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:55:19 by mortins-          #+#    #+#             */
/*   Updated: 2023/04/05 19:36:56 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_error(t_stack **stack)
{
	if (stack)
		ft_lstclear(stack);
	write(2, "ERROR\n", 6);
	exit (0);
}

void	check_dupes(int argc, char **argv)
{
	int	n;
	int	i;

	n = 1;
	if (ft_strlen(argv[n]) > 11)
		stack_error(NULL);
	while (n < (argc - 1))
	{
		i = n + 1;
		while (i < argc)
		{
			if (ft_strlen(argv[i]) > 11 || (ft_atoi(argv[n], NULL) == \
			ft_atoi(argv[i], NULL)))
				stack_error(NULL);
			i++;
		}
		n++;
	}
}

int	ft_atoi(const char *s, t_stack **stack)
{
	long	num;
	int		i;
	int		neg;

	i = 0;
	neg = 1;
	num = 0;
	while ((s[i] >= '\t' && s[i] <= '\r') || s[i] == ' ')
		i++;
	if (s[i] == '-')
		neg = -1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!(s[i] >= '0' && s[i] <= '9'))
		stack_error(stack);
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = (num * 10) + (s[i] - '0');
		i++;
		if (s[i] && !(s[i] >= '0' && s[i] <= '9'))
			stack_error(stack);
	}
	if (num * neg > INT_MAX || num * neg < INT_MIN)
		stack_error(stack);
	return (num * neg);
}
