/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:58:07 by michhern          #+#    #+#             */
/*   Updated: 2023/11/28 19:32:23 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*int	main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;

	a = 9;
	b = 2;
	ft_div_mod(a, b, &div, &mod);
	printf("dividend : %d\n", a);
	printf("divider : %d\n", b);
	printf("result : %d\n", div);
	printf("rest : %d\n", mod);
	return (0);
}*/
