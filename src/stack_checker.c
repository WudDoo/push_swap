/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:55:19 by mortins-          #+#    #+#             */
/*   Updated: 2023/04/11 18:50:37 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stk_error(t_stack **stack)
{
	if (stack)
		stk_clear(stack);
	write(2, "ERROR\n", 6);
	exit (0);
}

void	check_dupes(int argc, char **argv)
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

int	ps_atoi(const char *s, t_stack **stack)
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
		stk_error(stack);
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = (num * 10) + (s[i] - '0');
		i++;
		if (s[i] && !(s[i] >= '0' && s[i] <= '9'))
			stk_error(stack);
	}
	if (num * neg > INT_MAX || num * neg < INT_MIN)
		stk_error(stack);
	return (num * neg);
}
