/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:42:06 by michhern          #+#    #+#             */
/*   Updated: 2024/09/10 16:20:35 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	calculate_push_cost(t_stack_node *node_b, t_stack_node *node_a,
	int len_b, int len_a)
{
	int	cost_b;
	int	cost_target;

	cost_b = node_b->index;
	if (!node_b->above_median)
		cost_b = len_b - node_b->index;
	if (node_b->target_node)
	{
		cost_target = node_b->target_node->index;
		if (!node_b->target_node->above_median)
			cost_target = len_a - node_b->target_node->index;
		return (cost_b + cost_target);
	}
	else
	{
		printf("Error: Node target es NULL para node B
			con valor %d\n", node_b->nbr);
		return (INT_MAX);
	}
}
t_stack_node	push_cost_node(t_stack_node *b, t_stack_node *a)
{
	t_stack_node	*current_b;
	t_stack_node	*best_node;
	int				best_cost;
	int				current_cost;
	int				len_b;
	int				len_a;

	len_b = stack_len(b);
	len_a = stack_len(a);
	best_node = NULL;
	best_cost = INT_MAX;
	current_b = b;

	while (current_b)
	{
		current_cost = calculate_push_cost(current_b, a, len_b, len_a);
		if (current_cost < best_const)
		{
			best_cost = current_cost;
			best_node = current_b;
		}
		current_b = current_b->next;
	}
	return (best_node);
}