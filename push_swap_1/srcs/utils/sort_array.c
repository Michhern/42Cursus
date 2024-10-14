/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:32:28 by michhern          #+#    #+#             */
/*   Updated: 2024/09/16 13:58:18 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;

	while (j < high)
	{
		if (arr[j] <= pivot)
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	ft_swap(&arr[i + 1], &arr[high]);
	return (i + 1);	
}
static void	quicksort(int *arr, int low, int high)
{
	int	p;
	while (low < high)
	{
		p = partition(arr, low, high);
		if (p - low < high - p)
		{
			quicksort(arr, low, p - 1);
			low = p + 1;
		}
		else
		{
			quicksort(arr, p + 1, high);
			high = p - 1;
		}
	}
}

void	sort_array(int *arr, int len)
{
	quicksort(arr, 0, len - 1);
}