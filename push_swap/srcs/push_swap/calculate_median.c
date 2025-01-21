/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_median.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:57:25 by michhern          #+#    #+#             */
/*   Updated: 2024/10/21 14:34:20 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	compare(const void *a, const void *b)
{
	int	arg1;
	int	arg2;

	arg1 = *(const int *)a;
	arg2 = *(const int *)b;
	if (arg1 < arg2)
		return (-1);
	if (arg1 > arg2)
		return (1);
	return (0);
}

int	find_median(t_stack_node *array, int size)
{
	t_stack_node	*current;
	int				*values;
	int				median;
	int				i;

	i = 0;
	if (size <= 0)
		return (-1);
	values = malloc(size * sizeof(int));
	if (!values)
		return (-1);
	current = array;
	while (current != NULL && i < size)
	{
		values[i] = current->nbr;
		current = current->next;
		i++;
	}
	qsort(values, size, sizeof(int), compare);
	if (size % 2 == 0)
		median = values[size / 2 - 1];
	else
		median = values[size / 2];
	free(values);
	return (median);
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

int	calculate_median(t_stack_node *array, int size)
{
	t_stack_node	*copied_stack;
	int				median;

	if (size <= 0)
	{
		return (-1);
	}
	copied_stack = copy_stack(array);
	if (!copied_stack)
	{
		return (-1);
	}
	median = find_median(copied_stack, size);
	free_stack(&copied_stack);
	return (median);
}
