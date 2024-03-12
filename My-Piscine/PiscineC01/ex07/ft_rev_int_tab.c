/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:41:15 by michhern          #+#    #+#             */
/*   Updated: 2023/11/29 19:45:51 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	c;
	int	leng;

	c = 0;
	leng = 0;
	while (c < (size / 2))
	{
		leng = tab[c];
		tab[c] = tab[size -1 - c];
		tab[size -1 - c] = leng;
		c++;
	}
}

/*int	main(void)
{
	int	tab[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int	size;
	int	val;

	size = 9;
	val = 0;
	printf("Not inverse:");
	while (val < size)
	{
		printf("%d", tab[val]);
		val++;
	}
	printf("\n");
	ft_rev_int_tab(tab, size);
	printf("Inverse:");
	val = 0;
	while (val < size)
	{
		printf("%d", tab[val]);
		val++;
	}
	return (0);
}*/
