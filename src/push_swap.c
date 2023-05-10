/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:28:00 by mortins-          #+#    #+#             */
/*   Updated: 2023/05/10 16:06:05 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;

	if (argc < 2)
		return (0);
	check_format(argc, argv);
	a = malloc(sizeof(t_stack));
	if (!a)
		return (0);
	*a = NULL;
	b = malloc(sizeof(t_stack));
	if (!b)
		return (0);
	*b = NULL;
	make_stack(argc, argv, a);
	if (!check_sorted(a))
		sort(a, b);
	stk_free(b);
	stk_free(a);
	return (0);
}
