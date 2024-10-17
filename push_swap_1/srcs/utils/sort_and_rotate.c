/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_&_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:32:28 by michhern          #+#    #+#             */
/*   Updated: 2024/10/15 12:44:08 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rotate_both(t_stack_node **a, t_stack_node **b,
	t_stack_node *low_node, int dist_a, int dist_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(*a) / 2;
	len_b = stack_len(*b) / 2;

	if (dist_a <= len_a && dist_b <= len_b)
	{
		while(*b != low_node && *a != low_node->target_node)
			rr(a, b, false);
	}
	else if (dist_a > len_a && dist_b > len_b)
	{
		while (*b != low_node && *a != low_node->target_node)
			rrr(a, b, false);
	}
	
}

void	rotate_one(t_stack_node **a, t_stack_node **b,
	t_stack_node *low_node, int dist_a, int dist_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(*a) / 2;
	len_b = stack_len(*b) / 2;
	while (*a != low_node->target_node)
	{
		if (dist_a <= len_a)
			ra(a, false);
		else
			rra(a, false);
	}
	while (*b != low_node)
	{
		if (dist_b <= len_b)
			rb(b, false);
		else
			rrb(b, false);
	}
}

int	get_distance_to_top(t_stack_node *stack, t_stack_node *node)
{
	int				distance;
	t_stack_node	*current;

	distance = 0;
	current = stack;
	while (current && current != node)
	{
		current = current->next;
		distance++;
	}
	if (!current)
		return (-1);
	return (distance);
}

void	apply_optimal_rotations(t_stack_node **a, t_stack_node **b,
	t_stack_node *low_node)//nueva funcion
{
	int	dist_a;
	int	dist_b;
	int	len_a;
	int	len_b;

	dist_a = get_distance_to_top(*a, low_node->target_node);
	dist_b = get_distance_to_top(*b, low_node);
	len_a = stack_len(*a) / 2;
	len_b = stack_len(*b) / 2;

	if ((dist_a <= len_a && dist_b <= len_b) || (dist_a > len_a && dist_b > len_b))
		rotate_both(a, b, low_node, dist_a, dist_b);
	else
		rotate_one(a, b, low_node, dist_a, dist_b);
	current_index(*a);
	current_index(*b);
}