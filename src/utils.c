/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:22:04 by mortins-          #+#    #+#             */
/*   Updated: 2023/05/05 17:57:19 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ps_atoi(const char *s)
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
		stk_error(NULL, NULL);
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = (num * 10) + (s[i] - '0');
		i++;
		if (s[i] && !(s[i] >= '0' && s[i] <= '9'))
			stk_error(NULL, NULL);
	}
	if (num * neg > INT_MAX || num * neg < INT_MIN)
		stk_error(NULL, NULL);
	return (num * neg);
}

int	bin_converter(int dec)
{
	int	bin;
	int	i;

	bin = 0;
	i = 1;
	while (dec != 0)
	{
		bin += (dec % 2) * i;
		dec /= 2;
		i *= 10;
	}
	return (bin);
}
