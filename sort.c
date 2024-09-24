/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-f <jrocha-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:37:24 by jrocha-f          #+#    #+#             */
/*   Updated: 2024/08/28 15:11:35 by jrocha-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_tow(t_stack **a, t_stack **b, t_stack *cheapest)
{
	int	len_b;
	int	len_a;

	len_a = stack_len(*a);
	len_b = stack_len(*b);
	if (cheapest->above_median && cheapest->target_node->above_median)
	{
		if (cheapest->index > cheapest->target_node->index)
			rr_rb(a, b, cheapest);
		else
			rr_ra(a, b, cheapest);
	}
	else if (!cheapest->above_median && !cheapest->target_node->above_median)
	{
		if ((len_a - cheapest->target_node->index) > (len_b - cheapest->index))
			rrr_rra(a, b, cheapest);
		else
			rrr_rrb(a, b, cheapest);
	}
	else if (!cheapest->above_median && cheapest->target_node->above_median)
		rrb_ra(a, b, cheapest);
	else if (cheapest->above_median && !cheapest->target_node->above_median)
		rra_rb(a, b, cheapest);
}

static void	rotate_one(t_stack **a, t_stack **b, t_stack *cheapest)
{
	if (cheapest->target_node->index == 0)
	{
		if (cheapest->above_median)
			rb_n(b, cheapest);
		else
			rrb_n(b, cheapest);
	}
	else if (cheapest->index == 0)
	{
		if (cheapest->target_node->above_median)
			ra_n(a, cheapest);
		else
			rra_n(a, cheapest);
	}
}

static void	sort_a(t_stack **a, t_stack **b)
{
	int	n;

	if (is_sorted(*a))
		return ;
	ft_fill_values(a, b);
	if (min_node(*a)-> above_median == 1)
	{
		n = min_node(*a)->index;
		while (n-- > 0)
			ra(a);
	}
	else
	{
		n = stack_len(*a) - min_node(*a)->index;
		while (n-- > 0)
			rra(a);
	}
}

void	tiny_sort(t_stack **stack)
{
	t_stack	*max;

	if (stack_len(*stack) == 2)
	{
		sa(stack);
		return ;
	}
	max = max_node(*stack);
	if ((*stack) == max)
		ra(stack);
	else if ((*stack)->next == max)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;
	int		len_a;
	int		len_b;

	len_a = stack_len(*a);
	while (len_a != 3)
	{
		pb(a, b);
		len_a--;
	}
	tiny_sort(a);
	len_b = stack_len(*b);
	while (len_b > 0)
	{
		ft_fill_values(a, b);
		cheapest = cheapest_node(*b);
		if (cheapest->target_node->index == 0 || cheapest->index == 0)
			rotate_one(a, b, cheapest);
		else
			rotate_tow(a, b, cheapest);
		pa(a, b);
		len_b--;
		len_a++;
	}
	sort_a(a, b);
}
