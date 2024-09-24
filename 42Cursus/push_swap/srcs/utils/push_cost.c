/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:42:06 by michhern          #+#    #+#             */
/*   Updated: 2024/09/23 17:11:52 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	t_stack_node_lstsize(t_stack_node *lst)
{
	t_stack_node	*str;
	int				i;

	str = lst;
	i = 0;
	while (str != NULL)
	{
		str = str->next;
		i++;
	}
	return (i);
}

t_stack_node	*find_bigger_close(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*bigger;

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
		b->target_node = find_min(a);
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

	cost_b = node_b->index;
	if (!node_b->above_median)
		cost_b = len_b - node_b->index;
	target_node = find_target_node(a, node_b);
	cost_target = node_b->target_node->index;
	if (!target_node->above_median)
		cost_target = len_a - node_b->target_node->index;
	return (cost_b + cost_target);
}

t_stack_node	*push_cost_node(t_stack_node *b, t_stack_node *a,
					int len_b, int len_a)
{
	t_stack_node	*current_b;
	t_stack_node	*best_node;
	int				best_cost;
	int				current_cost;

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

void	move_best_node_and_target_on_top(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*min_pc;
	int				valor_medio_a;
	int				valor_medio_b;

	valor_medio_a = t_stack_node_lstsize(a) / 2;
	valor_medio_b = t_stack_node_lstsize(b) / 2;
	min_pc = push_cost_node(b, a, t_stack_node_lstsize(b), t_stack_node_lstsize(a));
	if (min_pc->index != 0 && min_pc->target_node->index != 0)
	{
		while (min_pc->index != 0)
		{
			if (min_pc->index > valor_medio_b)
				rrb(&b, false);
			else
				rb(&b, false);
		}
		while (min_pc->target_node->index != 0)
		{
			if (min_pc->target_node->index > valor_medio_a)
				rra(&a, false);
			else
				ra(&a, false);
		}
	}
}