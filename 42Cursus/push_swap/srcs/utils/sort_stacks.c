/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:40:29 by michhern          #+#    #+#             */
/*   Updated: 2024/09/24 17:51:19 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	//printf("(*b)->target_node = %i\n", (*b)->target_node->nbr);
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}*/

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

void	sort_stacks(t_stack_node **a, t_stack_node **b, int median) //int median
{
	int	len_a;
	//int	median;

	len_a = stack_len(*a);
	median = calculate_median(*a, len_a);
	while (len_a > 3 /*&& !stack_sorted(*a)*/)
	{
		/*if ((*a)->nbr < median)
			pb(b, a, false);
		else
			ra(a, false);
		len_a = stack_len(*a);*/
		pb(b, a, false);
		if (t_stack_node_lstsize(*a) > 3)
		{
			if (t_stack_node_lstsize(*b) > 1)
			{
				if ((*b)->nbr > median)
					rb(b, false);
			}
		}
		//len_a = stack_len(*a);
	}
	sort_three(a);
	move_best_node_and_target_on_top(*a, *b);
	pa(a, b, false);
	// while (*b)
	// {
		// init_nodes_b(*a, *b);
		// move_b_to_a(a, b);
	// }
	//current_index(*a);
	mini_on_top(a);
}
