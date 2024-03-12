/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:41:03 by michhern          #+#    #+#             */
/*   Updated: 2024/01/05 15:40:57 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char a);

void	ft_print_alphabet(void)
{
	char	alpha;

	alpha = 'a';
	while (alpha <= 'z')
	{
		ft_putchar(alpha);
		alpha++;
	}
}

/*int main(void)
{
	ft_print_alphabet();
	return (0);
}*/
