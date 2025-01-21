/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:31:33 by michhern          #+#    #+#             */
/*   Updated: 2024/07/13 17:03:36 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char *s);
int		ft_atoi(const char *str);
int		ft_isdigit(int a);
void	ft_putchar(char c);
void	ft_putnbr(int num);
int		check_digit(char *str);
int		msg_wrong(char *str);
char	*str2(char *s);
void	write_msg(char *str);

#endif
