/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:10:09 by jrocha-f          #+#    #+#             */
/*   Updated: 2024/08/05 14:10:09 by jrocha-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	while (--i >= 0)
		free(array[i]);
	free (array);
}

void	stack_init(t_stack **stack, int argc, char **argv)
{
	int		i;
	int		str;
	t_stack	*new;
	char	**args;

	i = 0;
	str = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		str = 1;
	}
	else
		args = argv + 1;
	ft_check_args(args, str);
	while (args[i] != NULL)
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	if (str == 1)
		free_array(args);
}
