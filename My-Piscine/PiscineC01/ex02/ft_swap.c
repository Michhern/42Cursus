/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:21:46 by michhern          #+#    #+#             */
/*   Updated: 2023/11/27 21:29:31 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	nbr;

	nbr = *a;
	*a = *b;
	*b = nbr;
}

/*#include <stdio.h>
int	main(void)
{
	int	a;
	int	b;
	int	*ptr1;
	int	*ptr2;

	a = 1;
	b = 2;
	ptr1 = &b;
	ptr2 = &a;
	ft_swap (ptr1, ptr2);
	printf("a : %d, b : %d\n", a, b);
}*/
