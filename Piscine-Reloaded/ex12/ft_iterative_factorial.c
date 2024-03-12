/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:48:36 by michhern          #+#    #+#             */
/*   Updated: 2024/01/05 14:37:22 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>*/

int	ft_iterative_factorial(int nb)
{
	int	factor;

	factor = 1;
	if (nb < 0 || nb > 12)
		return (0);
	else if (nb == 0 || nb == 1)
		return (1);
	else
	{
		while (nb > 1)
		{
			factor *= nb;
			nb--;
		}
		return (factor);
	}
}

/*int	main(void)
{
	int	numb;
	int	result;

	printf("Ingresa el numero para calcuar su factorial: ");
	scanf("%d", &numb);
	result = ft_iterative_factorial(numb);
	printf("El factorial de %d es %d\n", numb, result);
	return (0);
}*/
