/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:40:29 by michhern          #+#    #+#             */
/*   Updated: 2024/10/17 15:01:45 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	printf("in pila_a:");
	print_stack(*a);
	printf("\n");
	printf("(*b)->target_node = %i\n", (*b)->target_node->nbr);
	printf("in pila_b:");
	print_stack(*b);
	printf("\n");
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

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

/*void	sort_stacks(t_stack_node **a, t_stack_node **b) 
{
	int	len_a;

	len_a = stack_len(*a);
	while (len_a > 3 && !stack_sorted(*a))
	{
		pb(b, a, false);
		len_a = srrrtack_len(*a);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	mini_on_top(a);
}*/


static void	sort_stack_final(t_stack_node **a)//nueva implementacion
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

void print_stack(t_stack_node *stack)// comprobar pila a si esta ordenada 
{
    t_stack_node *current = stack;
    //printf("Stack: ");
    while (current)
    {
        printf("%d ", current->nbr);
        current = current->next;
    }
    //printf("\n");
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)//nueva implementacion
{
	int	len_a;
	int	median;
	t_stack_node	*best_node;

	if (stack_sorted(*a))
		return ;
	len_a = stack_len(*a);
	if (len_a <= 3)
	{
		sort_three(a);
		return ;
	}
	printf("before median\n");
	median = calculate_median(*a, len_a);
	printf("median = %i\n", median);
	printf("Median calculated: %d\n", median);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		 //***revisar en caso de poner > median***
		printf("Moving %d to stack b\n", (*a)->nbr);
		pb(b, a, false);
		// printf("in while \n");
		// if ((*a)->nbr <= median)
		// {
			// printf("Moving %d to stack b\n", (*a)->nbr);
			// pb(b, a, false);
		// }
		// else
		// {
			// printf("Rotating stack a\n");
			// ra(a, false);
		// }
		//len_a = stack_len(*a);
	}
	sort_three(a);
	printf("Pila A después de sort_three: ");
    print_stack(*a);
	printf("\n");
	while (*b)
	{
		init_nodes_b(*a, *b);
		best_node = push_cost_node(*b, *a, stack_len(*b), len_a);
		if (best_node)
		{
			printf("Pila B después: ");
			print_stack(*b);
			printf("\n");
			printf("Best node found: %d\n", best_node->nbr);
			apply_optimal_rotations(a, b, best_node);
			//pa(a, b, true);
			move_b_to_a(a, b);
		}
	}
	current_index(*a);
	mini_on_top(a);
	if (stack_sorted(*a))
		sort_stack_final(a);
}
