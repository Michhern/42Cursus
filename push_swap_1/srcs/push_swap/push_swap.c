/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:36:38 by michhern          #+#    #+#             */
/*   Updated: 2024/10/16 17:11:39 by michhern         ###   ########.fr       */
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
