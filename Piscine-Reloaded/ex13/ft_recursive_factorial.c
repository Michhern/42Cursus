/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:46:18 by michhern          #+#    #+#             */
/*   Updated: 2024/01/05 14:35:53 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>*/

int	ft_recursive_factorial(int nb)
{
	int	recurs;

	recurs = 1;
	if (nb < 0 || nb > 12)
		return (0);
	else if (nb == 0 || nb == 1)
	{
		return (1);
	}
	return (nb * ft_recursive_factorial(nb - 1));
}

/*int	main(void)
{
	int	numb;
	int	result;

	printf("Ingresa el numero para calcuar su factorial: ");
	scanf("%d", &numb);
	result = ft_recursive_factorial(numb);
	printf("El factorial de %d es %d\n", numb, result);
	return (0);
}*/
