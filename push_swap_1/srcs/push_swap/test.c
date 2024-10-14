/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:47:43 by michhern          #+#    #+#             */
/*   Updated: 2024/09/17 14:13:44 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	print_a(t_stack_node *a)
{
	while (a)
	{
		printf("a[%d]: %d\n", a->index, a->nbr);
		a = a->next;
	}
}

t_stack_node	*find_min(t_stack_node *stack)
{
	long			min;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

int	fin_mediam(t_stack_node *array, int size)
{
	t_stack_node	*arr;
	t_stack_node	*node_copy;
	t_stack_node	*actual;
	t_stack_node	*head;
	int				median_index;
	int				median;
	int				min;

	actual = NULL;
	while (array != NULL)
	{
		node_copy = malloc(sizeof(t_stack_node));
		node_copy->nbr = array->nbr;
		node_copy->next = NULL;
		if (actual)
			actual->next = node_copy;
		else
			head = node_copy;
		array = array->next;
		actual = node_copy;
	}
	if (size % 2 == 0)
		median_index = (size / 2) - 1;
	else
		median_index = size / 2;
	arr = head;
	while (median_index > 0)
	{
		min = (find_min(arr))->nbr;
	//	min = INT_MAX;
		arr->nbr = INT_MAX;
		arr = arr->next;
		median_index--;
	}
	median = find_min(arr)->nbr;
	while (head != NULL)
    {
        t_stack_node *temp = head;
        head = head->next;
        free(temp);
    }
	return (median);
}

int main(void)
{
	t_stack_node *test;
	t_stack_node *new_node;
	t_stack_node *current = NULL;
	int	i;

	test = malloc(sizeof(t_stack_node) * 5);
	i = 1;
	while (i < 10)
	{
		new_node = malloc(sizeof(t_stack_node));
		new_node->nbr = i;
		new_node->index = i;
		i++;
		new_node->next = NULL;
		new_node->prev = current;
		if (current)
			current->next = new_node;
		else
			test = new_node;
		current = new_node;
	}
	while (current && current->prev)
	{
		current = current->prev;
	}
	printf("median = %i\n", fin_mediam(test, 10));
	while (current != NULL)
    {
        t_stack_node *temp = current;
        current = current->next;
        free(temp);
    }
	free(test);
	return (0);
}