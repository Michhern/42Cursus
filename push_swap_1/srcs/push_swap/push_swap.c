/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:36:38 by michhern          #+#    #+#             */
/*   Updated: 2024/10/17 15:10:03 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	print_a(t_stack_node *a)
{
	while (a)
	{
		printf("a[%d]: %d\n", a->index, a->nbr);
		a = a->next;
	}
	printf("----------------\n");
}
static void sort_five(t_stack_node **a, t_stack_node **b)
{
	int	low_node1;
	int	low_node2;
	t_stack_node *tmp;
	
	tmp = *a;
	low_node1 = (*a)->nbr;
	low_node2 = (*a)->nbr;
	while (tmp)
	{
		if (tmp->nbr < low_node1)
			low_node1 = tmp->nbr;
		tmp = tmp->next;
	}
	tmp = *a;
	while (tmp)
	{
		if (tmp->nbr < low_node2 && tmp->nbr > low_node1)
			low_node2 = tmp->nbr;
		tmp = tmp->next;
	}
	while (stack_len(*a) > 3)
	{
		if ((*a)->nbr == low_node1 || (*a)->nbr == low_node2)
			pb(b, a, false);
		else
			ra(a, false);
	}
	sort_three(a);
	if (stack_sorted(*b))
		sb(b, false);
	pa(a, b, false);
	pa(a, b, false);
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
	printf("init stack _a\n");
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
		//printf("in if \n");
	}
	print_a(a);
	printf("after print a\n");
	print_a(b);
	free_stack(&a);
	return (0);
}
