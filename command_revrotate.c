/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_revrotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-f <jrocha-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:19:08 by jrocha-f          #+#    #+#             */
/*   Updated: 2024/08/26 14:24:20 by jrocha-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack **head)
{
	t_stack	*last;

	if (!head || !*head)
		return ;
	last = ft_findlast(head);
	last->prev->next = NULL;
	last->next = *head;
	(*head)->prev = last;
	last->prev = NULL;
	*head = last;
}

void	rra(t_stack **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}
