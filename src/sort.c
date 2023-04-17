/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:50:59 by mortins-          #+#    #+#             */
/*   Updated: 2023/04/17 18:38:54 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	special_cases(int argc, char **argv)
{
	if (argc > 4)
		return (0);
	if (argc == 3)
		write(1, "sa\n", 1);
	else if (argc == 4)
		case_3(argv);
	return (1);
}

void	case_3(char **argv)
{
	if (ps_atoi(argv[1]) < ps_atoi(argv[2]) && ps_atoi(argv[1]) < \
	ps_atoi(argv[3]))
		write(1, "ra\nsa\n", 6);
	else if (ps_atoi(argv[1]) > ps_atoi(argv[2]) && ps_atoi(argv[1]) < \
	ps_atoi(argv[3]))
		write(1, "sa\n", 3);
	else if (ps_atoi(argv[1]) < ps_atoi(argv[2]) && ps_atoi(argv[1]) > \
	ps_atoi(argv[3]))
		write(1, "ra\n", 3);
	else if (ps_atoi(argv[1]) > ps_atoi(argv[2]) && ps_atoi(argv[1]) > \
	ps_atoi(argv[3]))
	{
		if (ps_atoi(argv[2]) < ps_atoi(argv[3]))
			write(1, "rra\n", 4);
		else
			write(1, "sa\nra\n", 6);
	}
}
