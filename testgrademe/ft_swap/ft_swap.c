/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:42:01 by michhern          #+#    #+#             */
/*   Updated: 2024/06/28 12:41:49 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*int	main(int ac, char *av[])
{
	int	num1;
	int	num2;

	if (ac != 3)
	{
		printf("Usage: %s <number1> <number2>\n", av[0]);
		return (-1);
	}
	num1 = atoi(av[1]);
	num2 = atoi(av[2]);
	printf("Antes de SWAP: 	num1 = %d num2 = %d\n", num1, num2);
	ft_swap(&num1, &num2);
	printf("Despues de SWAP: num1 = %d num2 = %d\n", num1, num2);
	return (0);
}*/
