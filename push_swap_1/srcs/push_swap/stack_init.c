/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:50:36 by michhern          #+#    #+#             */
/*   Updated: 2024/10/15 12:00:22 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static long	ft_atolong(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r'
		|| *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

static void	add_node(t_stack_node **stack, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->nbr = value;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	init_stack_a(t_stack_node **a, char **av)
{
	long	n;
	int		i;

	i = 0;
	if (!a || !av)
	{
		//--printf("Puntero nulo en init_stack_a\n");
		free_errors(a, "Puntero nulo");
	}
	while (av[i])
	{
		//printf("Procesando argumento: %s\n", av[i]);
		if (syntax(av[i]))
			free_errors(a, "Bad syntax");
		n = ft_atolong(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a, "Overflow");
		if (duplicate(*a, (int)n))
			free_errors(a, "Duplicate arguments");
		add_node(a, (int)n);
		i++;
	}
}

t_stack_node	*get_the_lower(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->lower)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack_node **stack_a, t_stack_node *target_number,
	char stack_name)
{
	while (*stack_a != target_number)
	{
		if (stack_name == 'a')
		{
			if (target_number->above_median)
				ra(stack_a, false);
			else
				rra(stack_a, false);
		}
		else if (stack_name == 'b')
		{
			if (target_number->above_median)
				rb(stack_a, false);
			else
				rrb(stack_a, false);
		}
	}
}
