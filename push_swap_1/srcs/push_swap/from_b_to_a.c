/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:24:18 by michhern          #+#    #+#             */
/*   Updated: 2024/10/14 12:12:22 by michhern         ###   ########.fr       */
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

//setear los target 
//poner el numero y su target arriba
//pb
//funcion para conocer la mediana != valor al medio
//mediana: si tenemos todo la stack ordenada, es el valor al medio


/*int	fin_median(t_stack_node *array, int size)
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
	(void)min;
	return (median);
}*/

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

int	find_median(t_stack_node *array, int size)//modificada de la original
{
	t_stack_node	*current;
	int				*values;
	int				median;
	int				i;

	i = 0;
	if (size <= 0)
		return (-1);
	printf("Valores antes de ordenar: ");
	values = malloc(size *sizeof(int));
	if (!values)
		return (-1);
	current = array;
	while (current != NULL && i < size)
	{
		values[i] =  current->nbr;
		current = current->next;
		i++;
	}
	for (int j = 0; j < size; j++) {
	printf("%d ", values[j]);
	}
	printf("\n");
	qsort(values, size, sizeof(int), compare);
	printf("Valores ordenados para caalcular la mediana: ");
	for (int j = 0; j < size; j++) {
	printf("%d ", values[j]);
	}
	printf("\n");
	if (size % 2 == 0)
		median = values[size / 2 - 1]; //+ values[size / 2]) / 2;
	else
		median = values[size / 2];
	free(values);
	return(median);
}

static t_stack_node	*copy_stack(t_stack_node *array)//funion nueva
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

int	calculate_median(t_stack_node *array, int size)////nuneva implementacion
{
	t_stack_node	*copied_stack;
	//t_stack_node	*temp;
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
	free_stack(&copied_stack);
	printf("Mediana calculada: %d\n", median);
	return (median);
}
