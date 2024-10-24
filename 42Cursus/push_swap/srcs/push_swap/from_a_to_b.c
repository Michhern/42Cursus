/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:21:13 by michhern          #+#    #+#             */
/*   Updated: 2024/10/18 13:58:40 by michhern         ###   ########.fr       */
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
		stack->above_median = (i <= median_position);
		stack = stack->next;
		++i;
	}
}

static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > best_match_index)
			{
				best_match_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node)
		{
			if (a->target_node->above_median)
				a->push_cost += a->target_node->index;
			else
				a->push_cost += len_b - (a->target_node->index);
		}
		a = a->next;
	}
}

void	mark_lower_cost(t_stack_node *stack)
{
	long			low_value;
	t_stack_node	*low_node;

	if (!stack)
		return ;
	low_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < low_value)
		{
			low_value = stack->push_cost;
			low_node = stack;
		}
		stack = stack->next;
	}
	if (low_node)
		low_node->lower = true;
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	mark_lower_cost(a);
}
