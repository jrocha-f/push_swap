/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating_combo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:56:24 by jrocha-f          #+#    #+#             */
/*   Updated: 2024/08/20 09:56:24 by jrocha-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb_ra(t_stack **a, t_stack **b, t_stack *cheapest)
{
	int	n_rrb;
	int	n_ra;

	n_rrb = stack_len(*b) - cheapest->index;
	n_ra = cheapest->target_node->index;
	while (n_rrb-- > 0)
		rrb(b);
	while (n_ra-- > 0)
		ra(a);
}

void	ra_n(t_stack **a, t_stack *cheapest)
{
	int	n_ra;

	n_ra = cheapest->target_node->index;
	while (n_ra-- > 0)
		ra(a);
}

void	rra_n(t_stack **a, t_stack *cheapest)
{
	int	n_rra;

	n_rra = stack_len(*a) - cheapest->target_node->index;
	while (n_rra-- > 0)
		rra(a);
}

void	rb_n(t_stack **b, t_stack *cheapest)
{
	int	n_rb;

	n_rb = cheapest->index;
	while (n_rb-- > 0)
		rb(b);
}

void	rrb_n(t_stack **b, t_stack *cheapest)
{
	int	n_rrb;

	n_rrb = stack_len(*b) - cheapest->index;
	while (n_rrb-- > 0)
		rrb(b);
}
