/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:42:06 by michhern          #+#    #+#             */
/*   Updated: 2024/10/29 10:28:55 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack_node	*find_bigger_close(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*bigger;

	if (b == NULL)
		return (NULL);
	bigger = NULL;
	while (a)
	{
		if (a->nbr > b->nbr && (!bigger || a->nbr < bigger->nbr))
			bigger = a;
		a = a->next;
	}
	return (bigger);
}

t_stack_node	*find_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*target;

	if (!b)
		return (NULL);
	target = find_bigger_close(a, b);
	if (!target)
	{
		if (a != NULL)
			b->target_node = find_min(a);
		else
			b->target_node = NULL;
	}
	else
		b->target_node = target;
	return (target);
}

int	calculate_push_cost(t_stack_node *node_b, t_stack_node *a,
		int len_b, int len_a)
{
	int				cost_b;
	int				cost_target;
	t_stack_node	*target_node;

	if (!node_b)
		return (0);
	if (node_b->above_median)
		cost_b = node_b->index;
	else
		cost_b = len_b - node_b->index;
	target_node = find_target_node(a, node_b);
	if (!target_node)
		return (cost_b);
	if (target_node->above_median)
		cost_target = target_node->index;
	else
		cost_target = len_a - target_node->index;
	return (cost_b + cost_target);
}

t_stack_node	*push_cost_node(t_stack_node *b, t_stack_node *a,
					int len_b, int len_a)
{
	t_stack_node	*current_b;
	t_stack_node	*best_node;
	int				best_cost;
	int				current_cost;

	if (!b)
		return (NULL);
	best_node = NULL;
	best_cost = INT_MAX;
	current_b = b;
	while (current_b)
	{
		current_cost = calculate_push_cost(current_b, a, len_b, len_a);
		if (current_cost < best_cost)
		{
			best_cost = current_cost;
			best_node = current_b;
		}
		current_b = current_b->next;
	}
	return (best_node);
}
