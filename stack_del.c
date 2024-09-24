/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:16:53 by jrocha-f          #+#    #+#             */
/*   Updated: 2024/08/06 09:16:53 by jrocha-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_del_double(t_stack **head)
{
	t_stack	*current;

	if (head == NULL || *head == NULL)
		return ;
	current = *head;
	while (current->next != NULL)
	{
		current = current->next;
		free(current->prev);
	}
	free (current);
	*head = NULL;
}
