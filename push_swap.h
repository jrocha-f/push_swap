/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:22:09 by jrocha-f          #+#    #+#             */
/*   Updated: 2024/07/15 10:22:09 by jrocha-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	long			value;
	long			index;
	bool			max;
	bool			min;
	bool			above_median;
	bool			cheapest;
	int				cost_to_push;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	stack_init(t_stack **stack, int argc, char **argv);
int		is_sorted(t_stack *stack);
void	ft_check_args(char **args, int str);
void	ft_error(char **args, int str);
void	free_array(char **array);

//free
void	ft_del_stack(t_stack **stack);
void	ft_del_double(t_stack **head);

//values
void	ft_fill_values(t_stack **a, t_stack **b);
void	ft_ismax(t_stack *stack);
void	ft_ismin(t_stack *stack);
void	ft_lstindex(t_stack *stack);

//list utils
t_stack	*ft_lstnew(int n);
void	ft_lstadd_back(t_stack **stack, t_stack *new);
void	ft_lstadd_front(t_stack **stack, t_stack *new);
int		stack_len(t_stack *stack);
t_stack	*ft_findlast(t_stack **stack);

//instructions
void	sb(t_stack **b);
void	sa(t_stack **a);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rb(t_stack **b);
void	ra(t_stack **a);
void	rr(t_stack **a, t_stack **b);
void	rrb(t_stack **b);
void	rra(t_stack **a);
void	rrr(t_stack **a, t_stack **b);

//sort
void	tiny_sort(t_stack **stack);
void	push_swap(t_stack **a, t_stack **b);

//sort utils
t_stack	*max_node(t_stack *stack);
t_stack	*min_node(t_stack *stack);
void	target_node(t_stack *a, t_stack *b);
void	above_median(t_stack *stack);
void	reset_values(t_stack *stack);
void	cost_to_push(t_stack *a, t_stack *b);
void	ft_ischepeast(t_stack *stack);
t_stack	*cheapest_node(t_stack *stack);

//rotating combos
void	rr_ra(t_stack **a, t_stack **b, t_stack *cheapest);
void	rr_rb(t_stack **a, t_stack **b, t_stack *cheapest);
void	rrr_rra(t_stack **a, t_stack **b, t_stack *cheapest);
void	rrr_rrb(t_stack **a, t_stack **b, t_stack *cheapest);
void	rrb_ra(t_stack **a, t_stack **b, t_stack *cheapest);
void	rra_rb(t_stack **a, t_stack **b, t_stack *cheapest);
void	ra_n(t_stack **a, t_stack *cheapest);
void	rra_n(t_stack **a, t_stack *cheapest);
void	rb_n(t_stack **b, t_stack *cheapest);
void	rrb_n(t_stack **b, t_stack *cheapest);

//TEST
void	ft_test_array(char **test);
void	ft_test_stcak(t_stack *stack);
void	ft_test_stcak_target(t_stack *stack);
void	ft_test_stcak_no_target(t_stack *stack);
void	ft_test_stcak2(t_stack *stack);

#endif