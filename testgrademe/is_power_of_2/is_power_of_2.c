/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:17:57 by michhern          #+#    #+#             */
/*   Updated: 2024/04/23 15:22:08 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** primera funcion basica
*/

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0) // otra alternativa (!(n % 2))
		n /= 2;
	return ((n == 1) ? 1 : 0); // equivalente a : if (n == 1) return 1; else return (0);
}

/*
** Ahora la versión bitwise :
** aplicamos n - 1 máscara a n, y luego comprobar que es igual a 0
** será cierto para todos los números que sean potencia de 2.
** Por último nos aseguramos de que n es superior a 0.
*/

int		is_power_of_2(unsigned int n)
{
	return (n > 0 && !(n & (n - 1)));
}

/*
** Test program
*/

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("%s is power of 2 ?");
		is_power_of_2(atoi(av[1])) ? printf("Yes\n") : printf("No\n");
	}
	return (0);
}