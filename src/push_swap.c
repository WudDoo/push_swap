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
