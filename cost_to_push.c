/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_to_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-f <jrocha-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:09:17 by jrocha-f          #+#    #+#             */
/*   Updated: 2024/08/28 15:06:12 by jrocha-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ischepeast(t_stack *stack)
{
	t_stack	*current;
	t_stack	*cheapest;

	if (!stack)
		return ;
	current = stack;
	cheapest = cheapest_node(stack);
	while (current != NULL)
	{
		if (current == cheapest)
			current->cheapest = 1;
		else
			current->cheapest = 0;
		current = current->next;
	}
}

t_stack	*cheapest_node(t_stack *stack)
{
	t_stack	*current;
	t_stack	*cheapest_node;
	int		min_cost;

	if (!stack)
		return (NULL);
	current = stack;
	cheapest_node = current;
	min_cost = current->cost_to_push;
	while (current != NULL)
	{
		if (min_cost > current->cost_to_push)
		{
			min_cost = current->cost_to_push;
			cheapest_node = current;
		}
		current = current ->next;
	}
	current = stack;
	return (cheapest_node);
}

static void	cost_abovemedian(t_stack *current)
{
	if (current->index > current->target_node->index)
		current->cost_to_push = current->index;
	else
		current->cost_to_push = current->target_node->index;
}

static void	cost_belowmedian(t_stack *current, int len_a, int len_b)
{
	if (len_a - current->target_node->index > len_b - current->index)
		current->cost_to_push = len_a - current->target_node->index;
	else
		current->cost_to_push = len_b - current->index;
}

void	cost_to_push(t_stack *a, t_stack *b)
{
	int		len_a;
	int		len_b;
	t_stack	*current;

	current = b;
	len_a = stack_len(a);
	len_b = stack_len(b);
	if (!b || !a)
		return ;
	while (current != NULL)
	{
		if (current->above_median && current->target_node->above_median)
			cost_abovemedian(current);
		else if (!current->above_median && !current->target_node->above_median)
			cost_belowmedian(current, len_a, len_b);
		else if (!current->above_median && current->target_node->above_median)
			current->cost_to_push = len_b - current->index
				+ current->target_node->index;
		else if (current->above_median && !current->target_node->above_median)
			current->cost_to_push = len_a - current->target_node->index
				+ current->index;
		current = current->next;
	}
}
