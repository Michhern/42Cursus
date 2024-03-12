/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:10:26 by michhern          #+#    #+#             */
/*   Updated: 2023/11/29 20:15:40 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	arr;
	int	punt;

	punt = 0;
	while (punt < (size - 1))
	{
		if (tab[punt] > tab[punt + 1])
		{
			arr = tab[punt];
			tab[punt] = tab[punt + 1];
			tab[punt + 1] = arr;
			punt = 0;
		}
		else
			punt++;
	}
}

/*int	main(void)
{
	int	tab[9] = {40, 5, 8, 4, 15, 20, 7, 10, 30};
	int	size;
	int	var;

	size = 9;
	var = 0;
	ft_sort_int_tab(tab, size);
	while (var < size)
	{
	printf("%d ", tab[var]);
	var++;
	}
	return (0);
}*/
