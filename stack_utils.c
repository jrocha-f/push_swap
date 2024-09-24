/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:49:33 by jrocha-f          #+#    #+#             */
/*   Updated: 2024/08/05 14:49:33 by jrocha-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	t_stack	*current;
	int		count;

	current = stack;
	count = 0;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

t_stack	*ft_findlast(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

void	ft_lstadd_front(t_stack **stack, t_stack *new)
{
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
	new->prev = NULL;
}

void	ft_lstadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*current;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	current = *stack;
	while (current -> next != NULL)
		current = current->next;
	current->next = new;
	new->prev = current;
	new->next = NULL;
}

t_stack	*ft_lstnew(int n)
{
	t_stack	*new;

	new = NULL;
	new = malloc(sizeof(t_stack));
	if (new == NULL)
		exit(1);
	new->value = n;
	new->index = -1;
	new->max = 0;
	new->min = 0;
	new->above_median = 0;
	new->cost_to_push = -1;
	new->cheapest = 0;
	new->target_node = NULL;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
