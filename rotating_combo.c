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

void	rra_rb(t_stack **a, t_stack **b, t_stack *cheapest)
{
	int	n_rra;
	int	n_rb;

	n_rra = stack_len(*a) - cheapest->target_node->index;
	n_rb = cheapest->index;
	while (n_rra-- > 0)
		rra(a);
	while (n_rb-- > 0)
		rb(b);
}

void	rr_ra(t_stack **a, t_stack **b, t_stack *cheapest)
{
	int	n_rr;
	int	n_ra;

	n_rr = cheapest->index;
	n_ra = cheapest->target_node->index - n_rr;
	while (n_rr-- > 0)
		rr(a, b);
	while (n_ra-- > 0)
		ra(a);
}

void	rr_rb(t_stack **a, t_stack **b, t_stack *cheapest)
{
	int	n_rr;
	int	n_rb;

	n_rr = cheapest->target_node->index;
	n_rb = cheapest->index - n_rr;
	while (n_rr-- > 0)
		rr(a, b);
	while (n_rb-- > 0)
		rb(b);
}

void	rrr_rra(t_stack **a, t_stack **b, t_stack *cheapest)
{
	int	n_rrr;
	int	n_rra;

	n_rrr = stack_len(*b) - cheapest->index;
	n_rra = stack_len(*a) - cheapest->target_node->index - n_rrr;
	while (n_rrr-- > 0)
		rrr(a, b);
	while (n_rra-- > 0)
		rra(a);
}

void	rrr_rrb(t_stack **a, t_stack **b, t_stack *cheapest)
{
	int	n_rrr;
	int	n_rrb;

	n_rrr = stack_len(*a) - cheapest->target_node->index;
	n_rrb = stack_len(*b) - cheapest->index - n_rrr;
	while (n_rrr-- > 0)
		rrr(a, b);
	while (n_rrb-- > 0)
		rrb(b);
}
