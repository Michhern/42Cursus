/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:36:38 by michhern          #+#    #+#             */
/*   Updated: 2024/10/29 11:34:13 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	print_a(t_stack_node *a)
{
	while (a)
	{
		a = a->next;
	}
}

static void	find_lowest(t_stack_node *a, int *low_node1, int *low_node2)
{
	t_stack_node	*tmp;

	*low_node1 = a->nbr;
	*low_node2 = INT_MAX;
	tmp = a;
	while (tmp)
	{
		if (tmp->nbr < *low_node1)
			*low_node1 = tmp->nbr;
		tmp = tmp->next;
	}
	tmp = a;
	while (tmp)
	{
		if (tmp->nbr < *low_node2 && tmp->nbr > *low_node1)
			*low_node2 = tmp->nbr;
		tmp = tmp->next;
	}
}

static void	sort_five(t_stack_node **a, t_stack_node **b)
{
	int	low_node1;
	int	low_node2;
	
	find_lowest(*a, &low_node1, &low_node2);
	//printf("Lowest nodes found: %d, %d\n", low_node1, low_node2);
	while (stack_len(*a) > 3)
	{
		//printf("Current top of A: %d\n", (*a)->nbr);
		if ((*a)->nbr == low_node1 || (*a)->nbr == low_node2)
		{
			pb(b, a, false);
			//printf("Pushed %d to B\n", (*a)->nbr);
		}
		else
		{
			ra(a, false);
			//printf("Rotated A: %d\n", (*a)->nbr);
		}
	}
	sort_three(a);
	//printf("Stack A sorted with 3 elements.\n");
	if (stack_len(*b) > 1 && stack_sorted(*b))
	{
		sb(b, false);
		//printf("Swapped B to sort\n");
	}
	pa(a, b, false);
	//printf("Moved from B to A: %d\n", (*a)->nbr);
	pa(a, b, false);
	//printf("Moved from B to A: %d\n", (*a)->nbr);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	init_stack_a(&a, &argv[1]);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else if (stack_len(a) == 5)
			sort_five(&a, &b);
		else
			sort_stacks(&a, &b);
	}
	print_a(a);
	print_a(b);
	free_stack(&a);
	return (0);
}
