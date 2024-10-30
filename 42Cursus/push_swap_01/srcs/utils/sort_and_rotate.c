/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_and_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:32:28 by michhern          #+#    #+#             */
/*   Updated: 2024/10/30 14:37:33 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	mini_on_top(t_stack_node **a)
{
	t_stack_node	*mini_node;

	current_index(*a);
	mini_node = find_min(*a);
	if (mini_node->above_median)
	{
		while (*a != mini_node)
			ra(a, false);
	}
	else
	{
		while (*a != mini_node)
			rra(a, false);
	}
}

void	sort_stack_final(t_stack_node **a)
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














