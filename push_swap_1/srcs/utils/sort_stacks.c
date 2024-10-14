/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:40:29 by michhern          #+#    #+#             */
/*   Updated: 2024/10/14 14:38:42 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*static void	rotate_both(t_stack_node **a, t_stack_node **b,
	t_stack_node *low_node)
{
	if ((*a)->index < low_node->index)// mirar esta condicion por que entra en else
	{
		while (*b != low_node->target_node && *a != low_node)
			rr(a, b, false);
	}
	else
	{
		while (*b != low_node->target_node && *a != low_node) //mirar esta condicion por que entra en else
		{
			rrr(a, b, false);
		}	
	}
	current_index(*a);
	current_index(*b);
}*/

static void	rotate_both(t_stack_node **a, t_stack_node **b,
	t_stack_node *low_node, int dist_a, int dist_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(*a) / 2;
	len_b = stack_len(*b) / 2;

	if (dist_a <= len_a && dist_b <= len_b)
	{
		while(*b != low_node && *a != low_node->target_node)
			rr(a, b, false);
	}
	else if (dist_a > len_a && dist_b > len_b)
	{
		while (*b != low_node && *a != low_node->target_node)
			rrr(a, b, false);
	}
	
}

static void	rotate_one(t_stack_node **a, t_stack_node **b,
	t_stack_node *low_node, int dist_a, int dist_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(*a) / 2;
	len_b = stack_len(*b) / 2;
	while (*a != low_node->target_node)
	{
		if (dist_a <= len_a)
			ra(a, false);
		else
			rra(a, false);
	}
	while (*b != low_node)
	{
		if (dist_b <= len_b)
			rb(b, false);
		else
			rrb(b, false);
	}
}

static int	get_distance_to_top(t_stack_node *stack, t_stack_node *node)
{
	int				distance;
	t_stack_node	*current;

	distance = 0;
	current = stack;
	while (current && current != node)
	{
		current = current->next;
		distance++;
	}
	if (!current)
		return (-1);
	return (distance);
}

static void	apply_optimal_rotations(t_stack_node **a, t_stack_node **b,
	t_stack_node *low_node)//nueva funcion
{
	int	dist_a;
	int	dist_b;
	int	len_a;
	int	len_b;

	dist_a = get_distance_to_top(*a, low_node->target_node);
	dist_b = get_distance_to_top(*b, low_node);
	len_a = stack_len(*a) / 2;
	len_b = stack_len(*b) / 2;

	if ((dist_a <= len_a && dist_b <= len_b) || (dist_a > len_a && dist_b > len_b))
		rotate_both(a, b, low_node, dist_a, dist_b);
	else
		rotate_one(a, b, low_node, dist_a, dist_b);
	current_index(*a);
	current_index(*b);
}


static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	//printf("(*b)->target_node = %i\n", (*b)->target_node->nbr);
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

void print_stack(t_stack_node *stack)// comprobar pila a si eta ordenada 
{
    t_stack_node *current = stack;
    printf("Stack: ");
    while (current)
    {
        printf("%d ", current->nbr);
        current = current->next;
    }
    printf("\n");
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
	median = calculate_median(*a, len_a);
	//printf("Median calculated: %d\n", median);
	while (len_a > 3)
	{
		if ((*a)->nbr <= median)
		{
			printf("Moving %d to stack b\n", (*a)->nbr);
			pb(b, a, false);
		}
		else
		{
			printf("Rotating stack a\n");
			ra(a, false);
		}
		len_a = stack_len(*a);
	}
	sort_three(a);
	printf("Pila A después de sort_three: ");//
    print_stack(*a);//
	while (*b)
	{
		init_nodes_b(*a, *b);
		best_node = push_cost_node(*b, *a, stack_len(*b), len_a);
		if (best_node)
		{
			printf("Pila B después: ");
			print_stack(*b);
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
