/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:48:33 by michhern          #+#    #+#             */
/*   Updated: 2024/07/29 11:57:12 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_putchar(int c);
int		ft_putnbr(int n);
size_t	ft_putnbr_len(int n);
size_t	ft_strlen(const char *str);
int		ft_putstr(char *str);
int		ft_hexalen(unsigned long long hexa, char format);
int		ft_hexadecimal(unsigned long long hexa, int *len, char format);
int		ft_printf(const char *format, ...);
int		ft_nbrunsig(unsigned int n);
size_t	ft_putnbr_len_unsigned(unsigned int n);

#endif