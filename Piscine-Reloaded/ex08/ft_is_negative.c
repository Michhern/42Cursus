/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:03:13 by michhern          #+#    #+#             */
/*   Updated: 2024/01/05 15:56:00 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char i);

void	ft_is_negative(int n)
{
	if (n < 0)
		ft_putchar('N');
	else
		ft_putchar('P');
}

/*int	main(void)
{
	int	num;

	num = 2;
	ft_is_negative(num);
	return (0);
}*/
