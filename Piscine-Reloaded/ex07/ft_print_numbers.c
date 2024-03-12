/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:05:17 by michhern          #+#    #+#             */
/*   Updated: 2024/01/05 15:42:52 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char n);

void	ft_print_numbers(void)
{
	int	numb;

	numb = '0';
	while (numb <= '9')
	{
		ft_putchar(numb);
		numb++;
	}
}

/*int	main(void)
{
	ft_print_numbers();
	return (0);
}*/
