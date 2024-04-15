/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:05:42 by michhern          #+#    #+#             */
/*   Updated: 2024/03/20 18:54:08 by michhern         ###   ########.fr       */
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