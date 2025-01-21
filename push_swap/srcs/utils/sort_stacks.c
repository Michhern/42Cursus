/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:40:29 by michhern          #+#    #+#             */
/*   Updated: 2024/10/31 10:39:52 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rotate_both(t_stack_node **a, t_stack_node **b,
	t_stack_node *low_node)
{
	while (*a != low_node->target_node && *b != low_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

void	reverse_rotate_both(t_stack_node **a, t_stack_node **b,
	t_stack_node *low_node)
{
	while (*a != low_node->target_node && *b != low_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

void	prep_for_push(t_stack_node **stack, t_stack_node *target_number,
	char stack_name)
{
	while (*stack != target_number)
	{
		if (stack_name == 'a')
		{
			if (target_number->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (target_number->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = return_the_cheapest(*b);
	if (cheapest_node->above_median && \
		cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && \
		!(cheapest_node->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	prep_for_push(b, cheapest_node, 'b');
	prep_for_push(a, cheapest_node->target_node, 'a');
	pa(a, b, false);
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		sort_five(a, b);
	else
	{
		while (len_a-- > 3)
			pb(b, a, false);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	mini_on_top(a);
	if (stack_sorted(*a))
		sort_stack_final(a);
}
