/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:05:37 by michhern          #+#    #+#             */
/*   Updated: 2024/10/31 10:38:58 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack_node	*find_last(t_stack_node *stack)
{
	while (stack)
	{
		if (!stack->next)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}

int	stack_len(t_stack_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack_node	*return_the_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheapest_node;
	int				min_cost;

	min_cost = stack->push_cost;
	cheapest_node = stack;
	while (stack)
	{
		if (stack->push_cost < min_cost)
		{
			min_cost = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	return (cheapest_node);
}

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}
