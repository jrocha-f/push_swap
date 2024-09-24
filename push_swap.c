/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:14:05 by jrocha-f          #+#    #+#             */
/*   Updated: 2024/07/15 10:14:05 by jrocha-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// VERIFICAR SE NAO E NULO O VALOR e se 0 zero da problema

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc < 2 && !argv[1][0]))
		return (1);
	stack_init(&a, argc, argv);
	if (is_sorted(a))
	{
		ft_del_double(&a);
		return (0);
	}
	if (stack_len(a) <= 3)
		tiny_sort(&a);
	else
		push_swap(&a, &b);
	ft_del_double(&a);
	return (0);
}
