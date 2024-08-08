/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:40:29 by michhern          #+#    #+#             */
/*   Updated: 2024/08/06 13:08:40 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b,
	t_stack_node *low_node, int reverse)
{
	while (*b, != low_node->target_node && *a != low_node)
	{
		if (reverse)
			rrr(a, b, false);
		else
			rr(a, b, false);
	}
	current_index(*a);
	current_index(*b);
}

/*static void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
	t_stack_node *low_node)
{
	while (*b != low_node->target_node && *a != low_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}*/

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*lower_node;

	lower_node = get_the_lower(*a);
	if (lower_node->above_median && lower_node->target_node->above_median)
		rotate_both(a, b, lower_node);
	else if (!(lower_node->above_median)
		&& !(lower_node->target_node->above_median))
		rev_rotate_both(a, b, lower_node);
	prep_for_push(a, lower_node, 'a');
	prep_for_push(b, lower_node->target_node, 'b');
	pb(a, b, false);
}

static void	move_b_to_a(t_stack_node, **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

static void	mini_on_top(t_stack_node **a)
{
	while ((*a)->nbr != fin_min(*a)->nbr)
	{
		if (fin_min(*a)->above_median)
			re(a, false);
		else
			rra(a, false);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	mini_on_top(a);
}
