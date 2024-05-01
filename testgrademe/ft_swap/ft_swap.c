/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:25:12 by michhern          #+#    #+#             */
/*   Updated: 2024/04/17 14:43:55 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_swap(int	*a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = tmp;
	*b = *a;
}

/*int	main(void)
{
	int	a = 8;
	int	b = 7;

	ft_swap(&a, &b);
	printf("a :%d\n", a);
	printf("b :%d\n", b);
	return (0);
}*/
