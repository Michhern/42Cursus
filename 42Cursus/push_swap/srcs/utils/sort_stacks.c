/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:40:29 by michhern          #+#    #+#             */
/*   Updated: 2024/10/21 14:38:02 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	mini_on_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

static void	sort_stack_final(t_stack_node **a)
{
	t_stack_node	*current;
	int				min_value;

	current = *a;
	min_value = INT_MAX;
	while (current)
	{
		if (current->nbr < min_value)
		{
			min_value = current->nbr;
		}
		current = current->next;
	}
	while ((*a)->nbr != min_value)
		ra(a, 0);
}

void	print_stack(t_stack_node *stack)
{
	t_stack_node	*current;

	current = stack;
	while (current)
	{
		current = current->next;
	}
}

static void	sort_initial_stack(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	if (stack_sorted(*a))
		return ;
	len_a = stack_len(*a);
	if (len_a <= 3)
	{
		sort_three(a);
		return ;
	}
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		pb(b, a, false);
	}
	sort_three(a);
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*best_node;

	sort_initial_stack(a, b);
	while (*b)
	{
		init_nodes_b(*a, *b);
		best_node = push_cost_node(*b, *a, stack_len(*b), stack_len(*a));
		if (best_node)
		{
			apply_optimal_rotations(a, b, best_node);
			move_b_to_a(a, b);
		}
	}
	current_index(*a);
	mini_on_top(a);
	if (stack_sorted(*a))
		sort_stack_final(a);
}
