/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-f <jrocha-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:13:49 by jrocha-f          #+#    #+#             */
/*   Updated: 2024/08/26 14:41:25 by jrocha-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	above_median(t_stack *stack)
{
	t_stack	*current;
	int		len;

	current = stack;
	len = stack_len(stack);
	if (!stack)
		return ;
	while (current != NULL)
	{
		if (current->index <= len / 2)
			current->above_median = 1;
		else
			current->above_median = 0;
		current = current->next;
	}
}

void	ft_lstindex(t_stack *stack)
{
	long	i;
	t_stack	*current;

	if (!stack)
		return ;
	i = 0;
	current = stack;
	while (current != NULL)
	{
		current->index = i;
		current = current->next;
		i++;
	}
}

void	ft_ismax(t_stack *stack)
{
	int		max;
	t_stack	*current;

	if (!stack)
		return ;
	current = stack;
	max = current ->value;
	while (current != NULL)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	current = stack;
	while (current != NULL)
	{
		if (current->value == max)
			current->max = 1;
		else
			current->max = 0;
		current = current->next;
	}
}

void	ft_ismin(t_stack *stack)
{
	int		min;
	t_stack	*current;

	if (!stack)
		return ;
	current = stack;
	min = current ->value;
	while (current != NULL)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	current = stack;
	while (current != NULL)
	{
		if (current->value == min)
			current->min = 1;
		else
			current->min = 0;
		current = current->next;
	}
}

void	ft_fill_values(t_stack **a, t_stack **b)
{
	reset_values(*a);
	reset_values(*b);
	if (*a)
	{
		ft_ismin(*a);
		ft_ismax(*a);
		ft_lstindex(*a);
		above_median(*a);
	}
	if (*b)
	{
		ft_ismin(*b);
		ft_ismax(*b);
		ft_lstindex(*b);
		above_median(*b);
	}
	if (*b && *a)
	{
		target_node(*a, *b);
		cost_to_push(*a, *b);
		ft_ischepeast(*b);
	}
}
