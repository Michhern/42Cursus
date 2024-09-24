/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:24:18 by michhern          #+#    #+#             */
/*   Updated: 2024/09/24 17:52:39 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		//target_node = NULL;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_match_index)
			{
				best_match_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LLONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}

static t_stack_node	*copy_stack(t_stack_node *array)
{
	t_stack_node	*node_copy;
	t_stack_node	*actual;
	t_stack_node	*head;

	node_copy = NULL;
	actual = NULL;
	head = NULL;
	while (array)
	{
		node_copy = malloc(sizeof(t_stack_node));
		if (!node_copy)
		{
			free_stack(&head);
			return (NULL);
		}
		node_copy->nbr = array->nbr;
		node_copy->next = NULL;
		if (actual)
			actual->next = node_copy;
		else
			head = node_copy;
		actual = node_copy;
		array = array->next;
	}
	return (head);
}

/*int	find_median(t_stack_node *arr, int size)
{
	int	median_index;
	int	median;

	if (size % 2 == 0)
		median_index = (size / 2) - 1;
	else
		median_index = size / 2;
	while (median_index > 0)
	{
		find_min(arr)->nbr = INT_MAX;
		arr = arr->next;
		median_index--;
	}
	median = find_min(arr)->nbr;
	return (median);
}*/

static int	compare_ints(const void *a, const void *b)
{
	int	int_a;
	int	int_b;

	int_a = *(const int *)a;
	int_b = *(const int *)b;
	return(int_a - int_b);
}

int	find_median(t_stack_node *arr, int size)
{
	int	*values;
	int	i;
	int	median;

	values = malloc(sizeof(int) * size);
	if (!values)
		return (-1);
	i = 0;
	while (arr && i < size)
	{
		values[i++] = arr->nbr;
		arr = arr->next;
	}
	qsort(values, size, sizeof(int), compare_ints);
	if (size % 2 == 0)
		median = values[size / 2 - 1];
	else
		median = values[size / 2];
	free(values);
	return (median);
}

int	calculate_median(t_stack_node *array, int size)
{
	t_stack_node	*copied_stack;
	t_stack_node	*temp;
	int				median;

	if (size <= 0)
	{
		printf("Error: tamaño no válido para calcular la mediana\n");
		return (-1);
	}
	copied_stack = copy_stack(array);
	if (!copied_stack)
	{
		printf("Error: no se pudo copiar la pila\n");
		return (-1);
	}
	median = find_median(copied_stack, size);
	if (median == -1)
	{
		free_stack(&copied_stack);
		return (-1);
	}
	while (copied_stack)
	{
		temp = copied_stack;
		copied_stack = copied_stack->next;
		free(temp);
	}
	return (median);
}
