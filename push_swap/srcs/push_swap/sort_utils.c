/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:21:13 by michhern          #+#    #+#             */
/*   Updated: 2024/10/31 10:39:55 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median_position;

	i = 0;
	if (!stack)
		return ;
	median_position = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median_position)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		target_node = NULL;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_match_index)
			{
				best_match_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

static void	cost_analysis(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_cost = b->index;
		if (!(b->above_median))
			b->push_cost = len_b - (b->index);
		if (b->target_node)
		{
			if (b->target_node->above_median)
				b->push_cost += b->target_node->index;
			else
				b->push_cost += len_a - (b->target_node->index);
		}
		b = b->next;
	}
}

void	set_cheapest_cost(t_stack_node *b)
{
	long			low_value;
	t_stack_node	*low_node;

	if (!b)
		return ;
	low_value = LONG_MAX;
	while (b)
	{
		if (b->push_cost < low_value)
		{
			low_value = b->push_cost;
			low_node = b;
		}
		b = b->next;
	}
	if (low_node)
		low_node->lower = true;
}

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_node(a, b);
	cost_analysis(a, b);
	set_cheapest_cost(b);
}
