/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:57:29 by michhern          #+#    #+#             */
/*   Updated: 2024/09/23 15:34:14 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	syntax(char *str)
{
	int	i;

	i = 0;
	//printf("Entro con %s\n", str);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		//printf("str[%d] %c\n", i, str[i]);
		if (!ft_isdigit(str[i]))
		{
			//printf("Error syntax: no numbers\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **a, char *str)
{
	if (a)
	{
		free_stack(a);
	}
	ft_printf("Error: %s\n", str);
	exit(1);
}
