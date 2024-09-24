/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-f <jrocha-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:00:58 by jrocha-f          #+#    #+#             */
/*   Updated: 2024/08/28 15:07:32 by jrocha-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_values(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return ;
	current = stack;
	while (current != NULL)
	{
		current->index = -1;
		current->max = 0;
		current->min = 0;
		current->above_median = 0;
		current->cost_to_push = -1;
		current->cheapest = 0;
		current->target_node = NULL;
		current = current->next;
	}
}

static t_stack	*target_node_help(t_stack *a, t_stack *b_current)
{
	t_stack			*a_current;
	t_stack			*target_node;
	long int		dif;
	unsigned int	smallest_dif;

	a_current = a;
	smallest_dif = UINT_MAX;
	target_node = min_node(a);
	while (a_current != NULL)
	{
		if (a_current->value > b_current->value)
		{
			dif = a_current->value - b_current->value;
			if (dif < smallest_dif)
			{
				smallest_dif = dif;
				target_node = a_current;
			}
		}
		a_current = a_current->next;
	}
	return (target_node);
}

void	target_node(t_stack *a, t_stack *b)
{
	t_stack	*b_current;
	t_stack	*target_node;

	b_current = b;
	target_node = NULL;
	while (b_current != NULL)
	{
		if (b_current->value > max_node(a)->value)
			target_node = (min_node(a));
		else
			target_node = target_node_help(a, b_current);
		b_current->target_node = target_node;
		b_current = b_current->next;
	}
}

t_stack	*max_node(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	ft_ismax(stack);
	while (current-> max != 1)
		current = current->next;
	return (current);
}

t_stack	*min_node(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	ft_ismin(stack);
	while (current-> min != 1)
		current = current->next;
	return (current);
}
