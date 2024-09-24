/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:36:38 by michhern          #+#    #+#             */
/*   Updated: 2024/09/24 17:50:48 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	print_a(t_stack_node *a)
{
	while (a)
	{
		//printf("a[%d]: %d\n", a->index, a->nbr);
		a = a->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				median;
	int				len_a;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	init_stack_a(&a, &argv[1]);
	if (!stack_sorted(a))
	{
		len_a = stack_len(a);
		if (len_a == 2)
			sa(&a, false);
		else if (len_a == 3)
			sort_three(&a);
		else
		{
			median = calculate_median(a, len_a);
			sort_stacks(&a, &b, median); //sort_stack(&a, &b, median)
		}
	}
	print_a(a);
	free_stack(&a);
	return (0);
}
