/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:08:54 by michhern          #+#    #+#             */
/*   Updated: 2023/11/28 19:32:02 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a;
	mod = *b;
	*a = div / mod;
	*b = div % mod;
}

/*int	main(void)
{
	int	a;
	int	b;
	int	*var1;
	int	*var2;

	a = 7;
	b = 3;
	var1 = &a;
	var2 = &b;
	ft_ultimate_div_mod(var1, var2);
	printf("result : %d\n", a);
	printf("rest : %d\n", b);
}*/
